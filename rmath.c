#include"rmath.h"
#include<malloc.h>
#include<math.h>
struct Matrix * create_matrix(const unsigned int height, const unsigned int width, const double num)
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
struct Matrix * matrix_mult(const struct Matrix * matrix1, const struct Matrix * matrix2)
{
	if(matrix2->height != matrix1->width)
		return NULL;
	if(matrix1 == NULL || matrix2 == NULL || matrix1->matrix == NULL || matrix2->matrix == NULL)
		return NULL;
	struct Matrix * resMatrix = create_matrix(matrix1->height, matrix2->width, 0.0);

	for(unsigned int i = 0; i < matrix1->height; i += 1)
		for(unsigned int j = 0; j < matrix2->width; j += 1)
			for(unsigned int k = 0; k < matrix2->width; k += 1)
				resMatrix->matrix[i][j] += matrix1->matrix[i][k]*matrix2->matrix[k][j];
	return resMatrix;
}
struct Matrix * matrix_mult_num(struct Matrix * matrix, const double num)
{
	if(matrix == NULL || matrix->matrix == NULL)
		return NULL;

	for(unsigned int i = 0; i < matrix->height; i += 1)
                for(unsigned int j = 0; j < matrix->width; j += 1)
                        matrix->matrix[i][j] *= num;
	return matrix;
}
struct Matrix * matrix_add_num(struct Matrix * matrix, const double num)
{
	if(matrix == NULL || matrix->matrix == NULL)
		return NULL;
	
	for(unsigned int i = 0; i < matrix->height; i += 1)
		for(unsigned int j = 0; j < matrix->width; j += 1)
			matrix->matrix[i][j] += num;
	return matrix;
}
struct Matrix * matrix_add(const struct Matrix * matrix1, const struct Matrix * matrix2)
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
	free_matrix(matrix);
	return resMatrix;
}
struct Matrix * neg_matrix(struct Matrix * matrix)
{
	if(matrix == NULL || matrix->matrix == NULL)
		return NULL;

	for(unsigned int i = 0; i < matrix->height; i += 1)
		for(unsigned int j = 0; j < matrix->width; j += 1)
			matrix->matrix[i][j] *= -1;
	return matrix;
}
struct Matrix * mult_x(const struct Matrix * matrix, const double theta)
{
	register const struct Matrix * Rx = create_matrix(3, 3, 0.0);
	Rx->matrix[0][0] = 1.0;
	Rx->matrix[1][1] = cos(theta);
	Rx->matrix[1][2] = -sin(theta);
	Rx->matrix[2][1] = sin(theta);
	Rx->matrix[2][2] = cos(theta);
	return matrix_mult(Rx, matrix);
}
struct Matrix * mult_y(const struct Matrix * matrix, const double theta)
{
	register const struct Matrix * Ry = create_matrix(3, 3, 0.0);
	Ry->matrix[0][0] = cos(theta);
	Ry->matrix[0][2] = sin(theta);
	Ry->matrix[1][1] = 1.0;
	Ry->matrix[2][0] = -sin(theta);
	Ry->matrix[2][2] = cos(theta);
	return matrix_mult(Ry, matrix);
}
struct Matrix * mult_z(const struct Matrix * matrix, const double theta)
{
	register const struct Matrix * Rz = create_matrix(3, 3, 0.0);
	Rz->matrix[0][0] = cos(theta);
	Rz->matrix[0][1] = -sin(theta);
	Rz->matrix[1][0] = sin(theta);
	Rz->matrix[1][1] = cos(theta);
	Rz->matrix[2][2] = 1.0;
	return matrix_mult(Rz, matrix);
}
