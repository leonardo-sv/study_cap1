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
	point	pt1;
	point	pt2;
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

bool point_iqual(const point&, const point&);
double distance(const point&, const point&);
double polygon_perimeter(const simple_polygon&);
double distance_haversine(const point&, const point&);
double degrees_to_radians(double);
double hessean_equation(const point&, const point&, const point&);
double distance_point_line(const point&, const point&, const point&);
double distance_point_segment_line(const line_segment&, const point&);
bool intercept_segment_line(const line_segment&, const line_segment);
bool test_interval(double, double, double);
bool simple_polygon_test(const simple_polygon&);
double polygon_area(const simple_polygon&);

#endif // __struct_space2D_hpp_
