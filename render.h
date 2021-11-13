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

struct Point * create_point(double x, double y, double z);
struct Figure * create_figure(unsigned int points_county, ...);
#endif
