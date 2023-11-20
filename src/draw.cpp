#include "draw.hpp"
// #include "Conic.hpp"
#include "random"
#include "chrono"

//assert : pour des erreurs de code qui pourraient arriver (de notre faute)
//exceptions : pour des erreurs qui pourraient arriver de l'extérieur, à cause d"un souci...


void draw::conic_from_points(std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){

    Conic C1(vector); //création de la conique
    // on transmet ses coeff à la conique de geogebra
    Eigen::VectorXd conic1(6);
    conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // on la push

    try{
        viewer.push_conic(conic1, r, g, b);
    }
    catch (std::runtime_error) {
        // std::cout <<"Erreur lors du dessin de la conique dans le viewer"<<std::endl;
        std::cerr << "erreur lors du dessin de la conique" << std::endl;
    }
}

void draw::classic_conic(Viewer_conic &viewer){
    // on choisi 5 points de contrôle
    //en bleu
    Point p1(5.0,5.0,1.0), p2(-3.0,2.0,1.0), p3(-4.0,-4.0,1.0), p4(1.0,-2.0,1.0), p5(0.0,1.0,1.0);
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    draw::conic_from_points(v1,viewer,0,0,200);
}

void draw::set_w_to_conic(Viewer_conic &viewer, const double w){
    Point p1(5.0,5.0,w), p2(-3.0,2.0,w), p3(-4.0,-4.0,w), p4(1.0,-2.0,w), p5(0.0,1.0,w);
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    draw::conic_from_points(v1,viewer,0,0,200);
}

void draw::random_points(Viewer_conic &viewer, const unsigned int n){ 
    //conique de (n) points random
    //en ROUGE

    // selection de la seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// std::cout << "seed : " << seed << std::endl;

    // selection du générateur random 
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> uniformRealDistribution(-5,5); //distribution de réels entre -5 et 5
    std::vector<Point> v2;
    for(unsigned int i=1; i <n+1 ; i++){
        Point p (uniformRealDistribution(generator), uniformRealDistribution(generator), uniformRealDistribution(generator));
        v2.push_back(p); //ajout de chaque point au vecteur v2
    }
    draw::conic_from_points(v2,viewer,200,0,0);
}

//DRAW TYPES

// void draw_types(Viewer_conic &viewer){
    //créée des coniques à partir des coef
void draw::circle_conic(Viewer_conic &viewer){
    //cercle : a = c et b=0
    Conic cCercle;
    std::vector<double> vCercle = {1.0,0.0,1.0,5.0,3.0,2.0};
    cCercle.set_vector(vCercle);
    Eigen::VectorXd conicCercle(6);
    conicCercle << cCercle.a(), cCercle.b(), cCercle.c(), cCercle.d(), cCercle.e(), cCercle.f();
    // on la push
    assert (cCercle.is_cercle() && "erreur : la conique cercle ne vérifie pas l'équation");

    viewer.push_conic(conicCercle, 0, 200, 0);
}

void draw::ellipse_conic(Viewer_conic &viewer){

    //ellipse
    //b()*b()-4*a()*c()<0
    Conic cEllipse;
    std::vector<double> vEllipse = {1.0, 3.0, 5.0, 5.0, 3.0, 2.0};
    cEllipse.set_vector(vEllipse);
    Eigen::VectorXd conicEllipse(6);
    conicEllipse << cEllipse.a(), cEllipse.b(), cEllipse.c(), cEllipse.d(), cEllipse.e(), cEllipse.f();

    assert (cEllipse.is_ellipse() && "erreur : la conique ellipse ne vérifie pas l'équation");
    viewer.push_conic(conicEllipse, 0, 200, 0);
}

void draw::parabole_conic(Viewer_conic &viewer){

    //parabole
    //b()*b()-4*a()*c()==0
    Conic cParab;
    std::vector<double> vParab = {1.0, 2.0, 1.0, 5.0, 3.0, 2.0};
    cParab.set_vector(vParab);
    Eigen::VectorXd conicParab(6);
    conicParab << cParab.a(), cParab.b(), cParab.c(), cParab.d(), cParab.e(), cParab.f();

    assert (cParab.is_parabole() && "erreur : la conique parabole ne vérifie pas l'équation");
    viewer.push_conic(conicParab, 0, 200, 0);
}

void draw::hyperbole_conic(Viewer_conic &viewer){

    //hyperbole
    //b()*b()-4*a()*c()>0
    Conic cHyper;
    std::vector<double> vHyper = {2.0, 3.0, 1.0, 5.0, 3.0, 2.0};
    cHyper.set_vector(vHyper);
    Eigen::VectorXd conicHyper(6);
    conicHyper << cHyper.a(), cHyper.b(), cHyper.c(), cHyper.d(), cHyper.e(), cHyper.f();

    assert (cHyper.is_hyperbole() && "erreur : la conique hyperbole ne vérifie pas l'équation");

    viewer.push_conic(conicHyper, 0, 200, 0);

}

