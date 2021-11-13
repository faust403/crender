#include"rmath.h"
#include<malloc.h>
struct Matrix * create_matrix(unsigned int height, unsigned int width, double num)
{
	struct Matrix * matrix = (struct Matrix*)malloc(sizeof(struct Matrix));
	matrix->height = height;
	matrix->width = width;
	matrix->matrix = (double**)malloc(sizeof(double)*height);

	for(unsigned int i = 0; i < height; i += 1)
		matrix->matrix[i] = (double*)malloc(sizeof(double)*width);
	
	for(unsigned int i = 0; i < height; i += 1)
		for(unsigned int j = 0; j < width; j += 1)
			matrix->matrix[i][j] = num;
	return matrix;
}
struct Matrix * matrix_mult(struct Matrix * matrix1, struct Matrix * matrix2)
{
	if(matrix2->height != matrix1->width)
		return NULL;
	struct Matrix * resMatrix = create_matrix(matrix1->height, matrix2->width, 0.0);
	if(matrix1 == NULL || matrix2 == NULL || matrix1->matrix == NULL || matrix2->matrix == NULL)
		return resMatrix;

	for(unsigned int i = 0; i < matrix1->height; i += 1)
		for(unsigned int j = 0; j < matrix2->width; j += 1)
			for(unsigned int k = 0; k < matrix2->width; k += 1)
				resMatrix->matrix[i][j] += matrix1->matrix[i][k]*matrix2->matrix[k][j];
	return resMatrix;
}
struct Matrix * matrix_add_num(struct Matrix * matrix, double num)
{
	if(matrix == NULL || matrix->matrix == NULL)
		return NULL;
	struct Matrix * resMatrix = create_matrix(matrix->height, matrix->width, 0.0);
	
	for(unsigned int i = 0; i < resMatrix->height; i += 1)
		for(unsigned int j = 0; j < resMatrix->width; j += 1)
			resMatrix->matrix[i][j] += matrix->matrix[i][j] + num;
	return resMatrix;
}
struct Matrix * matrix_add(struct Matrix * matrix1, struct Matrix * matrix2)
{
	if(matrix1 == NULL || matrix2 == NULL || matrix1->matrix == NULL || matrix2->matrix == NULL)
		return NULL;
	if(matrix1->height != matrix2->height || matrix2->width != matrix2->width)
		return NULL;
	struct Matrix * resMatrix = create_matrix(matrix1->height, matrix2->width, 0.0);
	
	for(unsigned int i = 0; i < resMatrix->height; i += 1)
		for(unsigned int j = 0; j < resMatrix->width; j += 1)
			resMatrix->matrix[i][j] += matrix1->matrix[i][j] + matrix2->matrix[i][j];
	return resMatrix;
}
struct Matrix * matrix_Tr(struct Matrix * matrix)
{
	if(matrix == NULL || matrix->matrix == NULL)
		return NULL;
	struct Matrix * resMatrix = create_matrix(matrix->width, matrix->height, 0.0);

	for(unsigned int i = 0; i < resMatrix->height; i += 1)
		for(unsigned int j = 0; j < resMatrix->width; j += 1)
			resMatrix->matrix[i][j] = matrix->matrix[j][i];
	return resMatrix;
}
void free_matrix(struct Matrix * matrix)
{
	if(matrix == NULL || matrix->matrix == NULL)
		return;
	
	for(unsigned int i = 0; i < matrix->height; i += 1)
	{
		free(matrix->matrix[i]);
		matrix->matrix[i] = NULL;
	}
	free(matrix->matrix);
	matrix->matrix = NULL;
	free(matrix);
	matrix = NULL;
	return;
}
