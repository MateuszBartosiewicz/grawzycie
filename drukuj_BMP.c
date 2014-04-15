#include "drukuj_BMP.h"

void drukuj_BMP(siatka *gen, int i, int rozmiar_obrazu){

	int x,y,index;

	char *nazwa=(char*)malloc(sizeof("obrazy_BMP.generacja_nr_.bmp")+sizeof(int));

	sprintf(nazwa,"obrazy_BMP/generacja_nr_%d.bmp",i);
	BMP *bmp = BMP_new (SZER*rozmiar_obrazu, WYS*rozmiar_obrazu);
	BMP_clear (bmp, RGB_RED);
	for(y=0;y<WYS;y++)
	{
		for(x=0;x<SZER;x++){
			index=x_y_to_index(SZER,x,y);
			if(gen->tab[index]==1)
		BMP_fillrect (bmp, x*rozmiar_obrazu,y*rozmiar_obrazu, rozmiar_obrazu,rozmiar_obrazu,RGB_PURPLE);
		}
	}

	BMP_write (bmp,nazwa );
	free(nazwa);
}






