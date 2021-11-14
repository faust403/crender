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
void setCursor_normal();
int main()
{
	struct Point * center = create_point(5, 5, 5, " ");
	struct Point * point1 = create_point(0, 0, 0, "#");
	struct Point * point2 = create_point(0, 0, 10, "#");
	struct Point * point3 = create_point(0, 10, 10, "#");
	struct Point * point4 = create_point(0, 10, 0, "#");
	struct Point * point5 = create_point(10, 10, 10, "#");
	struct Point * point6 = create_point(10, 10, 0, "#");
	struct Point * point7 = create_point(10, 0, 10, "#");
	struct Point * point8 = create_point(10, 0, 0, "#");
	struct Figure * figure = create_figure(8, point1, point2, point3, point4, point5, point6, point7, point8);
	figure->center = center;

	printf("\033[1;32m");
	double angle = 0.00;
	while(1)
	{
		sleep(1);
		system("clear");
		for(unsigned int i = 0; i < figure->points_county; i += 1)
		{
			struct Matrix * projection = get_projection(figure->points[i]);
			setCursor(10+projection->matrix[0][0]+figure->center->matrix->matrix[0][0], 10+projection->matrix[1][0]+figure->center->matrix->matrix[1][0]);
			fflush(stdout);
			printf("%s", figure->points[i]->symbol);
			setCursor_normal();
			free_matrix(projection);
		}
		figure = rotate_x(figure, angle);
		figure = rotate_y(figure, angle);
		figure = rotate_z(figure, angle);
		angle += 0.04;
	}

	free_figure(figure);
	return 0;
}
