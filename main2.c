#include "fonctions.h"
/*                          
  ____    _                                                      
 |  _ \  (_)                                                     
 | |_) |  _    ___   _ __   __   __   ___   _ __    _   _    ___ 
 |  _ <  | |  / _ \ | '_ \  \ \ / /  / _ \ | '_ \  | | | |  / _ \
 | |_) | | | |  __/ | | | |  \ V /  |  __/ | | | | | |_| | |  __/
 |____/  |_|  \___| |_| |_|   \_/    \___| |_| |_|  \__,_|  \___|
                                          
	*/	

int main(){
  int nbplayer,character1,character2,character3,character4,check;//variables qui compte le nombre de joueur et le perso choisi par chaque joueur
  couleur(31)
  printf("__________________________________________________ \n");
  couleur(5)
  printf("           Bienvenue sur le Memo-RPG        \n");
  couleur(0)
  printf("\n");
//  printf("Les règles sont simples trouver le coffre et votre arme magique sur le plateau en faisant attention de se souvenir où se trouve les monstres et autre évenement.\n");           
  printf("           Saisir le nombre de joueur: \n");
  printf("           2 joueur  3 joueur 4 joueur\n");
  printf("\n");
  printf("\n");
  printf("              Le but est simple\n");
  printf("    Trouver votre arme magique, votre coffre \n");
  printf("Et retenez les cases sur lesquelles vous marchez\n");
  couleur(31)
  printf("___________________________________________________\n");
  couleur(0)
  printf("Si vous voulez afficher les scores saisissez 1 \n");
  check=scanf("%d",&nbplayer);
  vide_buffer();
  printf("\n");
  if(nbplayer==1){
    char c[50];
    FILE *f=fopen("scores.txt","r");
    if(f==NULL){
      printf("impossible d'ouvrir le fichier");
    }
    else{
      while(fgets(c,sizeof c,f)!=NULL){
        printf("%s",c);
      }
      fclose(f);
      printf("\n");
    }
  }
  while(nbplayer<2 || nbplayer>4 || check!=1){//Si le nombre saisi n'est pas 2,3 ou 4
    if(nbplayer!=1){
      printf("Erreur de saisie \n");
    }
    printf("Veuillez ressaisir le nombre de joueur(entre 2 et 4): \n");
    check=scanf("%d",&nbplayer);
    vide_buffer();
    printf("\n");
  }
  Hero player1,player2,player3,player4;//Les variables pour gérer les différents joueurs
  printf("Joueur 1 saisissez le chiffre du personnage que voulez incarner:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
  check=scanf("%d",&character1);
  vide_buffer();
  printf("\n");
  while(character1<1 || character1>4 || check!=1){//Si le nombre saisi ne correspond pas à un personnage
    printf("Erreur de saisie \n");
    printf("Veuillez ressaisir le chiffre du personnage que voulez incarner:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
    check=scanf("%d",&character1);
    vide_buffer();
    printf("\n");
  }
  printf("Saissisez votre nom: \n");
  check=scanf("%s",player1.name);
  vide_buffer();
  printf("\n");
  while(check!=1){
    printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
    check=scanf("%s",player1.name);
    vide_buffer();
    printf("\n");
  }
  switch (character1){//On choisi le marqueur et l'arme à récupérer en fonction du perso choisi
    case 1:
      player1.marker='G';
      player1.ancient_weapon='e';
      break;
    case 2:
      player1.marker='R';
      player1.ancient_weapon='b';
      break;
    case 3:
      player1.marker='V';
      player1.ancient_weapon='d';
      break;
    case 4:
      player1.marker='M';
      player1.ancient_weapon='g';
      break;
    }
  //On initialise les différents paramètres nécéssaire
  player1.xstart=0;  //Les coordonnées de départ
  player1.ystart=4;
  player1.x=player1.xstart; //Les coordonnées de la position 
  player1.y=player1.ystart;
  player1.turn=0;
  player1.stuff[0]='v'; // L'inventaire du personnage
  player1.stuff[1]='v'; // v comme vide
  printf("Joueur 2 saisissez le chiffre du personnage que voulez incarner mais pas le même que le joueur1:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
  check=scanf("%d",&character2);
  vide_buffer();
  printf("\n");
  while(character2<1 || character2>4 || character2==character1 || check!=1){ //Pareil que tout à l'heure mais on vérifie également que le perso choisi et différent du premier
    printf("Erreur de saisie \n");
    printf("Veuillez ressaisir le chiffre du personnage que voulez incarner mais pas le même que le joueur1:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
    check=scanf("%d",&character2);
    vide_buffer();
    printf("\n");
  }
  printf("Saissisez votre nom: \n");
  check=scanf("%s",player2.name);
  vide_buffer();
  printf("\n");
  while(check!=1){
    printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
    check=scanf("%s",player2.name);
    vide_buffer();
    printf("\n");
  }
  switch (character2){
    case 1:
      player2.marker='G';
      player2.ancient_weapon='e';
      break;
    case 2:
      player2.marker='R';
      player2.ancient_weapon='b';
      break;
    case 3:
      player2.marker='V';
      player2.ancient_weapon='d';
      break;
    case 4:
      player2.marker='M';
      player2.ancient_weapon='g';
      break;
    }
  //On initialise les différents paramètres nécéssaire
  player2.xstart=2;  //Les coordonnées de départ
  player2.ystart=0;
  player2.x=player2.xstart; //Les coordonnées de la position 
  player2.y=player2.ystart;
  player2.turn=0;
  player2.stuff[0]='v'; // L'inventaire du personnage
  player2.stuff[1]='v';
  if(nbplayer==2){// Si il y a que deux joueurs
    player3.marker='v'; // On intialise marqueur à vide pour savoir si il y a un  troisième joueur lorsqu'on appelle la fonction jeu 
    player3.stuff[0]='v'; // v comme vide
    player3.stuff[1]='v';
    player4.marker='v'; // On intialise marqueur à vide pour savoir si il y a un  quatrième joueur lorsqu'on appelle la fonction jeu 
    player4.stuff[0]='v'; // v comme vide
    player4.stuff[1]='v';
  }
  else{
    printf("Joueur 3 saisissez le chiffre du personnage que voulez incarner mais différent des joueur 1 et 2:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
    check=scanf("%d",&character3);
    vide_buffer();
    printf("\n");
    while(character3<1 || character3>4 || character3==character1 || character3==character2 || check!=1){// On vérifie que le personnage choisi soit différent des joueurs précédents 
      printf("Erreur de saisie \n");
      printf("Veuillez ressaisir le chiffre du personnage que voulez incarner mais différent des joueur 1 et 2:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
      check=scanf("%d",&character3);
      vide_buffer();
      printf("\n");
  }
    printf("Saissisez votre nom: \n");
    check=scanf("%s",player3.name);
    vide_buffer();
    printf("\n");
    while(check!=1){
      printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
      check=scanf("%s",player3.name);
      vide_buffer();
      printf("\n");
    }
    switch (character3){
      case 1:
        player3.marker='G';
        player3.ancient_weapon='e';
        break;
      case 2:
        player3.marker='R';
        player3.ancient_weapon='b';
        break;
      case 3:
        player3.marker='V';
        player3.ancient_weapon='d';
        break;
      case 4:
        player3.marker='M';
        player3.ancient_weapon='g';
        break;
    }
    //On initialise les différents paramètres nécéssaire
    player3.xstart=6;  //Les coordonnées de départ
    player3.ystart=2;
    player3.x=player3.xstart; //Les coordonnées de la position 
    player3.y=player3.ystart;
    player3.turn=0;
    player3.stuff[0]='v'; // L'inventaire du personnage
    player3.stuff[1]='v';
    if(nbplayer==3){ // Si il y a que 3 joueurs
      player4.marker='v'; // On intialise marqueur à vide pour savoir si il y a un  quatrième joueur lorsqu'on appelle la fonction jeu 
      player4.stuff[0]='v'; // v comme vide
      player4.stuff[1]='v';
    } 
    else{
      printf("Joueur 4 saisissez le chiffre du personnage restant:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
      check=scanf("%d",&character4);
      vide_buffer();
      printf("\n");
      while(character4<1 || character4>4 || character4==character1 || character4==character2 || character4==character3 || check!=1){ // Le dernier joueur doit choisir le dernier perso
        printf("Erreur de saisie \n");
        printf("Veuillez ressaisir le chiffre du personnage                   restant:\n1:guerrier\n2:ranger\n3:voleur\n4:magicien\n");
        check=scanf("%d",&character4);
        vide_buffer();
        printf("\n");
      }
      printf("Saissisez votre nom: \n");
      check=scanf("%s",player4.name);
      vide_buffer();
      printf("\n");
      while(check!=1){
        printf("Veuillez resaissir votre nom (30 caractère au maximum): \n");
        check=scanf("%s",player4.name);
        vide_buffer();
        printf("\n");
      }
      switch (character4){
        case 1:
          player4.marker='G';
          player4.ancient_weapon='e';
          break;
        case 2:
          player4.marker='R';
          player4.ancient_weapon='b';
          break;
        case 3:
          player4.marker='V';
          player4.ancient_weapon='d';
          break;
        case 4:
          player4.marker='M';
          player4.ancient_weapon='g';
          break;
      }
      //On initialise les différents paramètres nécéssaire
      player4.xstart=4;  //Les coordonnées de départ
      player4.ystart=6;
      player4.x=player4.xstart; //Les coordonnées de la position 
      player4.y=player4.ystart;
      player4.turn=0;
      player4.stuff[0]='v'; // L'inventaire du personnage
      player4.stuff[1]='v';
    }    
  }
  srand(time(NULL));
  char tab[ROW][COL];
  char tab2[7][7];
  char newgame[3];
  printf("Les différents éléments du labyrinthe sont: \n🧟 = Zombie \n 🦎 = Basilic \n 🧚 = Harpie \n 👹 = Troll \n 🏺 = Totem \n ⭖  = Portail \n Arme:\n 🗡 = Dague \n ⚔ = épée \n 🦯 = Baton \n 📕 = Grimoire");
  printf("\n");
  sleep(3);
  do{
    char tabmob[25] ={'Z','Z','Z','Z','H','H','H','H','B','B','B','B','T','T','T','T','C','C','o','o','P','b','d','e','g'};
    game(player1,player2,player3,player4,tab,tabmob,tab2);
    printf("Voulez vous recommencer une partie avec les mêmes personnages(si oui     tapez oui) ? \n");
    check=scanf("%s",newgame);
    vide_buffer();
    printf("\n");
    while(check!=1){
      printf("Voulez vous recommencer une partie avec les mêmes personnages(si oui tapez oui) ? \n");
      check=scanf("%s",newgame);
      vide_buffer();
      printf("\n");
    }
  }while(newgame[0]=='o' && newgame[1]=='u' && newgame[2]=='i');
  main();
  return 0;
}
