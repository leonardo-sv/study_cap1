/*
Leonardo de Souza Vieira
29/03/2017
*/
#include "space2D.hpp"
#include <iostream>
#include <cmath>

//Inicio Funções membro Point
Point::Point(double x, double y)
  : x_(x), y_(y){}

Point::~Point(){}

double Point::x() const{
    return x_;
}

double Point::y() const{
    return y_;
}

double Point::distance_point(const Point &p){
   double dx = x_ - p.x();
   double dy = y_ - p.y();

   double d2 = dx * dx + dy * dy;

   double d = sqrt(d2);

   return d;
}

bool Point::equal(const Point &p){
   if(x_ == p.x() && y_ == p.y())
      return true;

   return false;
}
//Fim Funçõe Membro Point

//Inicio Funções Membro Line_Segment
Line_Segment::Line_Segment(Point pt1, Point pt2)
   :pt1_(pt1), pt2_(pt2){

    if(pt1_.equal(pt2_)){
      std::cout << "CUIDADO os pontos do Line_Segment são iguais" << std::endl;
   }
}

Line_Segment::~Line_Segment(){}

Point Line_Segment::pt1() const{
    return pt1_;
}

Point Line_Segment::pt2() const{
    return pt2_;
}

double Line_Segment::distance_point(const Point& pt){
   double u, dx, dy, d_segment_points_quad;

   d_segment_points_quad = pow((pt2_.x() - pt1_.x()), 2) + pow((pt2_.y() - pt1_.y()), 2);

   if(d_segment_points_quad != 0){
      u = ((pt.x() - pt1_.x()) * (pt2_.x() - pt1_.x()) +
            (pt.y() - pt1_.y()) * (pt2_.y() - pt1_.y())) / d_segment_points_quad;
   }
   else{
      std::cout << "Os 2 pontos do seguimento são iguais, assim calcula-se a distância pontos." << std::endl;
      return pt1_.distance_point(pt);
   }

   if(u < 0){
      u = 0.0;
   }
   else if (u > 1){
      u = 1.0;
   }

   dx = (pt1_.x() + u * (pt2_.x() - pt1_.x())) - pt.x();
   dy = (pt1_.y() + u * (pt2_.y() - pt1_.y())) - pt.y();

   return sqrt(pow(dx,2) + pow(dy,2));

}

double Line_Segment::hassean_equation(const Point& pt) const{
   double d, d_segment_points;
   d = (pt2_.y() - pt1_.y()) * (pt.x()- pt1_.x()) - (pt2_.x() - pt1_.x()) * (pt.y()- pt1_.y());
   d_segment_points = sqrt(pow((pt2_.x() - pt1_.x()),2) + pow((pt2_.y() - pt1_.y()),2));;

   if(d_segment_points > 0){
      d = double(d) / double(d_segment_points);
   }
   else{
      std::cout << "Os pontos do Line_Segment são iguais" << std::endl;
   }

   return d;
}

bool Line_Segment::intercept(const Line_Segment& l1, const Line_Segment& l2){

   double l1_oposto_l2pt1 = l1.hassean_equation(l2.pt1());
   double l1_oposto_l2pt2 = l1.hassean_equation(l2.pt2());
   double l2_oposto_l1pt1 = l2.hassean_equation(l1.pt1());
   double l2_oposto_l1pt2 = l2.hassean_equation(l1.pt2());

   double l1_x_l2 = l1_oposto_l2pt1 * l1_oposto_l2pt2;
   double l2_x_l1 = l2_oposto_l1pt1 * l2_oposto_l1pt2;

   if(l1_x_l2 < 0 && l2_x_l1 < 0){
      return true;
   }
   else if(l1_x_l2 == 0){
      if(l1_oposto_l2pt1 == 0){
         if(interval(l1.pt1().x(), l1.pt2().x(), l2.pt1().x()) &&
                        interval(l1.pt1().y(), l1.pt2().y(), l2.pt1().y())){
            return true;
         }
      }
      else{
         if(interval(l1.pt1().x(), l1.pt2().x(), l2.pt2().x()) &&
               interval(l1.pt1().y(), l1.pt2().y(), l2.pt2().y())){
            return true;
         }
      }
   }
   else if(l2_x_l1 == 0){
      if(l2_oposto_l1pt1 == 0){
         if(interval(l2.pt1().x(), l2.pt2().x(), l1.pt1().x()) &&
                  interval(l2.pt1().y(), l2.pt2().y(), l1.pt1().y())){
            return true;
         }
      }
      else{
         if(interval(l2.pt1().x(),l2.pt2().x(),l1.pt2().x()) &&
                  interval(l2.pt1().y(), l2.pt2().y(), l1.pt2().y())){
            return true;
         }
      }
   }

   return false;
}

