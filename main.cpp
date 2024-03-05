#include <iostream>
#include <string>
#include "FunctionTree.h"
#include "Parser.h"
#include "ODESolver.h"
#include "StringUtils.h"
#include <algorithm>
#include <memory>

// Test results with doctest.
// Kinda cool.


int main(int argc, char *argv[]) {

    if (argc == 2 && strcmp(argv[1],"--help") == 0){
        std::cout << std::endl;
        std::cout << " --------------------------------------------------------------------------------------- " << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| This tool lets you calculate the result at an arbitrary point in time for an ODE      |" << std::endl;
        std::cout << "| of arbitrary order. Execute this tool using the following command:                    |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "|       ------------------------------------------------------------------------        |" << std::endl;
        std::cout << "|      | ./ODEsolver -f function -h timestep -tn timepoint -v0 [t0, y0, y'0, ...] |       |" << std::endl;
        std::cout << "|       ------------------------------------------------------------------------        |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| -h: denotes the step size for solving ODE via discrete stepping method.               |" << std::endl;
        std::cout << "|     (should be a floating point number)                                               |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| -tn: denotes the time point for which to solve the differential equation.             |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| -v0: denotes the initial values for all derivatives (except the highest, given by f). |" << std::endl;
        std::cout << "|      (the rectangular braces are not mandatory, the ',' are.)                         |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| -f: denotes the function, that calculates the highest order derivative.               |" << std::endl;
        std::cout << "|     Has to be given in a very specific way:                                           |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "|      (sin > (a*b))                                                                    |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| Every (pairwise) calculation has to be surrounded by round braces.                    |" << std::endl;
        std::cout << "| (Including y = (1*y) and -y = (0-y))                                                  |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| The common math symbols are: + - * / ^                                                |" << std::endl;
        std::cout << "| If you want to use a function (exponential or trigonometric) you need to apply it:    |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "|      (sin > 2)                                                                        |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << "| < and >: are the apply-symbols:                                                       |" << std::endl;
        std::cout << "| whatever is written on the side of the big end is applied to the other side.          |" << std::endl;
        std::cout << "|                                                                                       |" << std::endl;
        std::cout << " --------------------------------------------------------------------------------------- " << std::endl;
        std::cout << std::endl;

        return EXIT_SUCCESS;
    }



    Parser parser;

    parser.add_arg_option("f", true);

    parser.add_arg_option("tn", true);

    parser.add_arg_option("h", true);

    parser.add_arg_option("v0", true);

    parser.add_arg_option("solver", true);


    const int input_arr_size{8};
    char* input_arr[input_arr_size];
    // If the user enters no input, get the arguments from the user during run-time
    if (argc == 1) {

        std::cout << "Due to how cin works you are not allowed to use spaces ' '!" << std::endl;

        std::string input_names[] = {
                "-f",
                "function",
                "-h",
                "timestep",
                "-tn",
                "end time",
                "-v0",
                "initial conditions (e.g. [t0,y0])"
        };

        // Fill in the input array with user input
        for (int i = 0; i < input_arr_size / 2; i++) {
            std::string temp_input_str;

            std::cout << "Enter " << input_names[2*i + 1] << ": ";
            std::cin >> temp_input_str;

            input_arr[2*i] = new char[input_names[2*i].size() + 1];
            std::strcpy(input_arr[2*i], input_names[2*i].c_str());

            input_arr[2*i + 1] = new char[temp_input_str.size() + 1];
            std::strcpy(input_arr[2*i + 1], temp_input_str.c_str());
        }

    }


    try
    {
        if (argc == 1) {
            parser.parse(input_arr_size, input_arr);
        }
        else {
            parser.parse(argc, argv);
        }
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }



    std::string s_init_vecs;
    std::string s_hs;
    std::string s_tns;
    std::string s_fs;
    std::string s_solvers;

    try
    {
        s_init_vecs = parser.get_arg("v0");
        s_hs = parser.get_arg("h");
        s_tns = parser.get_arg("tn");
        // string_view made problems here.
        s_fs = parser.get_arg("f");
        s_solvers = parser.get_arg("solver");
    }
    catch (std::out_of_range &exc)
    {
        std::cout << exc.what() << std::endl;
        return EXIT_FAILURE;
    }


    std::vector<std::string> v_init_vecs = StringUtils::split_string(s_init_vecs, ';', " ");
    std::vector<std::string> v_hs = StringUtils::split_string(s_hs, ';', " ");
    std::vector<std::string> v_tns = StringUtils::split_string(s_tns, ';', " ");
    std::vector<std::string> v_fs = StringUtils::split_string(s_fs, ';', " ");
    std::vector<std::string> v_solvers = StringUtils::split_string(s_solvers, ';', " ");

    // if the number of evaluation points is different than the rest, then solve all solvers for all evaluation points.
    int t_iter = 1;
    int solver_iter;
    if (v_init_vecs.size() == v_hs.size() && v_init_vecs.size() == v_tns.size() && v_init_vecs.size() == v_fs.size() && v_init_vecs.size() == v_solvers.size()){
        solver_iter = v_init_vecs.size();
    }

    // TODO: make this case faster, by using previous solution in the next step.
    else if (v_init_vecs.size() == v_hs.size() && v_init_vecs.size() == v_fs.size() && v_init_vecs.size() == v_solvers.size() && v_init_vecs.size() != v_tns.size()){
        solver_iter = v_init_vecs.size();
        t_iter = v_tns.size();
    }
    else {
        std::cout << "Only the number of evaluation points can differ from the number of different solver parameters (f, init values, step size and solver)!\n";
        return EXIT_FAILURE;
    }


    int t_counter = 0;
    for(int i = 0; i < solver_iter; i++) {

        std::string init_vec = v_init_vecs[i];
        std::string h_s = v_hs[i];
        std::string f = v_fs[i];
        std::string solver_name = v_solvers[i];

        std::string_view chars_to_ignore{"[](){} "};

        std::vector <std::string> init_vals_s = StringUtils::split_string(init_vec, ',', chars_to_ignore);

        std::vector<double> init_vals(init_vals_s.size());

        try {
            std::transform(init_vals_s.begin(), init_vals_s.end(), init_vals.begin(), [](const std::string &s) {
                double num{};
                auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), num);
                if (ec == std::errc()) { return num; }
                else if (ec == std::errc::invalid_argument) {
                    throw std::invalid_argument(s + " is not a number!");
                } else if (ec == std::errc::result_out_of_range) {
                    throw std::invalid_argument(s + "number is too large for double!");
                } else { throw std::invalid_argument("something unexpected happened with " + s); }
            });
        }
        catch (std::invalid_argument &ex) {
            std::cout << ex.what() << std::endl;
            return EXIT_FAILURE;
        }


        FunctionTree* f_tree_p;
        try {
            std::string_view f_v{f};
            f_tree_p = new FunctionTree(f_v);
        } catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
            return EXIT_FAILURE;
        }
        f_tree_p->visualize_tree();


        double h{};
        auto [h_ptr, h_ec] = std::from_chars(h_s.data(), h_s.data() + h_s.size(), h);

        if (h_ec != std::errc() || h_ptr != (h_s.data() + h_s.size())) {
            std::cout << "h argument is not just a number!" << std::endl;
            return EXIT_FAILURE;
        }

        try {

            if (t_iter > 1){
                t_counter = 0;
            }
            for (int j = 0; j < t_iter; j++) {

                // now using previous solution for speed up!
                std::unique_ptr <ODESolvers::ODESolver> solver = ODESolvers::make_ODESolver(f_tree_p, init_vals, h,solver_name);

                auto tn_s = v_tns[t_counter];

                double tn{};
                auto [tn_ptr, tn_ec] = std::from_chars(tn_s.data(), tn_s.data() + tn_s.size(), tn);

                if (tn_ec != std::errc() || tn_ptr != (tn_s.data() + tn_s.size())) {
                    std::cout << "tn argument is not just a number!" << std::endl;
                    return EXIT_FAILURE;
                }

                std::map<std::string, double> sol = (*solver)(tn);
                std::cout << "y(" << sol["t"] << ") = " << sol["y"] << std::endl;
                init_vals = {};
                for( auto it = sol.begin(); it != sol.end(); ++it ) {
                    init_vals.push_back( it->second );
                }

                t_counter += 1;
            }
        }
        catch (std::out_of_range &e) {
            std::cout << e.what() << std::endl;
            return EXIT_FAILURE;
        }

        delete f_tree_p;

    }

    return EXIT_SUCCESS;
}
