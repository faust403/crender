#include<malloc.h>
#include<stdarg.h>
#include"rmath.h"
#include"render.h"
struct Point * create_point(double x, double y, double z)
{
	struct Point * point = (struct Point*)malloc(sizeof(struct Point));
	point->matrix = create_matrix(3, 1, 0.0);
	point->matrix->matrix[0][0] = x;
	point->matrix->matrix[1][0] = y;
	point->matrix->matrix[2][0] = z;

	return point;
}
struct Figure * create_figure(unsigned int points_county, ...)
{
	struct Figure * figure = (struct Figure*)malloc(sizeof(struct Figure));
	figure->points_county = points_county;
	figure->points = (struct Point**)malloc(sizeof(struct Point));
	register int i = 1;
	va_list arguments;
	va_start(arguments, points_county);

	while(i != points_county+1)
	{
		figure->points = realloc(figure->points, sizeof(struct Point) * i);
		figure->points[i-1] = va_arg(arguments, struct Point*);
		i += 1;
	}
	va_end(arguments);

	return figure;
}
