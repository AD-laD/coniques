#pragma once
#include <iostream>
#include <vector>
#include "point.hpp"

#include <C:\eigen-3.4.0\Eigen\Dense>

template <typename T> // on utilisera surtout des Point
class Conic {
    private :
        double m_a, m_b,m_c,m_d,m_e,m_f;
        std::vector<double> m_coeff[6];

    public : 
        Conic(std::vector<T> point_vector); //5 points constructor
        Conic(Conic C0); //copy constructor
        ~Conic() = default;

        //setter
        void set_value(int i, double& value);
        void set_vector(std::vector<double> vect[6]);
        void set_vector(Eigen::VectorXd vect);

        //getter
        T a(), b(), c(), d(), e(), f();

        //conic type
        bool is_cercle();
        bool is_ellipse();
        bool is_parabole();
        bool is_hyperbole();
};