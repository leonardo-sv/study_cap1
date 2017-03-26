/*
Leonardo de Souza Vieira
25/03/2017
*/
#include "struct_space2D.hpp"
#include <cmath>

bool point_iqual(const point& pt1, const point& pt2){
   if(pt1.x == pt2.x && pt1.y == pt2.y)
      return true;
   return false;
}

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

double degrees_to_radians(double degrees){
   double radians = 0;
   radians = (degrees * M_PI) / 180.0;
   return radians;
}

double distance_haversine(const point& pt1, const point& pt2){
   const double R = 6371;
   double dist = 2 * R * asin(sqrt((pow(sin((pt2.y - pt1.y) / 2),2)) + (cos(pt2.y) * cos(pt1.y) * pow(sin((pt2.x-pt1.x)/2),2))));

   return dist;
}

double hessean_equation(const point& pt1_reta, const point& pt2_reta, const point& pt_xy){
   double d, d_sqrt;
   d = (pt2_reta.y - pt1_reta.y) * (pt_xy.x- pt1_reta.x) - (pt2_reta.x - pt1_reta.x) * (pt_xy.y- pt1_reta.y);
   d_sqrt = sqrt(pow((pt2_reta.x - pt1_reta.x),2) + pow((pt2_reta.y - pt1_reta.y),2));

   if(d_sqrt != 0)
      d = double(d) / double(d_sqrt);
   else
      d =  distance(pt1_reta,pt_xy);

   return d;

}
double distance_point_line(const point& pt1_reta, const point& pt2_reta, const point& pt_xy){

   return fabs(hessean_equation(pt1_reta, pt2_reta,pt_xy));
}

double distance_point_segment_line(const line_segment& seg, const point& pt_xy){
   double a, b, c, d, e, u, dx, dy;
   a = seg.pt2.y - seg.pt1.y;
   b = pt_xy.x - seg.pt1.x;
   c = seg.pt2.x - seg.pt1.x;
   d = pt_xy.y - seg.pt1.y;
   e = pow(c, 2) + pow(a, 2);

   if(e != 0)
      u = (b * c + d * a ) / e;
   else
      return distance(seg.pt1, pt_xy);

   if(u < 0)
      u = 0.0;
   else if (u > 1)
      u = 1.0;

   dx = (seg.pt1.x + u * c) - pt_xy.x;
   dy = (seg.pt1.y + u * a) - pt_xy.y;

   return sqrt(pow(dx,2) + pow(dy,2));

}

bool test_interval(double a, double b, double value){

   if((std::min(a, b) <= value) && (std::max(a, b) >= value))
      return true;

   return false;
}

bool intercept_segment_line(const line_segment& l1, const line_segment l2){
   double inter1, inter2;
   double l1_l2pt1 = hessean_equation(l1.pt1, l1.pt2, l2.pt1);
   double l1_l2pt2 = hessean_equation(l1.pt1, l1.pt2, l2.pt2);
   double l2_l1pt1 = hessean_equation(l2.pt1, l2.pt2, l1.pt1);
   double l2_l1pt2 = hessean_equation(l2.pt1, l2.pt2, l1.pt2);
   inter1 =  l1_l2pt1 * l1_l2pt2;
   inter2 =  l2_l1pt1 * l2_l1pt2;


   if(inter1 < 0 && inter2 < 0){
      return true;
   }
   else if(inter1 == 0){
      if(l1_l2pt1 == 0){
         if(test_interval(l1.pt1.x,l1.pt2.x,l2.pt1.x) && test_interval(l1.pt1.y,l1.pt2.y,l2.pt1.y)){
            return true;
         }
      }
      else{
         if(test_interval(l1.pt1.x,l1.pt2.x,l2.pt2.x) && test_interval(l1.pt1.y,l1.pt2.y,l2.pt2.y)){
            return true;
         }
      }
   }
   else if(inter2 == 0){
      if(l2_l1pt1 == 0){
         if(test_interval(l2.pt1.x,l2.pt2.x,l1.pt1.x) && test_interval(l2.pt1.y,l2.pt2.y,l1.pt1.y)){
            return true;
         }
      }
      else{
         if(test_interval(l2.pt1.x,l2.pt2.x,l1.pt2.x) && test_interval(l2.pt1.y,l2.pt2.y,l1.pt2.y)){
            return true;
         }
      }
   }

   return false;
}

bool simple_polygon_test(const simple_polygon& p){
   line_segment l1, l2;
   bool aux,retorno = true;
   int control = 2;
   for (size_t v = 0; v < p.num_vertices - 2; ++v) {

      for (size_t v2 = v + 2; v2 < p.num_vertices - control; ++v2) {
         l1.pt1.x = p.boundary[v].x;
         l1.pt1.y = p.boundary[v].y;
         l1.pt2.x = p.boundary[v+1].x;
         l1.pt2.y = p.boundary[v+1].y;
         l2.pt1.x = p.boundary[v2].x;
         l2.pt1.y = p.boundary[v2].y;
         l2.pt2.x = p.boundary[v2+1].x;
         l2.pt2.y = p.boundary[v2+1].y;


         aux = intercept_segment_line(l1,l2);
         if(aux){
            break;
         }

      }
      if(v == 0)
         control-=1;

      if(aux){

         retorno = false;
         break;
      }
   }
   return retorno;

}

double polygon_area(const simple_polygon& p){
   double area = 0;
   for (size_t i = 0; i < p.num_vertices; i++) {
      area += p.boundary[i].x * p.boundary[i+1].y - p.boundary[i].y * p.boundary[i+1].x;
   }
   return fabs(area/2.0);
}
