#pragma once
#include <iostream>
#include <vector>

#include <C:\eigen-3.4.0\Eigen\Dense>

class Point {

    private :
        double m_x,m_y; //coordonnées x et x du point
        int m_w; //coordonnée homogène
    
    public :
        Point(const double &x=0, const double &y=0, const double &w=1); // default constructor : si on ne spécifie pas les paramètres, elles sont remplacées par les valeurs par defaut
        Point(const Point &p); // copy constructor

        ~Point() = default; //destructor

        Point prod_vect(const Point& b); // produit vectoriel

        //getters
        double x();
        double y();
        double w();
        
        //setters
        void set_x(double& x);
        void set_y(double& y);
        void set_w(double& w);

};