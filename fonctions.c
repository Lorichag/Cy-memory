#include "fonctions.h"


void vide_buffer(){
	while(getchar()!= '\n'){
	}
}

void display2(char tab[ROW][COL]){       //Affiche le terrain avec les évenement
	int i,j;
	for(i=0;i<ROW;i++){  // Parcours du plateau
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
		    else{                                       //Affiche le reste
			    printf(" %c ",tab[i][j]);
		    }
		}
		printf("\n");
	}

}	

void display(char tab[ROW][COL],Hero p,char tab2[ROW][COL]){     //Affiche le plateau de jeu
	int i,j;
  int see=0; // variable qui permet de savoir si la case a déja été révélé dans le tour                                
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
		    if(i==p.x && j==p.y){ // si la case qu'on veut afficher est celle où se trouve le joueur
          if(tab[p.x][p.y]==tab2[p.x][p.y]){ // on regarde si la case a déjà été révélé dans le tour
            see=1;
          }
		    	tab[p.x][p.y]=tab2[p.x][p.y]; // On remplace la case du plateau qui va être dévoilé par son évenement pour l'afficher
		    	if(tab[i][j]=='Z'|| tab[i][j]=='H' || tab[i][j]=='T'|| tab[i][j]=='B'){
		        	couleur(31)                //Si c'est un monstre
		        	printf(" %c ",tab[i][j]);
		        	couleur(0)
		    	}
		    	else if(tab[i][j]=='o'|| tab[i][j]=='P'){
				    couleur(35)                             //Si c'est un totems ou le portail
				    printf(" %c ",tab[i][j]);
				    couleur(0)
			     }
          else if(tab[i][j]==' ' || tab[i][j]=='X' || see==1){
              couleur(32)    // On affiche la position du joueur après que l'évenement se soit déroulé
		        	printf(" %c ",p.marker);
              couleur(0)
		    	}
		    	else if(tab[i][j]=='C'){
				    couleur(33)                             //Si c'est un Coffre
				    printf(" %c ",tab[i][j]);
				    couleur(0)
		    	}
		    	else{                                       //Si c'est autre chose(les armes)
			    printf(" %c ",tab[i][j]);
		    	}
		    }
        else{  // Lorsqu'on affiche pas la position du joueur
			     printf(" %c ",tab[i][j]);
        }
		}
		printf("\n");
	}
}



