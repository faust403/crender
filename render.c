#include<malloc.h>
#include<string.h>
#include<stdarg.h>
#include"rmath.h"
#include"render.h"



struct Point * create_point(const double x, const double y, const double z, const char symbol[])
{
	struct Point * point = (struct Point*)malloc(sizeof(struct Point));
	point->matrix = create_matrix(3, 1, 0.0);
	point->matrix->matrix[0][0] = x;
	point->matrix->matrix[1][0] = y;
	point->matrix->matrix[2][0] = z;
	strcpy(point->symbol, symbol);

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
struct Figure * rotate_x(struct Figure * figure, const double theta)
{
	if(figure == NULL)
		return NULL;
	
	for(unsigned int i = 0; i < figure->points_county; i += 1)
		figure->points[i]->matrix = mult_x(figure->points[i]->matrix, theta);
	return figure;
}
struct Figure * rotate_y(struct Figure * figure, const double theta)
{
	if(figure == NULL)
                return NULL;
        
	for(unsigned int i = 0; i < figure->points_county; i += 1)
                figure->points[i]->matrix = mult_y(figure->points[i]->matrix, theta);
        return figure;

}
struct Figure * rotate_z(struct Figure * figure, const double theta)
{
	if(figure == NULL)
                return NULL;
        
	for(unsigned int i = 0; i < figure->points_county; i += 1)
                figure->points[i]->matrix = mult_z(figure->points[i]->matrix, theta);
        return figure;

}
struct Matrix * get_projection(struct Point * point)
{
	if(point == NULL)
		return NULL;

	struct Matrix * projection_matrix = create_matrix(2, 3, 0.0);
	projection_matrix->matrix[0][0] = 1.0;
	projection_matrix->matrix[1][1] = 1.0;

	struct Matrix * resMatrix_projection = matrix_mult(projection_matrix, point->matrix);
	free_matrix(projection_matrix);
	return resMatrix_projection;
}
void print_point(signed int x, signed int y, const char symbol[])
{
        if(x < 0 || y < 0)
                return;
        fflush(stdout);
        printf("\033[%d;%dH", y, x*2);
        printf("%s", symbol);
}
