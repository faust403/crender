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
			for(unsigned int k = 0; k < matrix2->height; k += 1)
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
struct Matrix * mult_x(struct Matrix * matrix, const double theta)
{
	register struct Matrix * Rx = create_matrix(3, 3, 0.0);
	Rx->matrix[0][0] = 1.0;
	Rx->matrix[1][1] = cos(theta);
	Rx->matrix[1][2] = -sin(theta);
	Rx->matrix[2][1] = sin(theta);
	Rx->matrix[2][2] = cos(theta);
	
	struct Matrix * Res = matrix_mult(Rx, matrix);
	free_matrix(Rx);
	free_matrix(matrix);
	return Res;
}
struct Matrix * mult_y(struct Matrix * matrix, const double theta)
{
	register struct Matrix * Ry = create_matrix(3, 3, 0.0);
	Ry->matrix[0][0] = cos(theta);
	Ry->matrix[0][2] = sin(theta);
	Ry->matrix[1][1] = 1.0;
	Ry->matrix[2][0] = -sin(theta);
	Ry->matrix[2][2] = cos(theta);

	struct Matrix * Res = matrix_mult(Ry, matrix);
        free_matrix(Ry);
	free_matrix(matrix);
	return Res;
}
struct Matrix * mult_z(struct Matrix * matrix, const double theta)
{
	register struct Matrix * Rz = create_matrix(3, 3, 0.0);
	Rz->matrix[0][0] = cos(theta);
	Rz->matrix[0][1] = -sin(theta);
	Rz->matrix[1][0] = sin(theta);
	Rz->matrix[1][1] = cos(theta);
	Rz->matrix[2][2] = 1.0;
	
	struct Matrix * Res = matrix_mult(Rz, matrix);
        free_matrix(Rz);
	free_matrix(matrix);
	return Res;
}
unsigned int get_distance(const struct Matrix * point_from, const struct Matrix * point_to)
{
	if(point_from == NULL || point_from->matrix == NULL || point_to == NULL || point_to->matrix == NULL)
		return 0;

	double xp1 = point_from->matrix[0][0],
	yp1 = point_from->matrix[1][0],
	zp1 = point_from->matrix[2][0],
	xp2 = point_to->matrix[0][0],
	yp2 = point_to->matrix[1][0],
	zp2 = point_to->matrix[2][0];
	return (unsigned int)sqrt(pow(xp2-xp1, 2) + pow(yp2-yp1, 2) + pow(zp2-zp1, 2));
}
unsigned int get_distance_x(const struct Matrix * point_from, const struct Matrix * point_to)
{
	if(point_from == NULL || point_from->matrix == NULL || point_to == NULL || point_to->matrix == NULL)
                return 0;

	if(point_from->matrix[0][0] < 0 && point_to->matrix[0][0] > 0)
		return abs(point_from->matrix[0][0]) + abs(point_to->matrix[0][0]);
	return abs(point_from->matrix[0][0] - point_to->matrix[0][0]);
}
unsigned int get_distance_y(const struct Matrix * point_from, const struct Matrix * point_to)
{
	        if(point_from == NULL || point_from->matrix == NULL || point_to == NULL || point_to->matrix == NULL)                          
                return 0;                                                                                                             
                                                                                                                                      
        if(point_from->matrix[1][0] < 0 && point_to->matrix[1][0] > 0)                                                                
                return abs(point_from->matrix[1][0]) + abs(point_to->matrix[1][0]);                                                   
        return abs(point_from->matrix[1][0] - point_to->matrix[1][0]);
}
unsigned int get_distance_z(const struct Matrix * point_from, const struct Matrix * point_to)
{
	        if(point_from == NULL || point_from->matrix == NULL || point_to == NULL || point_to->matrix == NULL)                          
                return 0;                                                                                                             
                                                                                                                                      
        if(point_from->matrix[2][0] < 0 && point_to->matrix[2][0] > 0)                                                                
                return abs(point_from->matrix[2][0]) + abs(point_to->matrix[2][0]);                                                   
        return abs(point_from->matrix[2][0] - point_to->matrix[2][0]);

}
