#include "fonctions.h"

		

int main(){
  int nbjoueur,perso1,perso2,perso3,perso4,verif;//variables qui compte le nombre de joueur et le perso choisi par chaque joueur
  printf("Saisir le nombre de joueur(entre 2 et 4): \n");
  verif=scanf("%d",&nbjoueur);
  vide_buffer();
  printf("\n");
  while(nbjoueur<2 || nbjoueur>4 || verif!=1){//Si le nombre saisi n'est pas 2,3 ou 4
    printf("Erreur de saisie \n");
    printf("Veuillez ressaisir le nombre de joueur(entre 2 et 4): \n");
    verif=scanf("%d",&nbjoueur);
    vide_buffer();
    printf("\n");
  }
  Hero j1,j2,j3,j4;//Les variables pour gérer les différents joueurs
  printf("Joueur 1 saisissez le chiffre du personnage que voulez incarner:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
  verif=scanf("%d",&perso1);
  vide_buffer();
  printf("\n");
  while(perso1<1 || perso1>4 || verif!=1){//Si le nombre saisi ne correspond pas à un personnage
    printf("Erreur de saisie \n");
    printf("Veuillez ressaisir le chiffre du personnage que voulez incarner:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
    verif=scanf("%d",&perso1);
    vide_buffer();
    printf("\n");
  }
  printf("Saissisez votre nom: \n");
  verif=scanf("%s",j1.nom);
  vide_buffer();
  printf("\n");
  while(verif!=1){
    printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
    verif=scanf("%s",j1.nom);
    vide_buffer();
    printf("\n");
  }
  switch (perso1){//On choisi le marqueur et l'arme à récupérer en fonction du perso choisi
    case 1:
      j1.marqueur='G';
      j1.arme_ant='e';
      break;
    case 2:
      j1.marqueur='R';
      j1.arme_ant='b';
      break;
    case 3:
      j1.marqueur='V';
      j1.arme_ant='d';
      break;
    case 4:
      j1.marqueur='M';
      j1.arme_ant='g';
      break;
    }
  //On initialise les différents paramètres nécéssaire
  j1.xdeb=0;  //Les coordonnées de départ
  j1.ydeb=4;
  j1.x=j1.xdeb; //Les coordonnées de la position 
  j1.y=j1.ydeb;
  j1.inv[0]='v'; // L'inventaire du personnage
  j1.inv[1]='v'; // v comme vide
  printf("Joueur 2 saisissez le chiffre du personnage que voulez incarner mais pas le même que le joueur1:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
  verif=scanf("%d",&perso2);
  vide_buffer();
  printf("\n");
  while(perso2<1 || perso2>4 || perso2==perso1 || verif!=1){ //Pareil que tout à l'heure mais on vérifie également que le perso choisi et différent du premier
    printf("Erreur de saisie \n");
    printf("Veuillez ressaisir le chiffre du personnage que voulez incarner mais pas le même que le joueur1:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
    verif=scanf("%d",&perso2);
    vide_buffer();
    printf("\n");
  }
  printf("Saissisez votre nom: \n");
  verif=scanf("%s",j2.nom);
  vide_buffer();
  printf("\n");
  while(verif!=1){
    printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
    verif=scanf("%s",j2.nom);
    vide_buffer();
    printf("\n");
  }
  switch (perso2){
    case 1:
      j2.marqueur='G';
      j2.arme_ant='e';
      break;
    case 2:
      j2.marqueur='R';
      j2.arme_ant='b';
      break;
    case 3:
      j2.marqueur='V';
      j2.arme_ant='d';
      break;
    case 4:
      j2.marqueur='M';
      j2.arme_ant='g';
      break;
    }
  j2.xdeb=2;// La position de départ du deuxieme joueur
  j2.ydeb=0;
  j2.x=j2.xdeb;
  j2.y=j2.ydeb;
  j2.inv[0]='v'; // v comme vide
  j2.inv[1]='v';
  if(nbjoueur==2){// Si il y a que deux joueurs
    j3.marqueur='v'; // On intialise marqueur à vide pour savoir si il y a un  troisième joueur lorsqu'on appelle la fonction jeu 
    j3.inv[0]='v'; // v comme vide
    j3.inv[1]='v';
    j4.marqueur='v'; // On intialise marqueur à vide pour savoir si il y a un  quatrième joueur lorsqu'on appelle la fonction jeu 
    j4.inv[0]='v'; // v comme vide
    j4.inv[1]='v';
  }
  else{
    printf("Joueur 3 saisissez le chiffre du personnage que voulez incarner mais différent des joueur 1 et 2:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
    verif=scanf("%d",&perso3);
    vide_buffer();
    printf("\n");
    while(perso3<1 || perso3>4 || perso3==perso1 || perso3==perso2 || verif!=1){// On vérifie que le personnage choisi soit différent des joueurs précédents 
      printf("Erreur de saisie \n");
      printf("Veuillez ressaisir le chiffre du personnage que voulez incarner mais différent des joueur 1 et 2:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
      verif=scanf("%d",&perso3);
      vide_buffer();
      printf("\n");
  }
    printf("Saissisez votre nom: \n");
    verif=scanf("%s",j3.nom);
    vide_buffer();
    printf("\n");
    while(verif!=1){
      printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
      verif=scanf("%s",j3.nom);
      vide_buffer();
      printf("\n");
    }
    switch (perso3){
      case 1:
        j3.marqueur='G';
        j3.arme_ant='e';
        break;
      case 2:
        j3.marqueur='R';
        j3.arme_ant='b';
        break;
      case 3:
        j3.marqueur='V';
        j3.arme_ant='d';
        break;
      case 4:
        j3.marqueur='M';
        j3.arme_ant='g';
        break;
        }
    j3.xdeb=6;// Coordonnées de départ du 3eme joueur
    j3.ydeb=2;
    j3.x=j3.xdeb;
    j3.y=j3.ydeb;
    j3.inv[0]='v'; // v comme vide
    j3.inv[1]='v';
    if(nbjoueur==3){ // Si il y a que 3 joueurs
      j4.marqueur='v'; // On intialise marqueur à vide pour savoir si il y a un  quatrième joueur lorsqu'on appelle la fonction jeu 
      j4.inv[0]='v'; // v comme vide
      j4.inv[1]='v';
    } 
    else{
      printf("Joueur 4 saisissez le chiffre du personnage restant:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
      verif=scanf("%d",&perso4);
      vide_buffer();
      printf("\n");
      while(perso4<1 || perso4>4 || perso4==perso1 || perso4==perso2 || perso4==perso3 || verif!=1){ // Le dernier joueur doit choisir le dernier perso
        printf("Erreur de saisie \n");
        printf("Veuillez ressaisir le chiffre du personnage                   restant:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
        verif=scanf("%d",&perso4);
        vide_buffer();
        printf("\n");
  }
      printf("Saissisez votre nom: \n");
      verif=scanf("%s",j4.nom);
      vide_buffer();
      printf("\n");
      while(verif!=1){
        printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
        verif=scanf("%s",j4.nom);
        vide_buffer();
        printf("\n");
      }
      switch (perso4){
        case 1:
          j4.marqueur='G';
          j4.arme_ant='e';
          break;
        case 2:
          j4.marqueur='R';
          j4.arme_ant='b';
          break;
        case 3:
          j4.marqueur='V';
          j4.arme_ant='d';
          break;
        case 4:
          j4.marqueur='M';
          j4.arme_ant='g';
          break;
      }
      j4.xdeb=4; //Coordonnées de départ du quatrième joueur 
      j4.ydeb=6;
      j4.x=j4.xdeb;
      j4.y=j4.ydeb;
      j4.inv[0]='v'; // v comme vide
      j4.inv[1]='v';
    }    
  }
  srand(time(NULL));
  char tab[ROW][COL];
  char tab2[7][7];
  char tabmob[25] ={'Z','Z','Z','Z','H','H','H','H','B','B','B','B','T','T','T','T','C','C','o','o','P','b','d','e','g'};
  jeu(j1,j2,j3,j4,tab,tabmob,tab2);
  return 0;
}

   /* couleur(33)
	printf("🛡\n"); //Guerrier
	printf("🗝\n"); // voleur
	printf("⚚\n"); //magicien
	printf("➳\n");  //Ranger
	
	
	printf("▥\n"); //case 
	printf("▧\n"); //case
	printf("□\n");  //case vide
	

	printf("🕮\n"); //grimoire
	printf("⚔ \n");  //épée
	printf("🗡\n");  //Dague
	printf("⚕\n");  //Baton
	
	printf("☣\n");  //zombie	
	printf("〠\n");  //Troll
	printf("☬\n");  //Harpie
	printf("ఋ\n");  //Basilic
	
	printf("۝\n");  //Portail
	printf("۩\n");  //Totem

	
	printf("▣ \n"); //coffre
	
	couleur(7)  //échanger la couleur du fond et du texte


*/




