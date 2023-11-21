#include <iostream>
#include <vector>

// #include <Eigen/Dense>
#include <C:\eigen-3.4.0\Eigen\Dense>
#include "Geogebra_conics.hpp"
#include "Point.hpp"
#include "draw.hpp"
#include "ConicTypes.hpp"


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

  // draw line
  // viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // draw conic
  // Eigen::VectorXd conic(6);
  // conic << -1.4, -0.3, -1, -0.6, 0.0, 0.8;
  // viewer.push_conic(conic, 0,0,200);  

  //Types de coniques
  set_w_to_conic(viewer,1);
  set_w_to_conic(viewer, 2); //on peut choisir la valeur de la coordonnée homogène des points
  set_w_to_conic(viewer, 3);
  set_w_to_conic(viewer, 4);
  circle_conic(viewer);
  ellipse_conic(viewer);
  parabole_conic(viewer);
  hyperbole_conic(viewer);

  //Fonctions plus complexes
  //draw::conic_from_points(create_random_points(5),viewer,200,0,0);
  //draw::faisceau(viewer, 150, 0, 150);


  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)


  return 0;
}

