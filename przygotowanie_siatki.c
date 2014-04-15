#include "przygotowanie_siatki.h"
void alokacja_pamieci(siatka* gen)
{
	int rozmiar=(gen->szer)*(gen->wys);
	gen->tab=(int*)malloc(rozmiar*sizeof(int));
	gen->temp=(int*)malloc(rozmiar*sizeof(int));
}

void zerowanie_tab(siatka *gen){
	int  x, y, index;
	for(y=0;y<WYS;y++)
	{
		for(x=0;x<SZER;x++){
			index=x_y_to_index(SZER,x,y);
			gen->tab[index]=MARTWA;
		}
	}
}

void zerowanie_temp(siatka *gen){
	int  x, y, index;
	for(y=0;y<WYS;y++)

		for(x=0;x<SZER;x++){
			index=x_y_to_index(SZER,x,y);
			gen->temp[index]=MARTWA;
		}

}
void inicjuj(siatka *gen, int x, int y){
	gen->szer=x;
	gen->wys=y;
}

void gotowa_siatka(siatka *gen, int x, int y){
	inicjuj(gen,x,y);
	alokacja_pamieci(gen);
	zerowanie_tab(gen);
	zerowanie_temp(gen);
}

