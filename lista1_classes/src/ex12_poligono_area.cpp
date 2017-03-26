/*
Leonardo de Souza Vieira
29/03/2017
*/

#include "space2D.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

   size_t n = 6;
   Point pt0 = Point (3.0, 5.0);
   Point pt1 = Point (2.8, 4.0);
   Point pt2 = Point (4.0, 2.5);
   Point pt3 = Point (2.0, 1.0);
   Point pt4 = Point (1.0, 3.0);
   Point pt5 = Point (3.0, 5.0);

   Line_Segment l1 = Line_Segment(pt0, pt1);
   Line_Segment l2 = Line_Segment(pt1, pt2);
   Line_Segment l3 = Line_Segment(pt2, pt3);
   Line_Segment l4 = Line_Segment(pt3, pt4);
   Line_Segment l5 = Line_Segment(pt4, pt5);

   vector<Point> verts       = {pt0, pt1, pt2, pt3, pt4, pt5};
   vector<Line_Segment> seg  = { l1, l2, l3, l4, l5 };

   Simple_Polygon p = Simple_Polygon(n, verts, seg);

   cout << " A área do poligono simples é:" << p.polygon_area() << endl;

   return 0;
}
