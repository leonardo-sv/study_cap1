/*
Leonardo de Souza Vieira
28/03/2017
*/

#include "struct_space2D.hpp"
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
   simple_polygon poligono;
   string retorno;
   poligono.boundary = new	point[7];
   poligono.num_vertices = 7;

   poligono.boundary[0]	=	{0.0,	0.0};
   poligono.boundary[1]	=	{1.0,	1.0};
   poligono.boundary[2]	=	{2.0,	2.0};
   poligono.boundary[3]	=	{3.0,	3.0};
   poligono.boundary[4]	=	{0.0,	3.0};
   poligono.boundary[5]	=	{2.0,	1.0};
   poligono.boundary[6]	=	{0.0,	0.0};


   retorno	=	(simple_polygon_test(poligono))	?	"SIM"	:	"NÃO";

   cout << endl<< retorno << " é um poligono simples!!" << endl << endl;

   return 0;
}
