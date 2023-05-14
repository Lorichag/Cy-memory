#include "fonctions.h"


void vide_buffer(){
	while(getchar()!= '\n'){
	}
}

void affichage2(char tab[ROW][COL]){       //Affiche le terrain avec les évenement
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
		    if(tab[i][j]=='Z'|| tab[i][j]=='H' || tab[i][j]=='T'|| tab[i][j]=='B'){
		        couleur(31)                             //Affiche les monstres
		        printf(" %c ",tab[i][j]);
		        couleur(0)
		    }
		    else if(tab[i][j]=='o'|| tab[i][j]=='P'){
		        couleur(35)                             //Affiche les Totems et le portail
		        printf(" %c ",tab[i][j]);
		        couleur(0)
		    }
		    else if(tab[i][j]=='C'){
		        couleur(33)                             //Affiche les Coffre
		        printf(" %c ",tab[i][j]);
		        couleur(0)
		    }
		    else if(tab[i][j]==' '){
		        printf(" %c ",tab[i][j]);

		    }
		    else{                                       //Affiche le reste
			    printf(" %c ",tab[i][j]);
		    }
		}
		printf("\n");
	}

}	

void affichage(char tab[ROW][COL],Hero j,char tab2[ROW][COL]){         //c'est pareil qu'avant j'au juste remplacer le M par le marqueur du personnage
	int i,k,colo;
  int dv=0;
	colo=0;                                
	for(i=0;i<ROW;i++){
		for(k=0;k<COL;k++){
		    if(i==j.x && k==j.y){
          if(tab[j.x][j.y]==tab2[j.x][j.y]){
            dv=1;
          }
		    	tab[j.x][j.y]=tab2[j.x][j.y];
		    	if(tab[i][k]=='Z'|| tab[i][k]=='H' || tab[i][k]=='T'|| tab[i][k]=='B'){
		        	couleur(31)                             //Affiche les monstres
		        	printf(" %c ",tab[i][k]);
		        	couleur(0)
		    	}
		    	else if(tab[i][k]=='o'|| tab[i][k]=='P'){
				    couleur(35)                             //Affiche les Totems et le portail
				    printf(" %c ",tab[i][k]);
				    couleur(0)
			     }
          else if(tab[i][k]==' ' || tab[i][k]=='X' || dv==1){
              couleur(32)
		        	printf(" %c ",j.marqueur);
              couleur(0)
		    	}
		    	else if(tab[i][k]=='C'){
				    couleur(33)                             //Affiche les Coffre
				    printf(" %c ",tab[i][k]);
				    couleur(0)
		    	}
		    	else{                                       //Affiche le reste
			    printf(" %c ",tab[i][k]);
		    	}
		    }
        else{
			     printf(" %c ",tab[i][k]);
        }
		}
		printf("\n");
	}
}



void constru(char tab[ROW][COL]){           //Construit le terrain
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
           if ((i==0 &&j==COL-3) || (i==ROW-3 && j==COL-1) || (i==ROW-1 && j==2) || (i==2 && j==0)) //Construit le point de départ des joueurs
                tab[i][j]='X';
            
            else if(i==0 || j==0 || j==ROW-1 || i==COL-1)  //Construit les bores vide du terrain
                    tab[i][j]=' ';
            else{                           //Construit le terrain
                tab[i][j]='o';
                }
            
        }

    }
    
}




//Faire le spawn des monstre et autre
void spawn(char tab[ROW][COL],char tabmob[25]){
    int i,j,a;
    for(int i=0;i<=6;i++){
        for(int j=0;j<=6;j++){
           if ((i==0 &&j==COL-3) || (i==ROW-3 && j==COL-1) || (i==ROW-1 && j==2) || (i==2 && j==0)) 
                tab[i][j]='X';//Les évenement sont placé aléatoirement dans le second tableaux
            else if(i==0 || j==0 || j==6 || i==6)  //Construit les bores vide du terrain
                    tab[i][j]=' ';

            else{
              a=rand()%25;
              while(tabmob[a]=='v'){
                a=rand()%25;
              }
              while((i==1 && j==4 || i==2 && j==1 || i==5 && j==2 || i==4 && j==5) && tabmob[a] == 'o'){
              	a=rand()%25;
              }
              tab[i][j]=tabmob[a];
              tabmob[a]='v';
            }
        }
    }
  printf("\n");

}

