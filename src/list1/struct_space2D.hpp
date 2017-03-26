/*
Leonardo de Souza Vieira
25/03/2017
*/
#ifndef __struct_space2D_hpp__
#define __struct_space2D_hpp__

#include <iostream>

struct point
{
	double x;
	double y;
};

struct line_segment
{
	point	p1;
	point	p2;
};
struct line_string
{
	point vertices[32];
	size_t num_vertices;
};
struct simple_polygon
{
	point* boundary;
	size_t num_vertices;
};

double distance(const point&, const point&);
double polygon_perimeter(const simple_polygon&);
double distance_haversine(const point&, const point&);
double degree_to_radians(double);


#endif // __space2D_hpp_
