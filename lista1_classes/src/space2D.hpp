/*
Leonardo de Souza Vieira
29/03/2017
*/
#ifndef __space2D_hpp__
#define __space2D_hpp__

#include <iostream>
#include <vector>

class Point{

public:

   Point(double x, double y);

   ~Point();

   double x() const;

   double y() const;

   double distance_point(const Point&);

   bool equal(const Point&);

private:

   double x_;
   double y_;

};

class Line_Segment{

public:

   Line_Segment(Point pt1, Point pt2);

   ~Line_Segment();

   Point pt1() const;

   Point pt2() const;

   double distance_point(const Point&);

   double hassean_equation(const Point&) const;

   bool is_segment();

   static bool intercept(const Line_Segment&, const Line_Segment&);

private:

   Point pt1_;
   Point pt2_;
};

class Line_String{
   Line_String(size_t, std::vector<Point>);

   ~Line_String();

   size_t num_verts() const;

   std::vector<Point> vertices();

private:

   size_t num_verts_;
   std::vector<Point> vertices_;

};

class Simple_Polygon{

public:

   Simple_Polygon(size_t, std::vector<Point>, std::vector<Line_Segment>);

   ~Simple_Polygon();

   size_t num_verts() const;

   size_t num_segments() const;

   std::vector<Point> vertices();

   std::vector<Line_Segment> seg();

   double polygon_area();

   bool is_simple_poligon();

private:

   size_t num_verts_;
   size_t num_segments_;
   std::vector<Point> vertices_;
   std::vector<Line_Segment> segments_;
};

bool interval(const double, const double, const double);
double distance_haversine(const Point&, const Point&);
double degrees_to_radians(const double);

#endif // __space2D_hpp_
