#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "point.hpp"
#include "Droite.hpp"

#include <C:\eigen-3.4.0\Eigen\Dense>

//template <typename T> // T peut etre Point ou Droite
class Conic {
    private :
        double m_a, m_b,m_c,m_d,m_e,m_f;
        std::vector<double> m_coeff;

    public : 
        Conic(std::vector<Point> point_vector); //5 points constructor
        Conic(std::vector<Droite> droite_vector);
        Conic(std::vector<double> vector);
        //Conic(Conic C0); //copy constructor
        Conic(); // default constructor
        ~Conic() = default;

        //setter
        void set_value(unsigned int i, double& value);
        void set_vector(std::vector<double> &vect);
        void set_vector(Eigen::VectorXd &vect);

        //getter
        double a(), b(), c(), d(), e(), f();
        std::vector<double> get_coeff();

        //conic type
        bool is_cercle();
        bool is_ellipse();
        bool is_parabole();
        bool is_hyperbole();

        //operator
        Conic operator/(const double a);
        Conic operator*(const double a);
        Conic operator+(Conic C);
};