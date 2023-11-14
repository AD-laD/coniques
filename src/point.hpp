#pragma once
#include <iostream>
#include <vector>

#include <C:\eigen-3.4.0\Eigen\Dense>

class Point {

    private :
        double m_x,m_y;
        int m_w;
    
    public :
        Point(const double &x=0, const double &y=0, const double &w=1); // default constructor : si on ne spécifie pas les paramètres, elles sont remplacées par les valeurs par defaut
        Point(const Point &p); // copy constructor

        ~Point() = default; //destructor

        Point prod_vect(Point& a, Point& b); // produit vectoriel
        double x(); // getter de x
        double y(); //getter de y
        double w(); //getter de w
        //faire des setters ?

};