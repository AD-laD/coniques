#pragma once
#include "Geogebra_conics.hpp"
#include "Faisceau.hpp"

namespace draw{
    //toutes les fonctions qui vont push des conics au viewer sont dans draw
    void conic_from_points(const std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b);
    void conic_from_coeff(const std::vector<double> vector, const std::string type, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b);
    void faisceau(Viewer_conic &viewer,const unsigned int r, const unsigned int g, const unsigned int b);
}

std::vector<Point> create_random_points(const unsigned int n);//permet de générer n points random

