#include<malloc.h>
#include<stdio.h>
#include<stdarg.h>
#include"rmath.h"
#include"render.h"
struct Point * create_point(const double x, const double y, const double z)
{
	struct Point * point = (struct Point*)malloc(sizeof(struct Point));
	point->matrix = create_matrix(3, 1, 0.0);
	point->matrix->matrix[0][0] = x;
	point->matrix->matrix[1][0] = y;
	point->matrix->matrix[2][0] = z;

	return point;
}
struct Figure * create_figure(const unsigned int points_county, ...)
{
	struct Figure * figure = (struct Figure*)malloc(sizeof(struct Figure));
	figure->points_county = points_county;
	figure->points = (struct Point**)malloc(sizeof(struct Point));
	register int i = 1;
	va_list arguments;
	va_start(arguments, points_county);

	while(i != points_county+1)
	{
		struct Point * currentPoint = va_arg(arguments, struct Point*);
		if(currentPoint == NULL)
		{
			free(figure->points);
			figure->points = NULL;
			free(figure);
			figure = NULL;
			return NULL;
		}
		figure->points = realloc(figure->points, sizeof(struct Point) * i);
		figure->points[i-1] = currentPoint;
		i += 1;
	}
	va_end(arguments);
	return figure;
}
void free_figure(struct Figure * figure)
{
	if(figure == NULL)
		return;

	for(unsigned int i = 0; i < figure->points_county; i += 1)
	{
		free_matrix(figure->points[i]->matrix);
		figure->points[i]->matrix = NULL;
		free(figure->points[i]);
		figure->points[i] = NULL;
	}
	free(figure->points);
	figure->points = NULL;
	free(figure);
	figure = NULL;
	return;
}
