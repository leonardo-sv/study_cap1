/*
Leonardo de Souza Vieira
26/03/2017
*/

#include "space2D.hpp"
#include <iostream>

using namespace std;

void texto_entrada(double&, double&, double&, double&, double&, double&);

int main(int argc, char const *argv[]) {
   double pt1x, pt1y, pt2x, pt2y, pt3x, pt3y;
   texto_entrada(pt1x, pt1y, pt2x, pt2y, pt3x, pt3y);

   double distance = 0;
   Point pt1(pt1x, pt1y);
   Point pt2(pt2x, pt2y);
   Point pt3(pt3x, pt3y);

   Line_Segment l(pt1, pt2);

   distance = l.distance_point(pt3);
   cout << "A distancia entre o ponto3 e o segmento de reta formado por ponto1 e ponto 2 é: " << distance << endl;

   return 0;
}

void texto_entrada(double& pt1x, double& pt1y, double& pt2x, double& pt2y, double& pt3x, double& pt3y){

   cout << "Digite as coordenadas dos 2 pontos pertencentes a reta:" << endl;
   cout << "Ponto 1 coordenada X:" << endl;
   cin  >> pt1x;
   cout << "Ponto 1 coordenada Y:" << endl;
   cin  >> pt1y;
   cout << "Ponto 2 coordenada X:" << endl;
   cin  >> pt2x;
   cout << "Ponto 2 coordenada Y:" << endl;
   cin  >> pt2y;
   cout << "Digite as coordenadas do ponto que deseja saber a distancia:" << endl;
   cout << "Ponto 3 coordenada X:" << endl;
   cin  >> pt3x;
   cout << "Ponto 3 coordenada Y:" << endl;
   cin  >> pt3y;
}
