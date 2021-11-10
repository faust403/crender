#include<malloc.h>
#include<unistd.h>
#include<stdio.h>
#include "rmath.h"
	
int main()
{
	struct Matrix * matrix1 = create_matrix(1, 3);
	struct Matrix * matrix2 = create_matrix(3, 3);
	matrix1->matrix[0][0] = 1.0;
	matrix2->matrix[0][0] = 1.0;
	struct Matrix * resMat = matrix_mult(matrix1, matrix2);
	for(int i = 0; i < resMat->height; i += 1)
	{	for(int j = 0; j < resMat->width; j += 1)
			printf("%f", resMat->matrix[i][j]);
		printf("\n");
	}
	return 0;
}
