/*
Leonardo de Souza Vieira
29/03/2017
*/

#include "space2D.hpp"
#include <string>



using namespace std;

int main(int argc, char const *argv[]) {
   string retorno;
   Point pt1 = Point(0.0, 0.0);
   Point pt2 = Point(1.0, 1.0);
   Point pt3 = Point(2.0, 2.0);
   Point pt4 = Point(3.0, 3.0);
   Point pt5 = Point(3.0, 0.0);
   Point pt6 = Point(2.0, 1.0);
   Point pt7 = Point(1.0, -1.0);
   Point pt8 = Point(1.0, 0.0);
   Point pt9 = Point(0.0, 0.0);

   Line_Segment l1 = Line_Segment(pt1, pt2);
   Line_Segment l2 = Line_Segment(pt2, pt3);
   Line_Segment l3 = Line_Segment(pt3, pt4);
   Line_Segment l4 = Line_Segment(pt4, pt5);
   Line_Segment l5 = Line_Segment(pt5, pt6);
   Line_Segment l6 = Line_Segment(pt6, pt7);
   Line_Segment l7 = Line_Segment(pt7, pt8);
   Line_Segment l8 = Line_Segment(pt8, pt9);

   vector<Point> verts       = {pt1, pt2, pt3, pt4, pt5, pt6, pt7,pt8,pt9};
   vector<Line_Segment> seg  = { l1, l2, l3, l4, l5, l6, l7, l8};

   Simple_Polygon p(7 ,verts, seg);


   retorno	=	(p.is_simple_poligon())	?	"SIM"	:	"NÃO";

   cout << endl<< retorno << " é um poligono simples!!" << endl << endl;

   return 0;
}
