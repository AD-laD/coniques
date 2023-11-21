#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"
#include "Droite.hpp"

#include <C:\eigen-3.4.0\Eigen\Dense>

//template <typename T> // T peut etre Point ou Droite
class Conic {
    private :
        double m_a, m_b, m_c, m_d, m_e, m_f; //6 coefficients de la conique
        std::vector<double> m_coeff; //vecteur de coefficients

    public : 
        Conic(); // default constructor
        ~Conic() = default;
        //setters
        void set_value(unsigned int i, double& value);
        void set_vector(std::vector<double> &vect);
        void set_vector(Eigen::VectorXd &vect);

        //getters
        double a(), b(), c(), d(), e(), f();
        std::vector<double> get_coeff();
        double get_coeff_from_i(const unsigned int i);

        Conic(std::vector<Point> point_vector); //5 points constructor
        Conic(std::vector<double> vector);
        Conic(std::vector<Droite> droite_vector);
        //Conic(Conic C0); //copy constructor

        //booléens types de conique
        bool is_cercle();
        bool is_ellipse();
        bool is_parabole();
        bool is_hyperbole();

        //opérateurs
        Conic operator/(const double a);
        Conic operator*(const double a);
        Conic operator+(Conic &C);
};