void reset(char tab[ROW][COL],char tab2[ROW][COL]){ // reset la map quand un joueur fini son tour
    for(int i=0;i<7;i++){
      for(int j=0;j<7;j++){
      tab2[i][j]=tab[i][j];
    }
  }
}


int dep_interdit(Hero j,int dep,char tab[ROW][COL]){
  if((dep==1 && (j.y==0 || tab[j.x][j.y-1]!='o' ))||(dep==2 && (j.x==0 || tab[j.x-1][j.y]!='o'))||( dep==3 && (tab[j.x+1][j.y]!='o' || j.x==6))||( dep==4 && (tab[j.x][j.y+1]!='o' || j.y==6))){  // on teste si on sort du tableau ou si on sort du labyrinthe
     printf("Il est impossible d'aller par là ! \n");
     return 0; 
  }
  return 1;
}

Hero deplacement(Hero j,char tab[ROW][COL]){
  // La fonction pour déplacer le joueur
  int pose;
  int verif;
  printf("Choisissez où vous voulez allez: \n");
  printf("1=gauche,2=haut,3=bas,4=droite\n");
  verif = scanf("%d",&pose);
  vide_buffer();
  while(dep_interdit(j,pose,tab)==0 || verif != 1){
    if(verif != 1){
      printf("Erreur de saisie \n");
    }
    printf("Choisissez où vous voulez allez: \n");
    printf("1=gauche,2=haut,3=bas,4=droite\n");
    verif = scanf("%d",&pose);
    vide_buffer();
  }// On regarde si le déplacement est valide
  switch(pose){
    case 1:
      j.y--;
      break;
    case 2:
      j.x--;
      break;
    case 3:
      j.x++;
      break;
    case 4:
      j.y++;
      break;
    default:
      printf("Erreur de saisie \n");
      deplacement(j,tab);
      break;
  }
  
  return j;
}

Hero retour(Hero j,char tab[ROW][COL]){ //Lorsque le personnage meurt ou si il tombe sur unn totem on le renvoie à sa position initiale et on vide son inventaire
  j.x=j.xdeb;
  j.y=j.ydeb;
  j.inv[0]='v';
  j.inv[1]='v';
  return j;
}

