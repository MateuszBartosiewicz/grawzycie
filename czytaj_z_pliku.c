#include "czytaj_z_pliku.h"
void czytaj_z_pliku(char *nazwa, siatka *gen){
	FILE *plik;
	int index=0;
	int x, y;

	if((plik=fopen(nazwa,"r"))==NULL){
		fprintf(stdin,"Nie mogę otworzyć pliku %s\n",nazwa);
		exit (1);
	}

	while(feof(plik)== 0){
		fscanf(plik,"%d %d",&x,&y);
		if(x<0 ||y<0){
		fprintf(stderr,"\nBłąd, argumenty w pliku wejsciowym nie mogą być ujemne\n");
		}
		index=	x_y_to_index(SZER,x,y);
		gen->tab[index]=ZYWA;
	}
	if(fclose(plik) != 0)
		fprintf(stderr,"Błąd przy zamykaniu pliku.\n");
}
