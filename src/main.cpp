#include <iostream>
#include <vector>

// #include <Eigen/Dense>
#include <C:\eigen-3.4.0\Eigen\Dense>
#include "Geogebra_conics.hpp"
#include "point.hpp"
#include "draw.hpp"


int main()
{
  // the viewer will open a file whose path is writen in hard (bad!!). 
  // So you should either launch your program from the fine directory or change the path to this file.
  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  // draw points
  /*Eigen::VectorXd pt1(2), pt2(2), pt3(2);
  pt1 <<  1.5,  2.0;
  pt2 <<  3.0,  1.0;
  pt3 << -5.0, -1.0;

  viewer.push_point(pt1, "p1", 200,0,0);
  viewer.push_point(pt2, "p2", 200,0,0);
  viewer.push_point(pt3, 200,0,0);*/

  //tests class point
  // Point a(1,1,1);
  // Point b(2,2,1);
  // std::cout << a.x() << std::endl;
  // std::cout << b.y() << std::endl;
  // Point result = a.prod_vect(b);
  // std::cout<< result.x() << std::endl;
  // std::cout<< result.y() << std::endl;
  // std::cout<< result.w() << std::endl;

  // draw line
  // viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // draw conic
  // Eigen::VectorXd conic(6);
  // conic << -1.4, -0.3, -1, -0.6, 0.0, 0.8;
  // viewer.push_conic(conic, 0,0,200);

  // draw
  draw::classic_conic(viewer);
  draw::set_w_to_conic(viewer, 2); //on peut choisir la valeur de la coordonnée homogène des points
  draw::set_w_to_conic(viewer, 3);
  draw::set_w_to_conic(viewer, 4);
  // draw::random_points(viewer, 10);
  // draw::circle_conic(viewer);
  // draw::ellipse_conic(viewer);
  // draw::parabole_conic(viewer);
  // draw::hyperbole_conic(viewer);

  // A TEST
  draw::faisceau(viewer, 150, 0, 150);
  // A patch
  draw::conic_tangents(viewer);
  

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)


  return 0;
}

