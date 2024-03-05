//
// Created by lucas on 14.11.23.
//

#include "ODESolver.h"


std::map<std::string, double> create_var_map(const std::vector<double>& values){

    // predefined order: t0, y0, y'0, y''0, ...

    std::map<std::string, double> map;

    map["t"] = values[0];

    std::string order;

    for (unsigned int i = 1; i < values.size(); i++)
    {
        order = std::string(i - 1, '\'');
        map["y"+order] = values[i];
    }

    return map;
}


std::map<std::string, double> ODESolvers::Explicit_Euler::operator()(double t) {

    std::map<std::string, double> v0 = create_var_map(_init_values);

    unsigned int order = v0.size() - 1;

    std::map<std::string, double> v = v0;

    while (t > v.at("t"))
    {
        double step = std::min(_h, t - v.at("t"));

        std::map<std::string, double> tmp;

        std::string current = "y" +  std::string(order-1, '\'');
        try {
            tmp[current] = v[current] + step * _f->solve(v);
        }
        catch (std::out_of_range &e)
        {
            throw;
        }

        for (unsigned int i = order - 1; i > 0; i--){

            current = "y" + std::string(i-1, '\'');
            tmp[current] = v[current] + step * v[current+"\'"];

        }

        tmp["t"] = v["t"] + step;

        v = tmp;
    }

    return v;

}

std::map<std::string, double> ODESolvers::Implicit_Euler::operator()(double t) {

    std::map<std::string, double> v0 = create_var_map(_init_values);

    double conv_limit = std::max(_h*_h,1e-14);
    conv_limit = std::min(conv_limit, 1e-6);

    // int not big enough.
    double counter = 0.0;

    unsigned int order = v0.size() - 1;

    std::map<std::string, double> v = v0;

    while (t > v.at("t"))
    {
        double step = std::min(_h, t - v.at("t"));

        std::map<std::string, double> tmp = v;
        double temp;

        std::string current = "y" +  std::string(order-1, '\'');
        try {
            // the max number of iterations should be related to the strictness of the convergence limit, this is the
            // most obvious implementation of such an relationship.
            while (counter < 1/conv_limit) {
                temp = v[current] + step * _f->solve(tmp);
                if (std::abs(tmp[current] - temp) < conv_limit){
                    tmp[current] = temp;
                    break;
                }
                tmp[current] = temp;
                counter += 1.0;
            }

            if (counter >= 1/conv_limit){
                std::cout << "WARNING: the solution did not converge!" << std::endl;
                std::cout << "The remaining error is: " << std::abs(tmp[current]-v[current]) << std::endl;
            }

        }
        catch (std::out_of_range &e)
        {
            throw;
        }

        for (unsigned int i = order - 1; i > 0; i--){

            current = "y" + std::string(i-1, '\'');
            counter = 0.0;

            // this only works for non-stiff functions (or at least not stiff where you want to calculate).
            // Alternatively: One could use Newtons Method (Downside: you need to calculate a derivative).
            while (counter < 1/conv_limit) {
                temp = v[current] + step * tmp[current + "\'"];
                if (std::abs(tmp[current] - temp) < conv_limit){
                    tmp[current] = temp;
                    break;
                }
                tmp[current] = temp;
                counter += 1.0;
            }

            if (counter >= 1/conv_limit){
                std::cout << "WARNING: the solution did not converge!" << std::endl;
                std::cout << "The remaining error is: " << std::abs(tmp[current]-v[current]) << std::endl;
            }

        }

        tmp["t"] = v["t"] + step;

        v = tmp;
    }

    return v;

}


std::unique_ptr<ODESolvers::ODESolver> ODESolvers::make_ODESolver(FunctionTree *&f, const std::vector<double> &init_values, double h, const std::string &solver) {
    if (solver == "EE" || solver == "Explicit-Euler") {
        return std::make_unique<Explicit_Euler>(f, init_values, h);
    } else if (solver == "IE" || solver == "Implicit-Euler") {
        return std::make_unique<Implicit_Euler>(f, init_values, h);
    } else {
        throw std::invalid_argument(
                "You entered the wrong solver, th options are: Explicit-Euler(EE or Explicit-Euler) and Implicit-Euler (IE or Implicit-Euler)!");
    }
}

