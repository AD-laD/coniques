#pragma once
#include "Geogebra_conics.hpp"
#include "Faisceau.hpp"

namespace draw{
    //toutes les fonctions qui vont push des conics au viewer sont dans draw
    void conic_from_points(std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b);
    void conic_from_coeff(std::vector<double> vector, const std::string type, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b);
    void faisceau(Viewer_conic &viewer,const unsigned int r, const unsigned int g, const unsigned int b);
    void conic_from_tangents(std::vector<Droite> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b);
    void conic_tangents(Viewer_conic &viewer);
}

std::vector<Point> create_random_points(const unsigned int n);
std::vector<double> create_random_coeff();

