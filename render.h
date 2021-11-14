#ifndef __RENDER_H__
#define __RENDER_H__
#include "rmath.h"
#include <stdarg.h>



struct Point
{
	struct Matrix * matrix;
	char symbol[];
};
struct Figure
{
	struct Point ** points;
	unsigned int points_county;
	struct Point * center;
};
void free_figure(struct Figure * figure);
struct Point * create_point(const double x, const double y, const double z, const char symbol[]);
struct Figure * create_figure(const unsigned int points_county, ...);
struct Figure * rotate_x(struct Figure * figure, const double theta);
struct Figure * rotate_y(struct Figure * figure, const double theta);
struct Figure * rotate_z(struct Figure * figure, const double theta);
struct Matrix * get_projection(struct Point * point);
#endif
