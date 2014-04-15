#include "drukuj_BMP.h"
void drukuj_BMP(siatka *gen,int numer_generacji)
int a,b, x, y;
int szer = gen->szer;
int wys = gen->wys;
char nazwa[23]="generacja_nr_";
char *rozszerzenie=".bmp";
strcat(nazwa,numer_generacji);
strcat(nazwa,rozszerzenie);

BMP *bmp = BMP_new (szer*10, wys*10);
BMP_clear (bmp, RGB_RED);
for(y=0;y<wys;y++)
		{
			for(x=0;x<szer;x++){
				x_y_to_index(szer,x,y);
				if(gen->tab[index]==1)
				BMP_fillrect (bmp, x*10,y*10, 10,10, RGB_PURPLE);
			}
		}

if (1 == BMP_write (bmp,nazwa ))
		printf ("Created file %s",nazwa);

}






