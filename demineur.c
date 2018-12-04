#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define T 5
#define MINE 5
#define X 'X' // Case non découverte
#define M 'M' // Case minée

typedef char tab[T][T];
int i;
int j;

void Initialisation(tab,tab);
void AfficheGrille(tab);
void PlaceMine(tab);
void Jouer(tab, tab);
void ChercheMine(tab,tab, int i, int j);

int main(){
	tab TableauMine; //Tableau pour les mines 
	tab TableauJeu; //Tableau pour le jeu 
	
	srand(time(NULL)); // pour empêcher la répétition de séquence entre les exécutions
	
	Initialisation(TableauMine, TableauJeu);
	PlaceMine(TableauMine);
	Jouer(TableauMine, TableauJeu);
	
}

void Initialisation(tab TabMin, tab TabJeu) { //Initilisation du tableau de mines et de jeu
	int i, j;
	
	for(i=0; i<T; i++){
		for(j=0; j<T; j++){
			TabMin[i][j] = X;
			TabJeu[i][j] = X;
		}
	}
}

void AfficheGrille(tab TabJeu){ // Affiche la grille de jeu
	int i, j;
	
	for(i=0;i<T;i++){
    	for(j=0;j<T;j++){
      		printf("%c ",TabJeu[i][j]);
    	}
    	printf("\n");
  	}
  	printf("\n");
}

void PlaceMine(tab TabMin){ //Place les mines dans le tableau de mine
	int i,j;
	int pose;
	
	for(pose=0; pose<MINE; pose++){
		i = rand()%T;
    	j = rand()%T;
    	if (TabMin[i][j] == M){
      		while(TabMin[i][j] == M){
   				i = rand()%T;
   				j = rand()%T;
      		}
      		TabMin[i][j] = M;
    	}else{
      		TabMin[i][j] = M;
    	}
  	}	
}

