#ifndef FONCTIONS
#define FONCTIONS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define ROW 7
#define COL 7

#define couleur(param)\
	printf("\033[%dm",param); 


//constructeur de hero
typedef struct{ // la structure pour gérer le personnage
  char nom[30];
  char arme_ant;
  int x; //Sert à gérer la position du personnage
  int y;
  int xdeb; // les coordonnées de débart (utile pour la fonction retour)
  int ydeb;
  char marqueur; // la représentation du personnage dans la console
  char arme; // l'arme qu'il va utiliser pour le tour
  char inv[2]; /*l'inventaire du personnage (son arme antique et le coffre s'il les a)*/
}Hero;

void affichage2(char tab[ROW][COL]);

void affichage(char tab[ROW][COL],Hero j,char tab2[ROW][COL]);

void constru(char tab[ROW][COL]);

void spawn(char tab[ROW][COL],char tabmob[25]);

void reset(char tab[ROW][COL],char tab2[ROW][COL]);

int dep_interdit(Hero j,int dep,char tab[ROW][COL]);

Hero deplacement(Hero j,char tab[ROW][COL]);

Hero retour(Hero j,char tab[ROW][COL]);

Hero combat(Hero j,char tab[ROW][COL]);

Hero choixA(Hero j);

Hero armant(Hero j,char tab[ROW][COL]);

Hero event(Hero j,char tab[ROW][COL],char tab2[ROW][COL],char tabdeb[ROW][COL]);

Hero tour(Hero j,char tab[ROW][COL],char tabmob[25],char tab2[ROW][COL],char tabdeb[ROW][COL]);

int jeu(Hero j1,Hero j2,Hero j3,Hero j4,char tab[ROW][COL],char tabmob[25],char tab2[ROW][COL]);

void vide_buffer();


#endif
