#include "siatka.h"
#include "konwertowanie.h"
#include "zasady.h"
#include "drukuj_BMP.h"
#include "zapis_do_pliku.h"
#include <stdlib.h>

typedef struct{
	int rozmiar_obrazu;
	int szerokosc_siatki;//szerokość siatki
	int wysokosc_siatki;//wysokość siatki
	int ilosc_generacji;
	int co_ktora_generacja_zapis;//co którą genrację należy zapisać w postaci BMP

	char *plik_odczyt;//nazwa pliku do krórego ma zostać zapisana ostatnia generacja
	char *plik_zapis;
}opcje;

int licz_zywe(int x, int y, siatka *gen);
void generator(siatka *gen, opcje opcje_m);
void porownaj_stany(int x, int y, siatka *gen, int ilosc_zywych);
void zamiana_tablic(siatka *gen);
