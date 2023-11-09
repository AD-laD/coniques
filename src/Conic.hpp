#pragma once
#include <iostream>

#include <C:\eigen-3.4.0\Eigen\Dense>


class Conic {
    private:
    double m_a;
    double m_b;
    double m_c;
    double m_d;
    double m_e;
    double m_f;
};

//5 variables (const double) A B C D E F
//pour vérifier la formule ax^2 +bxy +cy^2+dx+ey+f = 0

// des fonctions pour chaque type de coniques ?
//cercle a = c et b =0
//ellipse b^2 - 4ac <0
//parabole b^2-4ac = 0
//hyperbole b^2-4ac > 0


//definition des 5 pts de controles


