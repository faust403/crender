#ifndef __RENDER_H__
#define __RENDER_H__
#include "rmath.h"
#include <stdarg.h>
struct Point
{
	struct Matrix * matrix;
};
struct Figure
{
	struct Point ** points;
	unsigned int points_county;
};
void free_figure(struct Figure * figure);
struct Point * create_point(const double x, const double y, const double z);
struct Figure * create_figure(const unsigned int points_county, ...);
#endif