void ChercheMine(tab TabMin, tab TabJeu, int i, int j){
	  int c = 0;

  if ((i == T-1) && (j == T-1)){ // Case "En bas à droite"
    if (TabMin[i-1][j-1] == M){
      c++;
    }
    if (TabMin[i][j-1] == M){
      c++;
    }
    if(TabMin[i-1][j] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    }
  }else if((i == 0) && (j == T-1)){ // Case "En haut à droite"
    if (TabMin[i][j-1] == M){
      c++;
    }
    if (TabMin[i-1][j-1] == M){
      c++;
    }
    if (TabMin[i-1][j] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    }
  }else if((i == 0) && (j == 0)){ // Case "En haut à gauche"
    if (TabMin[i][j+1] == M){
      c++;
    }
    if (TabMin[i+1][j+1] == M){
      c++;
    }
    if (TabMin[i+1][j] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    }
  }else if((i == T-1) && (j == 0)){ // Case "En bas à gauche"
    if (TabMin[i-1][j] == M){
      c++;
    }
    if (TabMin[i-1][j+1] == M){
      c++;
    }
    if (TabMin[i][j+1] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    }
  }else if(i == 0){ // Ligne du haut
    if (TabMin[i][j-1] == M){
      c++;
    }
    if (TabMin[i+1][j-1] == M){
      c++;
    }
    if (TabMin[i+1][j] == M){
      c++;
    }
    if(TabMin[i+1][j+1] == M){
      c++;
    }
    if (TabMin[i][j+1] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    case 4:
      TabJeu[i][j] = '4';
      break;
    case 5:
      TabJeu[i][j] = '5';
      break;
    }
  }else if(j == 0){ // Colonne de gauche
    if (TabMin[i-1][j] == M){
      c++;
    }
    if (TabMin[i-1][j+1] == M){
      c++;
    }
    if (TabMin[i][j+1] == M){
      c++;
    }
    if(TabMin[i+1][j+1] == M){
      c++;
    }
    if (TabMin[i+1][j] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    case 4:
      TabJeu[i][j] = '4';
      break;
    case 5:
      TabJeu[i][j] = '5';
      break;
    }
  }else if(i == T-1){ // Ligne du bas
    if (TabMin[i][j-1] == M){
      c++;
    }
    if (TabMin[i-1][j-1] == M){
      c++;
    }
    if (TabMin[i-1][j] == M){
      c++;
    }
    if(TabMin[i-1][j+1] == M){
      c++;
    }
    if (TabMin[i][j+1] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    case 4:
      TabJeu[i][j] = '4';
      break;
    case 5:
      TabJeu[i][j] = '5';
      break;
    }
  }else if(j == T-1){ // Colonne de droite
    if (TabMin[i-1][j] == M){
      c++;
    }
    if (TabMin[i-1][j-1] == M){
      c++;
    }
    if (TabMin[i][j-1] == M){
      c++;
    }
    if(TabMin[i+1][j-1] == M){
      c++;
    }
    if (TabMin[i+1][j] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    case 4:
      TabJeu[i][j] = '4';
      break;
    case 5:
      TabJeu[i][j] = '5';
      break;
    }
  }else{ // N'importe où ailleurs
    if (TabMin[i][j+1] == M){
      c++;
    }
    if (TabMin[i+1][j+1] == M){
      c++;
    }
    if (TabMin[i+1][j] == M){
      c++;
    }
    if (TabMin[i+1][j-1] == M){
      c++;
    }
    if (TabMin[i][j-1] == M){
      c++;
    }
    if (TabMin[i-1][j-1] == M){
      c++;
    }
    if (TabMin[i-1][j] == M){
      c++;
    }
    if (TabMin[i-1][j+1] == M){
      c++;
    }
    switch(c){ // Attribution de la valeur
    case 0:
      TabJeu[i][j] = '0';
      break;
    case 1:
      TabJeu[i][j] = '1';
      break;
    case 2:
      TabJeu[i][j] = '2';
      break;
    case 3:
      TabJeu[i][j] = '3';
      break;
    case 4:
      TabJeu[i][j] = '4';
      break;
    case 5:
      TabJeu[i][j] = '5';
      break;
    case 6:
      TabJeu[i][j] = '6';
      break;
    case 7:
      TabJeu[i][j] = '7';
      break;
    case 8:
      TabJeu[i][j] = '8';
      break;
    }
  }
}

void Jouer(tab TabMin, tab TabJeu){
	int ligne;
	int colonne;
	int perdu = -1;
	int compteur = 0;// Compte le nombre de cases qui ont été découverte
	int CSM = T*T-MINE; // Nombre de cases sans mines
	
	printf("Debut du Jeu du Démineur \n\n");
	
	while((perdu == -1) && (compteur != CSM)){
		AfficheGrille(TabJeu);
		
		printf("Ligne ? ");
		scanf("%d", &ligne);
		while((ligne < 0) || (ligne >= T)){
			printf("Ligne Invalide. Saisissez une nouvelle valeur : ");
			scanf("%d", &ligne);
		}
		
		printf("Colonne ? ");
		scanf("%d", &colonne);
		while((colonne < 0) || (colonne >= T)){
			printf("Colonne Invalide.Saisissez une nouvelle valeur : ");
			scanf("%d", &colonne);
		}
		
		printf("\n");
		
		if(TabMin[ligne][colonne] == M){
			perdu == 1; //Le joueur à perdu
			printf("Vous êtes tombés sur une mine :O \n\n");
		}else{
			if(TabJeu[ligne][colonne] != X){
				printf("Vous avez déja rentré cette valeur.\n\n");
			}else{
			//	ChercheMine(TabMin,TabJeu, ligne, colonne);// Recherche du nombre de mines aux alentours
				compteur++; 
			}
		}
	}
	
	if(perdu == 1){
		printf("GAME OVER !! Vous avez perdu !");
	}else{
		printf("Bravo ! Vous avez gagné la partie.");
	}
}

