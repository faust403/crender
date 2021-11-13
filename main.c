#include<malloc.h>
#include<stdio.h>
#include "rmath.h"
	
int main()
{
	struct Matrix * matrix1 = create_matrix(3, 2, 0.0);
	struct Matrix * matrix2 = create_matrix(2, 2, 0.0);
	
	matrix1->matrix[0][0] = 1.0;
	matrix1->matrix[0][1] = -6.0;
	matrix1->matrix[1][0] = -1.0;
	matrix1->matrix[1][1] = 3.0;
	matrix1->matrix[2][0] = 6.0;
	matrix1->matrix[2][1] = -3.0;

	matrix2->matrix[0][0] = 2.0;
	matrix2->matrix[0][1] = 4.0;
	matrix2->matrix[1][0] = 0.0;
	matrix2->matrix[1][1] = 5.0;

	struct Matrix * matrix3 = matrix_add(matrix1, matrix2);
	
	free_matrix(matrix1);
	free_matrix(matrix2);
	free_matrix(matrix3);
	return 0;
}
