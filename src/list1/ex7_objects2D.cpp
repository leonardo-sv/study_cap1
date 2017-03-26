#include "struct_space2D.hpp"


using namespace std;

int main(int argc, char const *argv[]) {

   simple_polygon	poly;
   point pt0 {3.0, 5.0};
   point pt1 {2.8, 4.0};
   point pt2 {4.0, 2.5};
   point pt3 {2.0, 1.0};
   point pt4 {1.0, 3.0};
   point pt5 {3.0, 5.0};

   poly.boundary = new point[6];
   poly.num_vertices = 6;

   poly.boundary[0] = pt0;
   poly.boundary[1] = pt1;
   poly.boundary[2] = pt2;
   poly.boundary[3] = pt3;
   poly.boundary[4] = pt4;
   poly.boundary[5] = pt5;

   cout << distance(pt0,pt1) << endl;
   cout << polygon_perimeter(poly) << endl;


   return 0;
}
