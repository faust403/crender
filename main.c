#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "render.h"


int main()
{	
	struct Point * center = create_point(0, 0, 0, ' ');
	struct Point * point1 = create_point(5, 5, 0, '#');
	struct Point * point2 = create_point(-5, -5, 0, '#');
	struct Figure * figure = create_figure(2, point1, point2);
	figure->center = center;
	//set_line(figure, point1, point2, '*');

	//printf("\033[1;32m");
	double angle = 0.00;
	while(1)
	{
		if(angle >= 0.32)
			angle = 0.0;
		sleep(1);
		system("clear");
		for(unsigned int i = 0; i < figure->points_county; i += 1)
		{
			struct Matrix * projection = neg_matrix(get_projection(figure->points[i]));
			print_point(20+projection->matrix[0][0]+figure->center->matrix->matrix[0][0], 20+projection->matrix[1][0]+figure->center->matrix->matrix[1][0], figure->points[i]->symbol);
			free_matrix(projection);
		}
		figure = rotate_x(figure, angle);
		//figure = rotate_y(figure, angle);
		//figure = rotate_z(figure, angle);
		angle += 0.04;
	}

	free_figure(figure);
	return 0;
}
