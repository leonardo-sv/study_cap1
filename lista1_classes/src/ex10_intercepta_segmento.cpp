/*
Leonardo de Souza Vieira
27/03/2017
*/

#include "space2D.hpp"
#include <iostream>
#include <string>

using namespace std;

void texto_entrada(double&, double&, double&, double&, double&, double&, double&, double&);


int main(int argc, char const *argv[]) {
   double distance = 0;
   string retorno;
   bool teste;
   double l1_pt1_x, l1_pt2_x, l2_pt1_x, l2_pt2_x;
   double l1_pt1_y, l1_pt2_y, l2_pt1_y, l2_pt2_y;

   texto_entrada(l1_pt1_x, l1_pt2_x, l2_pt1_x, l2_pt2_x, l1_pt1_y, l1_pt2_y, l2_pt1_y,l2_pt2_y);

   Point l1_pt1(l1_pt1_x, l1_pt1_y);
   Point l1_pt2(l1_pt2_x, l1_pt2_y);
   Point l2_pt1(l2_pt1_x, l2_pt1_y);
   Point l2_pt2(l2_pt2_x, l2_pt2_y);


   Line_Segment l1(l1_pt1,l1_pt2);
   Line_Segment l2(l2_pt1, l2_pt2);




   if(l1.is_segment() && l2.is_segment()){

      teste = (Line_Segment::intercept(l1, l2));
      retorno	=	(teste)	?	"SIM"	:	"NÃO";

   }else{

      cout << "Um dos segmentos de reta passados formam um ponto!" << endl;
      cout << "Não foi possivel verificar" << endl;
   }

   cout << "Os seguimentos " << retorno << " interceptam." <<endl;


   return 0;
}

void texto_entrada(double& l1_pt1_x, double& l1_pt2_x, double& l2_pt1_x, double& l2_pt2_x,
                     double& l1_pt1_y, double& l1_pt2_y, double& l2_pt1_y, double& l2_pt2_y){

   cout << "Digite as coordenadas dos 2 pontos pertencentes ao segmento de reta 1:" << endl;
   cout << "Ponto 1 coordenada X:" << endl;
   cin  >> l1_pt1_x;
   cout << "Ponto 1 coordenada Y:" << endl;
   cin  >> l1_pt1_y;
   cout << "Ponto 2 coordenada X:" << endl;
   cin  >> l1_pt2_x;
   cout << "Ponto 2 coordenada Y:" << endl;
   cin  >> l1_pt2_y;
   cout << "Digite as coordenadas dos 2 pontos pertencentes ao segmento de reta 2:" << endl;
   cout << "Ponto 1 coordenada X:" << endl;
   cin  >> l2_pt1_x;
   cout << "Ponto 1 coordenada Y:" << endl;
   cin  >> l2_pt1_y;
   cout << "Ponto 2 coordenada X:" << endl;
   cin  >> l2_pt2_x;
   cout << "Ponto 2 coordenada Y:" << endl;
   cin  >> l2_pt2_y;
}
