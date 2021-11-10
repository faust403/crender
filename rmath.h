#ifndef __RMATH_H__
#define __RMATH_H__
struct Matrix
{
	unsigned int width;
	unsigned int height;

	double ** matrix;
};
struct Matrix * create_matrix(unsigned int width, unsigned int height);
struct Matrix * matrix_mult(struct Matrix * matrix1, struct Matrix * matrix2);
struct Matrix * rotate_x(struct Matrix * matrix);
struct Matrix * rotate_y(struct Matrix * matrix);
struct Matrix * rotate_z(struct Matrix * matrix);
#endif
