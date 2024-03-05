//
// Created by lucas on 09.11.23.
//

#ifndef ODESOLVER_PARSER_H
#define ODESOLVER_PARSER_H

#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <string_view>
#include <stdexcept>
#include <limits>
#include <algorithm>


class Option {

private:

    std::string _name;

    bool _present;


public:

    explicit Option(std::string name): _name(std::move(name)), _present(false){};


    void set_to_present(){_present = true;}

    std::string get_name(){return _name;}

    bool is_present(){return _present;}

};


class ArgOption : public Option {

private:

    std::string _arg;

    bool _must;


public:

    ArgOption(std::string name, bool must): Option(std::move(name)), _must(must){};

    void set_arg(const std::string &argument)
    {
        _arg = argument;
    }

    std::string get_arg(){return _arg;}

    bool is_must(){return _must;}

};


class Parser {

private:

    std::vector<Option*> _flags;

    std::vector<ArgOption*> _arg_options;


public:

    // Constructors and Destructors:

    Parser(){};

    ~Parser();

    // TODO: add copy and move constructor as well as copy and move assignment.


    //adders:

    void add_flag(const std::string &name);

    void add_arg_option(const std::string &name, bool must_be_present);


    // getters:

    bool has_flag(const std::string &name);

    std::string get_arg(const std::string &name);


    //methods:

    void parse(const int &argc, char ** argv);

};


#endif //ODESOLVER_PARSER_H
