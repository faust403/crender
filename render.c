#include<malloc.h>
#include"render.h"

struct Point * create_point(unsigned long x, unsigned long y, unsigned long z)
{
	struct Point * point = (struct Point*)malloc(sizeof(struct Point));
	
	point->x = x;
	point->y = y;
	point->z = z;

	return point;
}
struct Figure * create_figure()
{
	struct Figure * figure = (struct Figure*)malloc(sizeof(struct Figure));

	figure->points = (struct Point**)malloc(sizeof(struct Point));
	figure->size = 1;
	
	return figure;
}

void add_point(struct Figure * figure, struct Point * point)
{
	if(figure == NULL || point == NULL)
		return;

	figure->points[figure->size-1] = point;
	figure->points = realloc(figure->points, sizeof(struct Point)* (figure->size + 1));
	figure->size += 1;
}
void delete_figure(struct Figure * figure)
{
	if(figure == NULL)
		return;
	for(unsigned int counter = 0; counter < figure->size-1; counter += 1)
	{
		free(figure->points[counter]);
		figure->points[counter] = NULL;
	}

	free(figure->points);
	figure->points = NULL;
	free(figure);
	figure = NULL;
}