bool Line_Segment::is_segment(){
   if(!pt1_.equal(pt2_)){
      return true;
   }
  return false;

}
//Fim Funções Membro Line_Segment

//Inicio Funcões membro Simple_Polygon
Simple_Polygon::Simple_Polygon(size_t num_verts, std::vector<Point> vertices, std::vector<Line_Segment> segments)
   :num_verts_(num_verts), vertices_(vertices), segments_(segments){
      num_segments_ = num_verts -1;
}

Simple_Polygon::~Simple_Polygon(){}

size_t Simple_Polygon::num_verts() const{
    return num_verts_;
}

size_t Simple_Polygon::num_segments() const{
    return num_segments_;
}

std::vector<Point> Simple_Polygon::vertices(){
    return vertices_;
}

double Simple_Polygon::polygon_area(){
   double area = 0;
   for (size_t i = 0; i < num_verts_; i++) {
      area += vertices_[i].x() * vertices_[i+1].y() - vertices_[i].y() * vertices_[i+1].x();
   }
   return fabs(area/2.0);
   return 0;
}

bool Simple_Polygon::is_simple_poligon(){
   bool aux = false,retorno = true;
   int control = 1;
   for (size_t i = 0; i < num_segments_; i++) {

      for (size_t j = i + 2; j <  num_segments_ - control; j++) {

         aux = Line_Segment::intercept(segments_[i],segments_[j]);

         if(aux){
            break;
         }
      }
      if(i == 0){
         control-=1;
      }
      if(aux){
         std::cout << "aux" << '\n';
         std::cout << aux << '\n';
         std::cout << true << '\n';

         std::cout << i << i+2<< '\n';
         std::cout << segments_[i].pt1().x() << ", " << segments_[i].pt1().y() <<'\n';
         std::cout << segments_[i].pt2().x() << ", " << segments_[i].pt2().y() <<'\n';
         std::cout << segments_[i+2].pt1().x() << ", " << segments_[i+2].pt1().y()<< '\n';
         std::cout << segments_[i+2].pt2().x() << ", " << segments_[i+2].pt2().y() <<'\n';
         retorno = false;
         break;
      }
   }
   return retorno;
}
//Fim Funções Membro Simple_Polygon

//Inicio Funções Membro Line_String
Line_String::Line_String(size_t num_verts, std::vector<Point> vertices)
   :num_verts_(num_verts), vertices_(vertices){}

Line_String::~Line_String(){}

size_t Line_String::num_verts() const{
    return num_verts_;
}

std::vector<Point> Line_String::vertices(){
    return vertices_;
}
//Fim Funções Membro Line_String

//Funções adicionais

double degrees_to_radians(const double degrees){
   double radians = 0;
   radians = (degrees * M_PI) / 180.0;
   return radians;
}

double distance_haversine(const Point& pt1, const Point& pt2){
   const int R = 6371;
   double dist = 2 * R * asin(sqrt( (pow(sin((pt2.y() - pt1.y()) / 2), 2)) +
                  (cos(pt2.y()) * cos(pt1.y()) * pow(sin((pt2.x() - pt1.x()) / 2), 2))));

   return dist;
}

bool interval(const double a, const double b, const double value){

   if((std::min(a, b) <= value) && (std::max(a, b) >= value))
      return true;

   return false;
}
//Fim das Funções adicionais
