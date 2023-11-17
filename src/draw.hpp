#pragma once
#include <iostream>
#include <vector>
#include "Geogebra_conics.hpp"
#include "Conic.hpp"
#include "point.hpp"

void draw_conic(std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b);
void draw_1(Viewer_conic &viewer);
void draw_random(Viewer_conic &viewer, const unsigned int n);
void draw_types(Viewer_conic &viewer);