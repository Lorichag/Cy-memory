
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
  char name[30];
  char ancient_weapon;
  int x; //Sert à gérer la position du personnage
  int y;
  int xstart; // les coordonnées de débart (utile pour la fonction retour)
  int ystart;
  int turn;
  char marker; // la représentation du personnage dans la console
  char weapon; // l'arme qu'il va utiliser pour le tour
  char stuff[2]; /*l'inventaire du personnage (son arme antique et le coffre s'il les a)*/
}Hero;

void display2(char tab[ROW][COL]);

void display(char tab[ROW][COL],Hero j,char tab2[ROW][COL]);

void build(char tab[ROW][COL]);

void spawn(char tab[ROW][COL],char tabmob[25]);

void reset(char tab[ROW][COL],char tab2[ROW][COL]);

int banmove(Hero j,int dep,char tab[ROW][COL]);

Hero move(Hero j,char tab[ROW][COL]);

Hero back(Hero j,char tab[ROW][COL]);

Hero fight(Hero j,char tab[ROW][COL]);

Hero choiceW(Hero j);

Hero ancient(Hero j,char tab[ROW][COL]);

Hero event(Hero j,char tab[ROW][COL],char tab2[ROW][COL],char tabdeb[ROW][COL]);

Hero trap(Hero j,char tab[ROW][COL]);

Hero turn(Hero j,char tab[ROW][COL],char tabmob[25],char tab2[ROW][COL],char tabdeb[ROW][COL]);

int game(Hero j1,Hero j2,Hero j3,Hero j4,char tab[ROW][COL],char tabmob[25],char tab2[ROW][COL]);

void vide_buffer();


#endif
