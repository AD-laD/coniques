#pragma once
#include <iostream>
#include <vector>
#include "Geogebra_conics.hpp"
#include "Conic.hpp"
#include "point.hpp"

namespace draw{
    void conic_from_points(std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b);
    void classic_conic(Viewer_conic &viewer);
    void set_w_to_conic(Viewer_conic &viewer, const double w);
    void random_points(Viewer_conic &viewer, const unsigned int n);
    void circle_conic(Viewer_conic &viewer);
    void ellipse_conic(Viewer_conic &viewer);
    void parabole_conic(Viewer_conic &viewer);
    void hyperbole_conic(Viewer_conic &viewer);
}

