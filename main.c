#include<stdio.h>
#include<stdlib.h>
#include "siatka.h"
#include "generowanie.h"
#include "czytaj_z_pliku.h"
#include "getopt.h"

char *pomoc="\n-x [szer] -y [wys] -i [ilosc_generacji] -z [ckgz] -f [zapis] -F [odczyt] -r [rozmiar_obrazu]\n"
"\nPOMOC\n"
"\nszer	szerokość siatki na, której program ma operować\n" 
"wys	wysokość siatki na, której program ma operować\n" 
"ilosc_generacji	ilosc generacji jaka ma zostać przeprowadzona\n"
"ckgz	częstotliwość zapisu generacji w formacie .bmp\n"
"zapis	nazwa pliku do, którego ma zostać zapisana ostatnia generacja\n"
"odczyt	nazwa pliku z, którego ma zostać pobrana genracja początkowa\n"
"rozmiar_obrazu	rozmiar obrazów jakie są tworzone\n"
"\nDostępne gotowe obiekty w pliku obiekty:\n"
"szybowiec.txt\n"
"dzialo.txt\n"
"Coeship.txt\n";

int main(int argc, char **argv){
	opcje opcje_m;
	opcje_m.szerokosc_siatki=0;
	opcje_m.wysokosc_siatki=0;
	opcje_m.ilosc_generacji=0;
	opcje_m.co_ktora_generacja_zapis=0;
	opcje_m.plik_odczyt=NULL;
	opcje_m.plik_zapis=NULL;
	opcje_m.rozmiar_obrazu=0;

	char *nazwa=argv[0];
	int opt;
	while((opt=getopt(argc,argv,"x:y:i:z:f:F:r:")) !=-1){
		switch(opt){
			case 'x':
				opcje_m.szerokosc_siatki=atoi(optarg);
				break;
			case 'y':
				opcje_m.wysokosc_siatki=atoi(optarg);
				break;
			case 'i':
				opcje_m.ilosc_generacji=atoi(optarg);
				break;
			case 'z':
				opcje_m.co_ktora_generacja_zapis=atoi(optarg);
				break;
			case 'f':
				opcje_m.plik_zapis=optarg;
				break;
			case 'F':
				opcje_m.plik_odczyt=optarg;
				break;
			case 'r':
				opcje_m.rozmiar_obrazu=atoi(optarg);
				break;

			default:
				fprintf(stderr,pomoc,nazwa);
				return (EXIT_FAILURE);
		}
	}
	if(optind<argc|| argc==1){

		fprintf(stderr,"\nBłąd parametrów!\n");
		for(;optind<argc;optind++)
			fprintf(stderr,"\t\"%s\\n",argv[optind]);
		fprintf(stderr,"\n");
		fprintf(stderr,pomoc,nazwa);

	}
	if(opcje_m.szerokosc_siatki <=0){
		fprintf(stderr,"\nArgument x wymaga wartości dodatniej, niezerowej\n");
		return EXIT_FAILURE;
	}
	if(opcje_m.wysokosc_siatki <=0){
		fprintf(stderr,"\nArgument y wymaga wartości dodatniej, niezerowej\n");
		return EXIT_FAILURE;
	}

	if(opcje_m.ilosc_generacji<=0){
		fprintf(stderr,"\nArgument i wymaga wartości dodatniej, niezerowej\n");
		return EXIT_FAILURE;
	}
	if(opcje_m.co_ktora_generacja_zapis<=0){
		fprintf(stderr,"\nArgument z wymaga wartości dodatniej, niezerowej\n");
		return EXIT_FAILURE;
	}
	if(opcje_m.plik_odczyt==NULL){
		fprintf(stderr,"\nArgument F wymaga nazwy pliku formatu .txt\n");
		return EXIT_FAILURE;
	}
	if(opcje_m.rozmiar_obrazu<=0){
		fprintf(stderr,"\nArgument r wymaga wartości dodatniej, niezerowej\n");
		return EXIT_FAILURE;
	}
	siatka pole;
	siatka *wsk=&pole;
	gotowa_siatka(wsk, opcje_m.szerokosc_siatki,opcje_m.wysokosc_siatki);	
	czytaj_z_pliku(opcje_m.plik_odczyt, wsk);
	generator(wsk,opcje_m);

	free(wsk->tab);	
	free(wsk->temp);
	return 0;
}
