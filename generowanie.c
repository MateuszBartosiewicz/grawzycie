#include "generowanie.h"
void zamiana_tablic(siatka *gen){

	int *j;
	j=gen->tab;
	gen->tab=gen->temp;
	gen->temp=j;
}
void porownaj_stany(int x, int y, siatka *gen, int ilosc_zywych){
	int index=x_y_to_index(SZER,x,y);
	int stan=gen->tab[index];
	if(stan== MARTWA ){
		if(ilosc_zywych==3)
			gen->temp[index]= ZYWA ;
		else
			gen->temp[index]= MARTWA ;
	}

	else if(stan==ZYWA) {
		if(ilosc_zywych ==2 || ilosc_zywych ==3){
			gen->temp[index]= ZYWA;
		}
		else
			gen->temp[index]= MARTWA;

	}


}
void generator(siatka *gen,opcje opcje_m){
	int x, y,g, ilosc_zywych;
	for(g=1;g<=opcje_m.ilosc_generacji;g++){	
		for(y=0;y<WYS;y++)
		{
			for(x=0;x<SZER;x++){
				ilosc_zywych=licz_zywe(x,y,gen);

				porownaj_stany(x,y,gen, ilosc_zywych);

			}
		}
		if(g%opcje_m.co_ktora_generacja_zapis==0)

			drukuj_BMP(gen, g, opcje_m.rozmiar_obrazu);	

		zamiana_tablic(gen);

	}
	zapis_do_pliku(opcje_m.plik_zapis,gen);
}

int licz_zywe(int x, int y, siatka *gen){
	int zywa=0, index=0, ax=0, ay=0, i;
	int tabx[8], taby[8];
	zasady(tabx,taby);
	int martwe=0;	
	for(i=0;i<8;i++){
		if(tabx[i]+x<0 || tabx[i]+x>=SZER || taby[i]+y<0 ||taby[i]+y>=WYS)
		{
			martwe++;
		}


		else
		{
			ax=tabx[i]+x;
			ay=taby[i]+y;
			index=x_y_to_index(SZER,ax,ay);
			if(gen->tab[index]==ZYWA) zywa++;
		}
	}
	return zywa;
}
