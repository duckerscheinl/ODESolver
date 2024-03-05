//
// Created by lucas on 09.11.23.
//

#include "Parser.h"

// adders

void Parser::add_flag(const std::string &name) {

    auto *flag = new Option(name);

    _flags.push_back(flag);

}

void Parser::add_arg_option(const std::string &name, const bool must_be_present) {

    auto *flag = new ArgOption(name, must_be_present);

    _arg_options.push_back(flag);

}


// methods
// I think this one is super ugly, but I cant figure out, how to write it better looking without loosing function.
void Parser::parse(const int &argc, char ** argv) {

    bool found;

    for (int i = 0; i < argc; i++)
    {

        if (argv[i][0] == '-'){
            found = false;
            std::string_view name = argv[i];
            name.remove_prefix(1);
            for (auto& flag : _flags)
            {
                if (name.compare(flag->get_name()) == 0)
                {
                    found = true;
                }
            }

            for (auto& flag : _arg_options)
            {
                if (name.compare(flag->get_name()) == 0)
                {
                    found = true;
                }
            }


            if (!found)
            {
                throw std::invalid_argument("-" + std::string(name) + " is not a known flag!");
            }

        }

    }

    for (auto &flag : _flags)
    {

        std::string searching = "-";
        searching += flag->get_name();

        for (int i = 0; i < argc; i++) {
            if (argv[i] == searching) {
                if ( i < argc - 1 && argv[i + 1][0] != '-') {
                    throw std::invalid_argument("Bool flag " + searching + " has arg!");
                } else {
                    flag->set_to_present();
                }
            }
        }

    }

    for (auto &flag : _arg_options)
    {

        found = false;

        std::string searching = "-";
        searching += flag->get_name();

        for (int i = 0; i < argc; i++) {
            if (argv[i] == searching) {
                if ( i == argc - 1 || argv[i + 1][0] == '-')
                {
                    throw std::invalid_argument("Arg flag " + searching + " has no argument!");
                }
                // order important.
                else if ( i < argc - 2 && argv[i + 2][0] != '-')
                {
                    throw std::invalid_argument("Arg flag " + searching + " has two arguments or more, this is currently not possible!");
                }
                else
                {
                    flag->set_to_present();
                    flag->set_arg(argv[i+1]);
                    found = true;
                }
            }
        }

        if (flag->is_must() && !found)
        {
            throw std::invalid_argument("The required flag " + searching + " was not found!");
        }
    }
}


Parser::~Parser() {

    for (auto & flag : _flags)
    {
        delete flag;
    }

    for (auto &flag : _arg_options)
    {
        delete flag;
    }

}

bool Parser::has_flag(const std::string &name) {

    for (const auto & flag : _flags)
    {
        if (flag->get_name() == name)
        {
            return flag->is_present();
        }
    }

    return false;
}


std::string Parser::get_arg(const std::string &name) {

    auto it = std::find_if(_arg_options.begin(), _arg_options.end(),
                           [name](ArgOption * o){return o->get_name() == name;});

    if (it != std::end(_arg_options))
    {
        return (*it)->get_arg();
    }
    else
    {
        throw std::out_of_range(name+" is not an option!");
    }
}
