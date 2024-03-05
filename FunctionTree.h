//
// Created by lucas on 02.11.23.
//

#ifndef ODESOLVER_FUNCTIONTREE_H
#define ODESOLVER_FUNCTIONTREE_H

// Binary Tree in C++

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cassert>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string_view>
#include <system_error>
#include <functional>


// node: predecessor refers only to the parent.
struct node {
    std::string symbol;
    struct node *predecessor;
    struct node *left;
    struct node *right;

    explicit node(const std::string &symbol);

};


// binary tree, that stores a string, such that it can be executed as a function.
class FunctionTree {

private:

    int height;

    struct node *root = nullptr;

public:

    static inline std::map<std::string, std::function<double(double)>> const trigonometric_functions
    {{"cos", cos}, {"sin", sin}, {"tan", tan}, {"atan", atan}, {"asin", asin}, {"acos", acos},
     {"e", exp}, {"ln", log}};

    // Constructors.
    // Either from existing tree.
    FunctionTree(struct node * root, int& height);

    // or from a string.
    explicit FunctionTree(std::string_view&);

    // Destructor.
    ~FunctionTree();


    // Methods.
    void visualize_tree();

    double solve(std::map<std::string, double>&);

    double solve(std::map<std::string, double>&, struct node *);


    // Getters ans Setters.
    struct node * get_root(){return this->root;}

    int get_height(){return this->height;}

};


#endif //ODESOLVER_FUNCTIONTREE_H
