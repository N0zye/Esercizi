#include "swap.h"
void swap(int &x, int &y) {
	const int tm = x;
	x = y;
	y = tm;
}