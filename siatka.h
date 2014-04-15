#ifndef SIATKA_H
#define SIATKA_H
#include<stdlib.h>
#include<stdio.h>
#define ZYWA 1
#define MARTWA 0
#define SZER gen->szer
#define WYS gen->wys
typedef struct{
	int *tab;//siatka główna do której zapiszę dane z pliku na początku
	int *temp;//siatka pomocnicz, do zapisu generacji nastepujących po sobie
	int szer;//szerokosć siatki na jakiej operuje
	int wys;//wysokość siatki na jakiej operuje
}siatka;

#endif

