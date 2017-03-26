/*
Leonardo de Souza Vieira
28/03/2017
*/

#include "struct_space2D.hpp"
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
   simple_polygon poly;
   poly.boundary = new	point[6];
   poly.num_vertices = 6;

   poly.boundary[0]	=	{3.0,	5.0};
   poly.boundary[1]	=	{2.8,	4.0};
   poly.boundary[2]	=	{4.0,	2.5};
   poly.boundary[3]	=	{2.0,	1.0};
   poly.boundary[4]	=	{1.0,	3.0};
   poly.boundary[5]	=	{3.0,	5.0};




   cout << " A área do poligono simples é:" << polygon_area(poly) << endl;

   return 0;
}