void draw::faisceau(Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){

    // faisceau basique
    // on contruit nos 2 coniques de base
    std::vector<double> va{1.0, 3.0, 5.0, 5.0, 3.0, 2.0};
    std::vector<double> vb{1.0, -3.0, 3.0, 5.0, -2.0, 1.0};
    Conic Ca(va);
    Conic Cb(vb);
    // on construit le faisceau
    Faisceau F(Ca, Cb);

    // on boucle sur ses coniques
    for(int i=0;i<F.get_num_conic();i++){
        // on transmet ses coeff à la conique de geogebra
        Eigen::VectorXd conic1(6);
        conic1 << F.get_Ci()[i].a(), F.get_Ci()[i].b(), F.get_Ci()[i].c(), F.get_Ci()[i].d(), F.get_Ci()[i].e(), F.get_Ci()[i].f();
        // on la push
        try{
            viewer.push_conic(conic1, r, g, b);
        }
        catch (std::runtime_error) {
            // std::cout <<"Erreur lors du dessin de la conique dans le viewer"<<std::endl;
            std::cerr << "erreur lors du dessin de la conique" << std::endl;
        }
    }

}


void draw::conic_from_tangents(std::vector<Droite> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){

    Conic C1(vector); //création de la conique
    // on transmet ses coeff à la conique de geogebra
    Eigen::VectorXd conic1(6);
    conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // on la push

    try{
        viewer.push_conic(conic1, r, g, b);
    }
    catch (std::runtime_error) {
        // std::cout <<"Erreur lors du dessin de la conique dans le viewer"<<std::endl;
        std::cerr << "erreur lors du dessin de la conique" << std::endl;
    }
}

void draw::conic_tangents(Viewer_conic &viewer){
    // on créé une conique à partir de 5 tangentes
    // on affiche la conique
    Droite d1(1,2,3),d2(-1,-1,5),d3(0,2.5,3),d4(-4,-5,0),d5(2,3,4);
    std::vector<Droite> vect{d1,d3,d3,d4,d5};
    draw::conic_from_tangents(vect, viewer, 0,200,200);

    // on affiche les tangentes : pour ça on doit trouver un point sur chaque droite, et son vecteur directeur
    // Point de chaque droite : on calcul l'intersection entre notre droite et une droite exemple
    /*Droite d_ex1(1,1,1);
    Droite d_ex2(0,1,0); // deux droites non parallèles
    std::vector<Point> points_in_tangents;
    std::vector<Point> directions; 
    int i=0;
    for(auto& d : vect){
        Point q;
        if(d_ex1.intersection(d).w()==0){
            // si l'intersection est à l'infini, on utilise la deuxième droite exemple
            q = d_ex2.intersection(d);
            points_in_tangents.push_back(q);
        }
        else{
            q = d_ex1.intersection(d);
            points_in_tangents.push_back(q);
        }
        // on calcul les paramètres du vecteur directeur
        directions.push_back({d.a()-q.x(),d.b()-q.y()});
        i++;
    }*/
    // on prend les points appartenant à chaque tangentes
    Eigen::VectorXd v1,v2,v3,v4,v5;
    //v1[0]= points_in_tangents[0].x();
    //v1 << points_in_tangents[0].y();
    /*v2 << points_in_tangents[1].x(), points_in_tangents[1].y();
    v3 << points_in_tangents[2].x(), points_in_tangents[2].y();
    v4 << points_in_tangents[3].x(), points_in_tangents[3].y();
    v5 << points_in_tangents[4].x(), points_in_tangents[4].y();*/
    // et leur direction
    /*Eigen::VectorXd dir1,dir2,dir3,dir4,dir5;
    dir1 << directions[0].x(), directions[0].y();
    dir2 << directions[1].x(), directions[1].y();
    dir3 << directions[2].x(), directions[2].y();
    dir4 << directions[3].x(), directions[3].y();
    dir5 << directions[4].x(), directions[4].y();*/
    //Eigen::VectorXd dir1(3),dir2(5),dir3(3),dir4(0),dir5(4);
    // on push la droite
    /*viewer.push_line(v1,dir1,0,0,250);
    viewer.push_line(v2,dir2,0,0,250);
    viewer.push_line(v3,dir3,0,0,250);
    viewer.push_line(v4,dir4,0,0,250);
    viewer.push_line(v5,dir5,0,0,250);*/
}