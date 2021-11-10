#ifndef __RENDER_H__
#define __RENDER_H__
struct Point
{
	unsigned long x;
	unsigned long y;
	unsigned long z;
};
struct Figure
{
	struct Point ** points;
	unsigned int size;
};

struct Point * create_point(unsigned long x, unsigned long y, unsigned long z);
struct Figure * create_figure();

void add_point(struct Figure * figure, struct Point * point);
void realloc_point(struct Figure * figure, struct Point * oldPoint, unsigned long * param, unsigned long * value);
void remove_point(struct Figure * figure, struct Point * point);
void delete_figure(struct Figure * figure);
#endif
