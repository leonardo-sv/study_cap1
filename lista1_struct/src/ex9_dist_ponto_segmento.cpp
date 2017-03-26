/*
Leonardo de Souza Vieira
26/03/2017
*/

#include "struct_space2D.hpp"

using namespace std;

void texto_entrada(point&, point&, point&);

int main(int argc, char const *argv[]) {
   point pt1, pt2, pt3;
   double distance = 0;

   texto_entrada(pt1, pt2, pt3);
   line_segment l {pt1, pt2};

   distance = distance_point_segment_line(l, pt3);
   cout << "A distancia entre o ponto3 e o segmento de reta formado por ponto1 e ponto 2 é: " << distance << endl;

   distance = distance_point_line(l.pt1, l.pt2, pt3);
   cout << "A distancia entre o ponto3 e a reta formada por ponto1 e ponto 2 é: " << distance << endl;

   return 0;
}

void texto_entrada(point& pt1, point& pt2, point& pt3){

   cout << "Digite as coordenadas dos 2 pontos pertencentes a reta:" << endl;
   cout << "Ponto 1 coordenada X:" << endl;
   cin  >> pt1.x;
   cout << "Ponto 1 coordenada Y:" << endl;
   cin  >> pt1.y;
   cout << "Ponto 2 coordenada X:" << endl;
   cin  >> pt2.x;
   cout << "Ponto 2 coordenada Y:" << endl;
   cin  >> pt2.y;
   cout << "Digite as coordenadas do ponto que deseja saber a distancia:" << endl;
   cout << "Ponto 3 coordenada X:" << endl;
   cin  >> pt3.x;
   cout << "Ponto 3 coordenada Y:" << endl;
   cin  >> pt3.y;
}
