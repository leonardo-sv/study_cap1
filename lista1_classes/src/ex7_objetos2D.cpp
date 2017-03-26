/*
Leonardo de Souza Vieira
25/03/2017
*/

#include "space2D.hpp"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {

   Point pt1(0,0);
   Point pt2(2,2);
   Point pt3(3,3);
   Point pt4(4,4);

   cout << pt1.distance_point(pt2) << endl;
   cout << pt3.equal(pt2) << endl;

   Line_Segment l1(pt1,pt2);
   Line_Segment l2(pt3,pt4);


   cout << l1.pt1().x() << ", " << l1.pt1().y() << endl;
   cout << l1.pt2().x() << ", " << l1.pt2().y() << endl;



   return 0;
}
