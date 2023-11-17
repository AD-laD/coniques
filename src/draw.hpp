#pragma once
#include <iostream>
#include <vector>
#include "Geogebra_conics.hpp"
#include "Conic.hpp"
#include "point.hpp"

void draw_conic(std::vector<Point> vector, unsigned int n, Viewer_conic &viewer);
void draw_1(Viewer_conic &viewer);
void draw_random(Viewer_conic viewer);