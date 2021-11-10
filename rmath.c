#include"rmath.h"
#include<malloc.h>
static unsigned int largest(unsigned int a, unsigned int b)
{ 
	return a > b ? a : b;
}
static unsigned int least(unsigned int a, unsigned int b)
{
	return a < b ? a : b;
}
struct Matrix * create_matrix(unsigned int width, unsigned int height)
{
        struct Matrix * matrix = (struct Matrix*)malloc(sizeof(struct Matrix));
        if(matrix == NULL)
                return NULL;

        matrix->height = height;
        matrix->width = width;
        matrix->matrix = (double**)malloc(sizeof(double)*height);
        
        for(int i = 0; i < height; i += 1)
        {
                matrix->matrix[i] = (double*)malloc(sizeof(double)*width);
                if(matrix->matrix[i] == NULL)
                        return NULL;
        }
        for(int i = 0; i < height; i += 1)
        {
                for(int j = 0; j < width; j += 1)
                {
                        matrix->matrix[i][j] = 0.0;
                }
        }

        return matrix;
}

struct Matrix * matrix_mult(struct Matrix * matrix1, struct Matrix * matrix2)
{
	if(matrix1 == NULL || matrix2 == NULL || matrix1->matrix == NULL || matrix2->matrix == NULL) 
		return NULL;
	struct Matrix * resMatrix = create_matrix(
			least(matrix1->width, matrix2->width),
			largest(matrix1->height, matrix2->height)
	);

	for(unsigned int i = 0; i < resMatrix->height; i += 1)
	{
		for(unsigned int j = 0; j < resMatrix->width; j += 1)
		{
			unsigned int lar = largest(matrix1->width, matrix2->width);
			for(unsigned int k = 0; k < lar; k += 1)
			{
				resMatrix->matrix[i][j] += matrix2->matrix[i][j] * matrix1->matrix[j][i];
			}
		}
	}
	return resMatrix;
}
