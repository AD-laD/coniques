#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Point.hpp"

#include <C:\eigen-3.4.0\Eigen\Dense>

// #include <Eigen/Dense> //pour MACOS

class Conic {
    private :
        double m_a, m_b, m_c, m_d, m_e, m_f; //6 coefficients de la conique
        std::vector<double> m_coeff; //vecteur de coefficients

    public : 
        Conic(); // default constructor
        ~Conic() = default; //desteucteur
        //setters
        void set_vector(const std::vector<double> &vect);

        //getters : retournent les valeurs de chaque coeff
        double a() const, b() const, c() const, d() const, e() const, f() const;
        std::vector<double> get_coeff() const; //retourne le vecteur de coeff
        double get_coeff_from_i(const unsigned int i) const; //retourne la ieme valeur du vecteur de coeff

        Conic(const std::vector<Point> point_vector); //5 points constructor
        Conic(const std::vector<double> vector); //coefficient constructor

        //booléens types de conique
        bool is_cercle();
        bool is_ellipse();
        bool is_parabole();
        bool is_hyperbole();

        //opérateurs
        Conic operator/(const double a) const;
        Conic operator*(const double a) const;
        Conic operator+(const Conic &C) const;
};