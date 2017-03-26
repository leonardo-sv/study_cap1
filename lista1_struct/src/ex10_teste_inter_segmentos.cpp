/*
Leonardo de Souza Vieira
27/03/2017
*/

#include "struct_space2D.hpp"
#include <string>

using namespace std;

void texto_entrada(line_segment&, line_segment&);
bool texta_segmento(line_segment&);

int main(int argc, char const *argv[]) {
   double distance = 0;
   string retorno;
   bool teste;
   line_segment l1, l2;


   texto_entrada(l1, l2);

   if(texta_segmento(l1) && texta_segmento(l2)){

      teste = intercept_segment_line(l1,l2);
      retorno	=	(teste)	?	"SIM"	:	"NÃO";

   }else{

      cout << "Um dos segmentos de reta passados formam um ponto!" << endl;
      cout << "Não foi possivel verificar" << endl;
   }

   cout << "Os seguimentos " << retorno << " interceptam." <<endl;


   return 0;
}

bool texta_segmento(line_segment& l){
   if(!point_iqual(l.pt1,l.pt2))
      return true;

   return false;
}
void texto_entrada(line_segment& l1, line_segment& l2){

   cout << "Digite as coordenadas dos 2 pontos pertencentes ao segmento de reta 1:" << endl;
   cout << "Ponto 1 coordenada X:" << endl;
   cin  >> l1.pt1.x;
   cout << "Ponto 1 coordenada Y:" << endl;
   cin  >> l1.pt1.y;
   cout << "Ponto 2 coordenada X:" << endl;
   cin  >> l1.pt2.x;
   cout << "Ponto 2 coordenada Y:" << endl;
   cin  >> l1.pt2.y;
   cout << "Digite as coordenadas dos 2 pontos pertencentes ao segmento de reta 2:" << endl;
   cout << "Ponto 1 coordenada X:" << endl;
   cin  >> l2.pt1.x;
   cout << "Ponto 1 coordenada Y:" << endl;
   cin  >> l2.pt1.y;
   cout << "Ponto 2 coordenada X:" << endl;
   cin  >> l2.pt2.x;
   cout << "Ponto 2 coordenada Y:" << endl;
   cin  >> l2.pt2.y;
}
