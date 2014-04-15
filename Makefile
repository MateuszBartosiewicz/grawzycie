CFLAGS= -Wall -ansi -pedantic

objects= konwertowanie.o generowanie.o main.o\
przygotowanie_siatki.o zasady.o drukuj_BMP.o\
czytaj_z_pliku.o zapis_do_pliku.o

objects2= konwertowanie.h siatka.h

GRA_W_ZYCIE: $(objects) 
	gcc -o GRA_W_ZYCIE $(objects) bmplib/bmplib.a
	
zasady.o: zasady.c
	gcc -c $^

konwertowanie.o: konwertowanie.c 
	gcc -c $^

zapis_do_pliku.o: zapis_do_pliku.c   
	gcc -c $^

generowanie.o: generowanie.c zasady.h drukuj_BMP.h zapis_do_pliku.h
	gcc -c generowanie.c

main.o: main.c czytaj_z_pliku.h 
	gcc -c main.c   

przygotowanie_siatki.o: przygotowanie_siatki.c $(objects2)
	gcc -c przygotowanie_siatki.c

drukuj_BMP.o: drukuj_BMP.c bmplib/BMP.h  konwertowanie.h
	gcc -c drukuj_BMP.c

czytaj_z_pliku.o: czytaj_z_pliku.c $(objects2)  
	gcc -c czytaj_z_pliku.c 

.PHONY: clean 

clean: 
	rm -f *.o
clean_BMP:
	rm -f obrazy_BMP/generacja_nr_*.bmp

