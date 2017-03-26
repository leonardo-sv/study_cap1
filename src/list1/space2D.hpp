/*
Leonardo de Souza Vieira
25/03/2017
*/
#ifndef __space2D_hpp__
#define __space2D_hpp__

#include <iostream>

class point
{
public:
  point();

  point(double x, double y);

  ~point();

  double x() const;

  double y() const;

private:

  double x_;
  double y_;
};

class line_segment
{
public:

   line_segment(const point &p1, const point &p2);

   ~line_segment();

   point p1() const;

   point p2() const;

private:

   point p1_;
   point p2_;
};

class string_segment
{
public:
   string_segment(point& vertices, const size_t num_vertices );

   ~string_segment();

   point& vertices();

   size_t num_vertices() const;


private:

   point& vertices_;
   size_t num_vertices_;

};

double distancia(const point& p, const point& q);


#endif // __space2D_hpp__
