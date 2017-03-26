/*
Leonardo de Souza Vieira
25/03/2017
*/
#include "struct_space2D.hpp"
#include <cmath>


double distance(const point& p, const point& q)
{
  double dx = p.x - q.x;
  double dy = p.y - q.y;

  double d2 = dx * dx + dy * dy;

  double d = sqrt(d2);

  return d;
}

double polygon_perimeter(const simple_polygon& polygon){

   double perimeter = 0.0;

   for(size_t i = 0; i < (polygon.num_vertices - 1); ++i)
   {
   		double dx = polygon.boundary[i].x - polygon.boundary[i + 1].x;
   		double dy	= polygon.boundary[i].y - polygon.boundary[i + 1].y;

   		perimeter += sqrt(dx * dx + dy * dy);
   }
   return perimeter;

}

double degree_to_radians(double degrees){
   double radians = 0;
   radians = (degrees * M_PI) / 180.0;
   return radians;
}

double distance_haversine(const point& pt1, const point& pt2){
   double R = 6371;
   double dist = 2 * R * asin(sqrt((pow(sin((pt2.y - pt1.y) / 2),2)) + (cos(pt2.y) * cos(pt1.y) * pow(sin((pt2.x-pt1.x)/2),2))));

   return dist;
}
