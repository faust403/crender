#include<malloc.h>
#include<unistd.h>
#include<stdio.h>
#include "render.h"
void setCursor(signed int x, signed int y)
{
	if(x < 0 || y < 0)
		return;
	printf("\033[%d;%dH", y, x*2);
}
int main()
{
	struct Point * center = create_point(2, 2, 2, " ");
	struct Point * point1 = create_point(0, 0, 0, "A");
	struct Point * point2 = create_point(0, 0, 4, "B");
	struct Point * point3 = create_point(0, 4, 4, "C");
	struct Point * point4 = create_point(0, 4, 0, "D");
	struct Point * point5 = create_point(4, 4, 4, "E");
	struct Point * point6 = create_point(4, 4, 0, "F");
	struct Point * point7 = create_point(4, 0, 4, "G");
	struct Point * point8 = create_point(4, 0, 0, "H");
	struct Figure * figure = create_figure(8, point1, point2, point3, point4, point5, point6, point7, point8);
	figure->center = center;

	double angle = 0.00;
	while(1)
	{
		sleep(0.5);
		system("clear");
		for(unsigned int i = 0; i < figure->points_county; i += 1)
		{
			unsigned int x = 0, y = 0;
			for(unsigned int j = 0; j < (unsigned int)figure->points[i]->matrix->matrix[0][0]; j += 1)
				x += 1;
			for(unsigned int j = 0; j < (unsigned int)figure->points[i]->matrix->matrix[1][0]; j += 1)
				y += 1;
			x += figure->center->matrix->matrix[0][0];
			y += figure->center->matrix->matrix[1][0];
			setCursor(x, y);
			fflush(stdout);
			printf("%s", figure->points[i]->symbol);
		}
		figure = rotate_x(figure, angle);
		figure = rotate_z(figure, angle);
		figure = rotate_z(figure, angle);
		angle += 0.01;
	}

	free_figure(figure);
	return 0;
}
