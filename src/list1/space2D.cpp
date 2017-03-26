/*
Leonardo de Souza Vieira
25/03/2017
*/
#include "space2D.hpp"
#include <iostream>
#include <cmath>

using namespace std;

point::point(double x, double y)
  : x_(x), y_(y)
{
    cout << "point construtor" << endl;
}

point::~point()
{
    cout << "point destrutor" << endl;
}

double point::x() const
{
    return x_;
}

double point::y() const
{
    return y_;
}

line_segment::line_segment(const point &p1, const point &p2)
   : p1_(p1),p2_(p2)
{
   cout << "line_segment construtor" << endl;
}

line_segment::~line_segment()
{
   cout << "line_segment destrutor" << endl;
}
point line_segment::p1() const
{
    return p1_;
}

point line_segment::p2() const
{
    return p2_;
}

string_segment::string_segment(point& vertices, const size_t num_vertices)
   :vertices_(vertices), num_vertices_(num_vertices)
{
   cout << "string_segment construtor" << endl;
}

string_segment::~string_segment()
{
   cout << "string_segment destrutor" << endl;
}

point& string_segment::vertices()
{
   return vertices_;
}
size_t string_segment::num_vertices() const
{
      return num_vertices_;
}



double distancia(const point& p, const point& q)
{
  double dx = p.x() - q.x();
  double dy = p.y() - q.y();

  double d2 = dx * dx + dy * dy;

  double d = sqrt(d2);

  return d;
}
