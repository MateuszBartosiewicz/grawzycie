#include "konwertowanie.h"
int index_to_x(int szer, int index){
	int x;
	x=index%szer;
	return x;
}
int index_to_y(int szer, int index){
	int y;
	y= index/szer;
	return y;
}
int x_y_to_index(int szer, int x, int y){
	int index=szer*y+x;
	return index;
}
