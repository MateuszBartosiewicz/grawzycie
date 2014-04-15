#include "zapis_do_pliku.h"
void zapis_do_pliku(char *nazwa, siatka *gen){
	FILE *plik;
	int index=0;
	int x, y,ax,ay;

	if((plik=fopen(nazwa,"w"))==NULL){
		fprintf(stdin,"Nie mogę otworzyć pliku do zapisu %s\n",nazwa);
		exit (1);
	}
	for(y=0;y<WYS;y++)
	{
		for(x=0;x<SZER;x++){
			index=	x_y_to_index(SZER,x,y);
			if(gen->tab[index]==ZYWA){
				ax=index_to_x(SZER,index);
				ay=index_to_y(SZER,index);
				fprintf(plik,"%d\t%d\n",ax,ay);
			}
		}
	}


	if(fclose(plik) != 0)
		fprintf(stderr,"Błąd przy zamykaniu pliku.\n");
}
