#include <iostream>
#include <vector>

// #include <Eigen/Dense>
// #include <C:\eigen-3.4.0\Eigen\Dense>
#include "Geogebra_conics.hpp"
// #include "Point.hpp"
// #include "draw.hpp"
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

  //Types de coniques

  set_w_to_conic(viewer, 1); //prend en attribut la viewer et la valeur de la coordonnée homgène des points de la conique
  set_w_to_conic(viewer, 2);
  set_w_to_conic(viewer, 3);
  set_w_to_conic(viewer, 4);

  // circle_conic(viewer); //créée et affiche une conique circulaire
  // ellipse_conic(viewer); //créée et affiche une conique elliptique
  // parabole_conic(viewer); //créée et affiche une conique parabolique
  // hyperbole_conic(viewer); //crée et affiche une conique hyperbolique

  // //Fonctions plus complexes
  // int nb_points =5;
  // draw::conic_from_points(create_random_points(nb_points),viewer,200,0,0); //créée et affiche une conique issue de n points à coordonnées random
  // draw::faisceau(viewer, 150, 0, 150); //créée et dessine un faisceau de coniques


  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)


  return 0;
}