Hero combat(Hero j,char tab[ROW][COL]){
// La fonction pour gérer le cas où tu tombe sur un monstre
  if(tab[j.x][j.y]=='Z'){ //cas zombie
    if(j.arme=='t'){
      printf("Vous avez vaincu le zombie \n");
      tab[j.x][j.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      j=retour(j,tab);
    }
  }
  else if(tab[j.x][j.y]=='H'){ //cas harpie
    if(j.arme=='a'){
      printf("Vous avez vaincu la harpie \n");
      tab[j.x][j.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      j=retour(j,tab);
    }
  }
  else if(tab[j.x][j.y]=='B'){ //cas basilic
    if(j.arme=='m'){
      printf("Vous avez vaincu le basilic \n");
      tab[j.x][j.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      j=retour(j,tab);
    }
  }
  else if(tab[j.x][j.y]=='T'){ //cas troll
    if(j.arme=='h'){
      printf("Vous avez vaincu le troll \n");
      tab[j.x][j.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      j=retour(j,tab);
    }
  }
  else if(tab[j.x][j.y]=='C'){ //cas coffre
    if(j.inv[0]!='C'){
      printf("Bravo vous avez trouver le coffre ! \n");
      j.inv[0]='C'; //On rempli l'iventaire
      tab[j.x][j.y]=' ';
    }
  }
return j;
}

Hero choixA(Hero j){ // Choix de l'arme
    int choix;
    int verif;
    printf("choisisser l'arme que vous voulez utiliser: \n");
    printf("1 = Torche (Tue le Zombie) \n2 = Miroir (Tue le Basilic)\n3 = Hache (Tue le Troll)\n4 = Arc (Tue la Harpie)\n");
    verif = scanf("%d",&choix);
    vide_buffer();
    while(verif!=1){
    	printf("Erreur de saisie \n");
    	printf("choisisser l'arme que vous voulez utiliser: \n");
	printf("1 = Torche (Tue le Zombie) \n2 = Miroir (Tue le Basilic)\n3 = Hache (Tue le Troll)\n4 = Arc (Tue la Harpie)\n");
	verif = scanf("%d",&choix);
	vide_buffer();
    }
    switch(choix){
    case 1: 
      j.arme = 't';
      break;
    case 2:
      j.arme='m' ;
      break;
    case 3:
      j.arme='h';
      break;
    case 4:
      j.arme='a';
      break;
    default:
      printf("Mauvaise saisi \n");
      choixA(j);
      break;
  }
  return j;
}
Hero armant(Hero j,char tab[ROW][COL]){//Quand le joueur tombe sur une arme antique
  if(j.arme_ant==tab[j.x][j.y]){
    printf("Bravo vous avez trouvé votre arme antique \n");
    j.inv[1]=tab[j.x][j.y]; //On rempli l'iventaire
    tab[j.x][j.y]=' ';
  }
  return j;
}

Hero event(Hero j,char tab[ROW][COL],char tab2[ROW][COL],char tabdeb[ROW][COL]){// Si le personnage tombe sur un portail, un totem ou une arme antique
  int x,y,verif1,verif2;
  char ret[1][1];
  
  if (tab2[j.x][j.y]=='P'){                           //A faire (condition si la case a été  découverte)
      printf("Oh un portail choisissez l'emplacement ou vous voulez vous téleporter \n" );
      printf("  |1|2|3|4|5|\n1 |.|.|.|.|.|\n2 |.|.|.|.|.|\n3 |.|.|.|.|.|\n4 |.|.|.|.|.|\n5 |.|.|.|.|.|\n ");
        printf("Entrer la coordonnée en x (1,2...) \n" );
        verif1=scanf("%d",&x);
        vide_buffer();
        printf("Entrer la coordonnée en y (1,2...) \n" );
        verif2=scanf(" %d",&y);
        vide_buffer();
      while((x>5 || x<1 && y<1 || y>5 ) || verif1 !=1 || verif2 !=1){
      	printf("Erreur de saisie \n" );
        printf("Entrer la coordonnée en x (1,2...) \n" );
        verif1=scanf("%d",&x);
        vide_buffer();
        printf("Entrer la coordonnée en y (1,2...) \n" );
        verif2=scanf(" %d",&y);
        vide_buffer();
      }
      tab[j.x][j.y]=' ';
      tab2[j.x][j.y]=' ';
      j.x=x;
      j.y=y;
      affichage(tab,j,tab2);
      j=combat(j,tab2); //On déclenche l'évenement de la case où on atteri
      j=event(j,tab,tab2,tabdeb);
    }    

  else if (tab2[j.x][j.y]=='o'){
      printf("Oh un totem choisissez l'emplacement ou vous voulez le déplacer mais pas devant la base des autres\n" );
      printf("  |1|2|3|4|5|\n1 |.|.|.|x|.|\n2 |x|.|.|.|.|\n3 |.|.|.|.|.|\n4 |.|.|.|.|x|\n5 |.|x|.|.|.|\n ");
      printf("Entrer la coordonnée en x (1,2...) \n" );            
      verif1=scanf("%d",&x);
      vide_buffer();
      printf("Entrer la coordonnée en y (1,2...) \n" );
      verif2=scanf(" %d",&y);
      vide_buffer();
      while((x>5 || x<1 && y<1 || y>5 || x==1 && y==4 || x==2 && y==1 || x==5 && y==2 || x==4 && y==5) || verif1 != 1 || verif2 != 1){
        printf("Erreur de saisie \n" );
        printf("Entrer la coordonnée en x (1,2...) \n" );            
        verif1=scanf("%d",&x);
        vide_buffer();
        printf("Entrer la coordonnée en y (1,2...) \n" );
        verif2=scanf(" %d",&y);
        vide_buffer();
        }  
      ret[0][0]=tabdeb[j.x][j.y];   // modifie le plateau d'origine pour pouvoir reset avec le totem au bon endroit
      tabdeb[j.x][j.y]=tabdeb[x][y];
      tabdeb[x][y]=ret[0][0];
      j=retour(j,tab2);
    }
  else if (tab2[j.x][j.y]=='e' || tab2[j.x][j.y]=='g' || tab2[j.x][j.y]=='d' || tab2[j.x][j.y]=='b'){
      j=armant(j,tab2);
    }
return j;
  }

int gagner(Hero j,char tab2[ROW][COL],char tabdeb[ROW][COL]){ //Fin de la partie
  if(j.inv[0]!='v' && j.inv[1]!='v'){
  	reset(tabdeb,tab2);
  	affichage2(tab2);
  	printf("Bravo %s vous avez gagné \n",j.nom);
  	return 1;
  }
return 0;
}


Hero tour(Hero j,char tab[ROW][COL],char tabmob[25],char tab2[7][7],char tabdeb[ROW][COL]){//Gère le tour d'un joueur
  do{
    affichage(tab,j,tab2);
    affichage2(tab2);
    j=choixA(j);
    j=deplacement(j,tab);
    affichage(tab,j,tab2);
    j=combat(j,tab2);
    j=event(j,tab,tab2,tabdeb);
  }while((j.inv[0]=='v'||j.inv[1]=='v')&&(j.x!=j.xdeb || j.y!=j.ydeb));
return j;
}

int jeu(Hero j1,Hero j2,Hero j3,Hero j4, char tab[ROW][COL],char tabmob[25],char tab2[7][7]){
  // Gère une partie de jeu
  char tabdeb[7][7];
  char tabmap[7][7];
  constru(tab);
  spawn(tab2,tabmob);
  reset(tab2,tabdeb);
  reset(tab,tabmap);

  do{
    printf("%s c'est à vous de jouer. \n",j1.nom);
    j1=tour(j1,tab,tabmob,tab2,tabdeb);
    if(gagner(j1,tab2,tabdeb)){
      return 1;
    }
    reset(tabdeb,tab2);
    reset(tabmap,tab);
    printf("%s c'est à vous de jouer. \n",j2.nom);           
    j2=tour(j2,tab,tabmob,tab2,tabdeb);
    if(gagner(j2,tab2,tabdeb)){
      return 1;
    }
    reset(tabdeb,tab2);
    reset(tabmap,tab);
    if(j3.marqueur!='v'){
      printf("%s c'est à vous de jouer. \n",j3.nom);           
      j3=tour(j3,tab,tabmob,tab2,tabdeb);
      if(gagner(j3,tab2,tabdeb)){
        return 1;
      }
    }
    if(j4.marqueur!='v'){
      printf("%s c'est à vous de jouer. \n",j4.nom);           
      j4=tour(j4,tab,tabmob,tab2,tabdeb);
      if(gagner(j4,tab2,tabdeb)){
        return 1;
      }
    }
  }while((j1.inv[0]=='v'||j1.inv[1]=='v')&&(j2.inv[0]=='v'||j2.inv[1]=='v')&&(j3.inv[0]=='v'||j3.inv[1]=='v')&&(j4.inv[0]=='v'||j4.inv[1]=='v'));
  return 0;
}