void build(char tab[ROW][COL]){           //Construit le terrain
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




//Faire le spawn des monstres et autre
void spawn(char tab[ROW][COL],char tabmob[25]){
    int i,j,mob;
    for(int i=0;i<=6;i++){
        for(int j=0;j<=6;j++){
           if ((i==0 &&j==COL-3) || (i==ROW-3 && j==COL-1) || (i==ROW-1 && j==2) || (i==2 && j==0)){ 
              tab[i][j]='X'; //On place les spawn des joueurs
           }
            else if(i==0 || j==0 || j==6 || i==6){ //Construit les bores vide du terrain
              tab[i][j]=' ';
            }
            else{  // On place aléatoirement les différents événements
              mob=rand()%25;
              while(tabmob[mob]=='v' || ((i==1 && j==4 || i==2 && j==1 || i==5 && j==2 || i==4 && j==5) && tabmob[mob] == 'o')){ // Si on tombe sur un événement déjà placé on en prend un autre
                mob=rand()%25;
              }
              tab[i][j]=tabmob[mob];
              tabmob[mob]='v'; // On met à vide l'élément qui vient d'être placé
            }
        }
    }
  printf("\n");

}

void reset(char tab[ROW][COL],char tab2[ROW][COL]){ // reset la map quand un joueur fini son tour
    for(int i=0;i<7;i++){
      for(int j=0;j<7;j++){
      tab2[i][j]=tab[i][j];// Tab2 correspond à la map qui va être réinitialisé et tab c'est la map d'origine
    }
  }
}


int banmove(Hero p,int location,char tab[ROW][COL]){
  if((location==1 && (p.y==0 || tab[p.x][p.y-1]!='o' ))||(location==2 && (p.x==0 || tab[p.x-1][p.y]!='o'))||( location==3 && (tab[p.x+1][p.y]!='o' || p.x==6))||( location==4 && (tab[p.x][p.y+1]!='o' || p.y==6))){  // on teste si on sort du tableau, si on sort du labyrinthe ou si on retoure sur une case déjà visité
     return 0; // si oui alors on renvoie 0
  }
  return 1; // si non alors on renvoie 1
}

Hero move(Hero p,char tab[ROW][COL]){
  // La fonction pour déplacer le joueur
  int location; // Variable qui va contenir la direction dans laquelle le joueur va aller
  int check;
  printf("Choisissez où vous voulez allez: \n");
  printf("1=gauche,2=haut,3=bas,4=droite\n");
  check = scanf("%d",&location);
  vide_buffer();
  while(banmove(p,location,tab)==0 || check != 1){ // On vérifie que le déplacement est autorisé est que le scanf c'est bien effectué
    if(check != 1){
      printf("Erreur de saisie \n");
    }
    else{
      printf("Il est impossible d'aller par là ! \n");
    }
    printf("Choisissez où vous voulez allez: \n");
    printf("1=gauche,2=haut,3=bas,4=droite\n");
    check = scanf("%d",&location);
    vide_buffer();
  }// On regarde si le déplacement est valide
  switch(location){ // On modifie la position du joueur selon la direction qu'il prend
    case 1:
      p.y--;
      break;
    case 2:
      p.x--;
      break;
    case 3:
      p.x++;
      break;
    case 4:
      p.y++;
      break;
    default:
      printf("Erreur de saisie \n");
      move(p,tab);
      break;
  }
  
  return p;
}

Hero back(Hero p,char tab[ROW][COL]){ //Lorsque le personnage meurt, s'il tombe sur un totem ou si il est coincé on le renvoie à sa position initiale et on vide son inventaire
  p.x=p.xstart;
  p.y=p.ystart;
  p.stuff[0]='v';
  p.stuff[1]='v';
  return p;
}

Hero fight(Hero p,char tab[ROW][COL]){
// La fonction pour gérer le cas où tu tombe sur un monstre
  if(tab[p.x][p.y]=='Z'){ //cas zombie
    if(p.weapon=='t'){
      printf("Vous avez vaincu le zombie \n");
      tab[p.x][p.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      p=back(p,tab);
    }
  }
  else if(tab[p.x][p.y]=='H'){ //cas harpie
    if(p.weapon=='a'){
      printf("Vous avez vaincu la harpie \n");
      tab[p.x][p.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      p=back(p,tab);
    }
  }
  else if(tab[p.x][p.y]=='B'){ //cas basilic
    if(p.weapon=='m'){
      printf("Vous avez vaincu le basilic \n");
      tab[p.x][p.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      p=back(p,tab);
    }
  }
  else if(tab[p.x][p.y]=='T'){ //cas troll
    if(p.weapon=='h'){
      printf("Vous avez vaincu le troll \n");
      tab[p.x][p.y]=' ';
    }
    else{
      printf("vous êtes mort retour à la case départ \n");
      p=back(p,tab);
    }
  }
  else if(tab[p.x][p.y]=='C'){ //cas coffre
    if(p.stuff[0]!='C'){ // Si le joueur n'a pas encore de coffre dans son inventaire
      printf("Bravo vous avez trouver le coffre ! \n");
      p.stuff[0]='C'; //On rempli l'inventaire
      tab[p.x][p.y]=' ';
    }
  }
return p;
}

Hero choiceW(Hero p){ // Choix de l'arme
    int choice;
    int check;
    printf("choisisser l'arme que vous voulez utiliser: \n");
    printf("1 = Torche (Tue le Zombie) \n2 = Miroir (Tue le Basilic)\n3 = Hache (Tue le Troll)\n4 = Arc (Tue la Harpie)\n");
    check = scanf("%d",&choice);
    vide_buffer();
    while(check!=1){
    	printf("Erreur de saisie \n");
    	printf("choisisser l'arme que vous voulez utiliser: \n");
	printf("1 = Torche (Tue le Zombie) \n2 = Miroir (Tue le Basilic)\n3 = Hache (Tue le Troll)\n4 = Arc (Tue la Harpie)\n");
	     check = scanf("%d",&choice);
	     vide_buffer();
    }
    switch(choice){ // On équipe l'arme choisi
    case 1: 
      p.weapon = 't';
      break;
    case 2:
      p.weapon='m' ;
      break;
    case 3:
      p.weapon='h';
      break;
    case 4:
      p.weapon='a';
      break;
    default:
      printf("Mauvaise saisi \n");
      choiceW(p);
      break;
  }
  return p;
}
Hero ancient(Hero p,char tab[ROW][COL]){//Quand le joueur tombe sur une arme antique
  if(p.ancient_weapon==tab[p.x][p.y]){ // Si c'est la sienne
    printf("Bravo vous avez trouvé votre arme antique \n");
    p.stuff[1]=tab[p.x][p.y]; //On rempli l'iventaire
    tab[p.x][p.y]=' ';
  }
  return p;
}

Hero event(Hero p,char tab[ROW][COL],char tab2[ROW][COL],char tabstart[ROW][COL]){// Si le personnage tombe sur un portail, un totem ou une arme antique
  int x,y,check1,check2;
  char ret[1][1];
  if (tab2[p.x][p.y]=='P'){            //S'il tombe sur un portail
      printf("Oh un portail choisissez l'emplacement ou vous voulez vous téleporter \n" );
      printf("  |1|2|3|4|5|\n1 |.|.|.|.|.|\n2 |.|.|.|.|.|\n3 |.|.|.|.|.|\n4 |.|.|.|.|.|\n5 |.|.|.|.|.|\n ");
        printf("Entrer la ligne (1,2...) \n" );
        check1=scanf("%d",&x);
        vide_buffer();
        printf("Entrer la colonne (1,2...) \n" );
        check2=scanf(" %d",&y);
        vide_buffer();
      while((x>5 || x<1 && y<1 || y>5 ) || check1 !=1 || check2 !=1){//On regarde si les coordonnées sont valides
      	printf("Erreur de saisie \n" );
        printf("Entrer la ligne (1,2...) \n" );
        check1=scanf("%d",&x);
        vide_buffer();
        printf("Entrer la colonne (1,2...) \n");
        check2=scanf(" %d",&y);
        vide_buffer();
      }
      tab[p.x][p.y]=' '; // On retire le portail de la map 
      tab2[p.x][p.y]=' ';
      p.x=x; // On téléporte le joueur à l'emplacement choisi
      p.y=y;
      display(tab,p,tab2);//On affiche l'évenement de la case où on atteri
      p=fight(p,tab2); //On déclenche l'évenement de la case où on atteri
      p=event(p,tab,tab2,tabstart);
    }    

  else if (tab2[p.x][p.y]=='o'){ // Si on tombe sur un totem
      printf("Oh un totem choisissez l'emplacement ou vous voulez le déplacer mais pas devant la base des autres\n" );
      printf("  |1|2|3|4|5|\n1 |.|.|.|x|.|\n2 |x|.|.|.|.|\n3 |.|.|.|.|.|\n4 |.|.|.|.|x|\n5 |.|x|.|.|.|\n ");
      printf("Entrer la ligne (1,2...) \n" );            
      check1=scanf("%d",&x);
      vide_buffer();
      printf("Entrer la colonne (1,2...) \n" );
      check2=scanf(" %d",&y);
      vide_buffer();
      while((x>5 || x<1 && y<1 || y>5 || x==1 && y==4 || x==2 && y==1 || x==5 && y==2 || x==4 && y==5) || check1 != 1 || check2 != 1){//On regarde si les coordonnées sont valides
        printf("Erreur de saisie \n" );
        printf("Entrer la ligne (1,2...) \n" );            
        check1=scanf("%d",&x);
        vide_buffer();
        printf("Entrer la colonne (1,2...) \n" );
        check2=scanf(" %d",&y);
        vide_buffer();
        }  
      ret[0][0]=tabstart[p.x][p.y];   // modifie le plateau d'origine pour pouvoir reset avec le totem au bon endroit
      tabstart[p.x][p.y]=tabstart[x][y];
      tabstart[x][y]=ret[0][0];
      p=back(p,tab2);
    }
  else if (tab2[p.x][p.y]=='e' || tab2[p.x][p.y]=='g' || tab2[p.x][p.y]=='d' || tab2[p.x][p.y]=='b'){ //Cas armes antiques
      p=ancient(p,tab2);
    }
return p;
  }

int win(Hero p,char tab2[ROW][COL],char tabstart[ROW][COL]){ //Fin de la partie
  if(p.stuff[0]!='v' && p.stuff[1]!='v'){ // On regarde si le joueur qui vient de finir son tour possede un coffre et son arme antique
    p=back(p,tab2);
  	reset(tabstart,tab2);
  	display2(tab2);// On affiche le plateau quand la partie est finie
  	printf("Bravo %s vous avez gagné en %d tours\n",p.name,p.turn);
    FILE* fichier=NULL;
    fichier=fopen("scores.txt","a");
    fprintf(fichier, "Le joueur %s à gagné en %d tours\n",p.name,p.turn);
  	return 1;//On renvoie 1 si la partie est finie
  }
return 0;
}

Hero trap(Hero p,char tab[ROW][COL]){
  if(banmove(p,1,tab)==0 && banmove(p,2,tab)==0 && banmove(p,3,tab)==0 && banmove(p,4,tab)==0 && p.x!=p.xstart && p.y!=p.ystart &&(p.stuff[0]=='v' || p.stuff[1]=='v')){ // Le joueur est-il bloquer?
  	printf("Vous êtes bloquer dans le labyrinthe! \n");
  	p=back(p,tab);// Si oui on le revoie à sa position initiale
  }
  return p;
}

Hero turn(Hero p,char tab[ROW][COL],char tabmob[25],char tab2[7][7],char tabstart[ROW][COL]){//Gère le tour d'un joueur
  do{
    display(tab,p,tab2);//On affiche le plateau au début du tour
    display2(tab2);
    sleep(1);
    p=choiceW(p);//Choix de l'arme
    p=move(p,tab);//Choix de la direction
    display(tab,p,tab2);//Affichage de l'événement
    sleep(1);
    p=fight(p,tab2);//Combat s'il y en a un
    p=event(p,tab,tab2,tabstart);//Evénement s'il y en a un//Combat s'il y en a un
    p=trap(p,tab);//Le joueur est-il bloquer
    sleep(1);
  }while((p.stuff[0]=='v'||p.stuff[1]=='v')&&(p.x!=p.xstart || p.y!=p.ystart));//Si le joueur est revenu au départ ou si son inventaire est plein on finit son tour
return p;
}

int game(Hero p1,Hero p2,Hero p3,Hero p4, char tab[ROW][COL],char tabmob[25],char tab2[7][7]){
  // Gère une partie de jeu
  char tabstart[7][7];//Phase d'initialisation
  char tabmap[7][7];
  build(tab);
  spawn(tab2,tabmob);
  reset(tab2,tabstart);
  reset(tab,tabmap);

  do{
    printf("%s c'est à vous de jouer. \n",p1.name);//tour du premier joueur
    p1=turn(p1,tab,tabmob,tab2,tabstart);
    p1.turn+=1;
    if(win(p1,tab2,tabstart)){
      return 1;
    }
    reset(tabstart,tab2);//On reset les deux maps
    reset(tabmap,tab);
    printf("%s c'est à vous de jouer. \n",p2.name);//tour du deuxième joueur
    p2=turn(p2,tab,tabmob,tab2,tabstart);
    p2.turn+=1;
    if(win(p2,tab2,tabstart)){
      return 1;
    }
    reset(tabstart,tab2);//On reset les deux maps
    reset(tabmap,tab);
    if(p3.marker!='v'){
      printf("%s c'est à vous de jouer. \n",p3.name);//tour du troisième joueur s'il existe 
      p3=turn(p3,tab,tabmob,tab2,tabstart);
      p3.turn+=1;
      if(win(p3,tab2,tabstart)){
        return 1;
      }
      reset(tabstart,tab2);//On reset les deux maps
      reset(tabmap,tab);
    }
    if(p4.marker!='v'){
      printf("%s c'est à vous de jouer. \n",p4.name);//tour du quatrième joueur s'il existe
      p4=turn(p4,tab,tabmob,tab2,tabstart);
      p4.turn+=1; 
      if(win(p4,tab2,tabstart)){
        return 1;
      }
      reset(tabstart,tab2);//On reset les deux maps
      reset(tabmap,tab);
    }
  }while((p1.stuff[0]=='v'||p1.stuff[1]=='v')&&(p2.stuff[0]=='v'||p2.stuff[1]=='v')&&(p3.stuff[0]=='v'||p3.stuff[1]=='v')&&(p4.stuff[0]=='v'||p4.stuff[1]=='v'));//On continue tant que personne n'a gagné
  return 0;
}


