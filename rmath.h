#ifndef __RMATH_H__
#define __RMATH_H__
struct Matrix
{
	unsigned int width;
	unsigned int height;

	double ** matrix;
};
struct Matrix * create_matrix(unsigned int height, unsigned int width, double num);
struct Matrix * matrix_mult(struct Matrix * matrix1, struct Matrix * matrix2);
struct Matrix * matrix_add_num(struct Matrix * matrix, double num);
struct Matrix * matrix_add(struct Matrix * matrix1, struct Matrix * matrix2);
struct Matrix * matrix_Tr(struct Matrix * matrix1);
struct Matrix * mult_x(struct Matrix * matrix);
struct Matrix * mult_y(struct Matrix * matrix);
struct Matrix * mult_z(struct Matrix * matrix);
void free_matrix(struct Matrix * matrix);
#endif
