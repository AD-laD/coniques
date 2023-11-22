#pragma once
#include <iostream>
#include <vector>

#include <C:\eigen-3.4.0\Eigen\Dense>
// #include <Eigen/Dense>//pour MACOS

class Point {

    private :
        double m_x,m_y; //coordonnées x et x du point
        int m_w; //coordonnée homogène
    
    public :
        Point(const double &x=0, const double &y=0, const double &w=1); // default constructor : si on ne spécifie pas les paramètres, elles sont remplacées par les valeurs par defaut
        Point(const Point &p); // copy constructor

        ~Point() = default; //destructor

        //getters : on récupère les valeurs de x, y, w
        double x() const;
        double y() const;
        double w() const;
        
        //setters : on peut modifier les valeurs de x, y, w
        void set_x(const double& x);
        void set_y(const double& y);
        void set_w(const double& w);
};