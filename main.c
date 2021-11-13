#include<malloc.h>
#include<stdio.h>
#include "render.h"
	
int main()
{
	struct Point * point1 = create_point(1.0, 2.0, 3.0);
	struct Point * point2 = create_point(1.0, 2.0, 3.0);
	struct Figure * figure = create_figure(2, point1, point2);
	
	return 0;
}
