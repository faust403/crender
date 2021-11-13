#ifndef __RMATH_H__
#define __RMATH_H__
struct Matrix
{
	unsigned int width;
	unsigned int height;

	double ** matrix;
};
struct Matrix * create_matrix(const unsigned int height, const unsigned int width, const double num);
struct Matrix * matrix_mult(const struct Matrix * matrix1, const struct Matrix * matrix2);
struct Matrix * matrix_mult_num(struct Matrix * matrix, const double num);
struct Matrix * matrix_add(const struct Matrix * matrix1, const struct Matrix * matrix2);
struct Matrix * matrix_add_num(struct Matrix * matrix, const double num);
struct Matrix * matrix_Tr(struct Matrix * matrix1);
struct Matrix * mult_x(const struct Matrix * matrix, const double theta);
struct Matrix * mult_y(const struct Matrix * matrix, const double theta);
struct Matrix * mult_z(const struct Matrix * matrix, const double theta);
struct Matrix * neg_matrix(struct Matrix * matrix);
void free_matrix(struct Matrix * matrix);
#endif
