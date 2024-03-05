//
// Created by lucas on 14.11.23.
//

#ifndef ODESOLVER_ODESOLVER_H
#define ODESOLVER_ODESOLVER_H

#include "FunctionTree.h"
#include <cmath>
#include <memory>

namespace ODESolvers {

    // Decision: Function object best approach.
    class ODESolver {

    protected:

        FunctionTree* _f;

        std::vector<double> _init_values;

        double _h;

    public:

        ODESolver(FunctionTree *&f, const std::vector<double> &init_values, double h) : _f{
                std::move(f)}, _init_values{init_values}, _h{h} {}

        virtual std::map<std::string, double> operator()(double t) = 0;

    };


    class Explicit_Euler : public ODESolver {

    public:

        Explicit_Euler(FunctionTree *&f, const std::vector<double> &init_values, double h) : ODESolver(
                f, init_values, h) {}

        std::map<std::string, double> operator()(double t) override;

    };


    class Implicit_Euler : public ODESolver {

    public:

        Implicit_Euler(FunctionTree *&f, const std::vector<double> &init_values, double h) : ODESolver(
                f, init_values, h) {}

        std::map<std::string, double> operator()(double t) override;

    };

    // This only makes sense as long as the constructors of the subclasses have the same input.
    // Nice thing is, you dont need to interact with the subclasses anymore.
    std::unique_ptr<ODESolver> make_ODESolver(FunctionTree *&f, const std::vector<double> &init_values, double h, const std::string &solver);
}



#endif //ODESOLVER_ODESOLVER_H
