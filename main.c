#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
/*Condition victoire, il reste un ou des bateaux au gagnant
On tire sur la grille de l'autre joueur, ce qui sous entends au moins 3 grilles (une pour le joueur 1, une pour le joueur 2 et une pour un affichage à chaque tour) ce qui donne donc un tableau à 3 dimensions
*/

#define MAP_H 24  //provisoire
#define MAP_W 18  // provisoire
#define MAP_ITEMS 2
#define TOT_BATEAUX 5
#define PORTE_AVION 6
#define CROISEUR 5
#define CORVETTE 1
#define DESTROYER 3
#define JOUEUR1 0
#define JOUEUR2 1
#define EAU 0
#define TOUCHE 5
#define RATE 9




void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){       //Utilsé pour la génération de valeurs aléatoires
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

void Color(int couleurDuTexte,int couleurDeFond){  //Fonction pour changer la couleur des valeurs du tableau
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void placementporteavion(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int pos , Dir;
    printf("Veuillez saisir les coordonnées de votre Porte Avions :\n");
    printf("X : " );
    scanf("%d",&X);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Y);
    fflush(stdin);
    pos=X+Y;
    printf("Position Horizontale (saisir 0) ou Verticale (saisir 1) ?\n");
    scanf("%d",&Dir);
    fflush(stdin);
      if(Dir==0){                                 //Je vois qu'il faut partir soit de Xposj soit Yposj pour pouvoir les associer a MAP_H, MAP_W mais il éssaye de me le placer au niveau de la coordoné X et non de pos
           for(i = pos ; i < PORTE_AVION ; i ++ ){
                printf("8", & i );
        }
        }
        else{
           for(i = pos ; i < PORTE_AVION ; i ++ ){
                printf("8", & i );
        }
        }
}

void placementcroiseur(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int pos, Dir;
    printf("Veuillez saisir les coordonnées de votre Croiseur :\n");
    printf("X : " );
    scanf("%d",&X);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Y);
    fflush(stdin);
    pos=X+Y;
    printf("Position Horizontale (saisir 0) ou Verticale (saisir 1) ?\n");
    scanf("%d",&Dir);
    fflush(stdin);
      if(Dir==0){
           for(i = pos ; i < CROISEUR ; i ++ ){
                printf("8", & i );
        }
        }
        else{
           for(i = pos ; i < CROISEUR ; i ++ ){
                printf("8", & i );
        }
        }
}

void placementdestroyer(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int i , pos , Dir ;
    int X , Y ;
    printf("Veuillez saisir les coordonnées de votre Destroyer :\n");
    printf("X : " );
    scanf("%d",&X);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Y);
    fflush(stdin);
    pos=X+Y;
    printf("Position Horizontale (saisir 0) ou Verticale (saisir 1) ?\n");
    scanf("%d",&Dir);
    fflush(stdin);
        if(Dir==0){
           for(i = pos ; i < DESTROYER ; i ++ ){
                printf("8", & i );
        }
        }
        else{
           for(i = pos ; i < DESTROYER ; i ++ ){
                printf("8", & i );
        }
        }

}

void placementcorvette(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int pos, Dir;
    printf("Veuillez saisir les coordonnées de votre Corvette :\n");
    printf("X : " );
    scanf("%d",&X);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Y);
    fflush(stdin);
    pos=X+Y;
    printf("Position Horizontale (saisir 0) ou Verticale (saisir 1) ?\n");
    scanf("%d",&Dir);
    fflush(stdin);
        if(Dir==0){
           for(i = pos ; i <    CORVETTE ; i ++ ){
                printf("8", & i );
        }
        }
        else{
           for(i = pos ; i < CORVETTE ; i ++ ){
                printf("8", & i );
        }
        }
}

void tirjvj(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int tir ,pos;
    printf("Veuillez saisir vos coordonnées de tir\n");
    printf("X : ?\n");
    scanf("%d",&X);
    printf("Y : ?\n");
    scanf("%d",&Y);
    tir = X+Y;
    if(tir==8){
        tir=5;//devient 5 car on a touché un bateau
        printf("Touché ! \n");
    }
    else{
        tir=9; // tir raté
        printf("Raté ! \n");
    }
}

void placementporteavionIA(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int pos;
    X=doRand(0 , MAP_W-1);
    Y=doRand(0 , MAP_H-1);;
    pos=X+Y;
    fflush(stdin);
           for(i = pos ; i <    PORTE_AVION ; i ++ ){
                printf("8", & i );
        }
}

void placementdestroyerIA(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int pos;
    X=doRand(0 , MAP_W-1);
    Y=doRand(0 , MAP_H-1);;
    pos=X+Y;
    fflush(stdin);
           for(i = pos ; i <    DESTROYER ; i ++ ){
                printf("8", & i );
        }
}

void placementcroiseurIA(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int pos;
    X=doRand(0 , MAP_W-1);
    Y=doRand(0 , MAP_H-1);;
    pos=X+Y;
    fflush(stdin);
           for(i = pos ; i <    CROISEUR ; i ++ ){
                printf("8", & i );
        }
}

void placementcorvetteIA(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y , i;
    int pos;
    X=doRand(0 , MAP_W-1);
    Y=doRand(0 , MAP_H-1);;
    pos=X+Y;
    fflush(stdin);
           for(i = pos ; i <    CORVETTE ; i ++ ){
                printf("8", & i );
        }
}


void tirjvia(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int X , Y ,i ;
    int tir ,pos;
    printf("Veuillez saisir vos coordonnées de tir\n");
    printf("X : ?\n");
    scanf("%d",&X);
    printf("Y : ?\n");
    scanf("%d",&Y);
    tir = X+Y;
    if(tir==8){
        tir=5;//devient 5 car on a touché un bateau
        printf("Touché ! \n");
    }
    else{
        tir=9; // tir raté
        printf("Raté ! \n");
    }
    printf("Tour IA \n");
    X=doRand(0 , MAP_W-1);
    Y=doRand(0 , MAP_H-1);
    tir = X+Y;
    if(tir==8){
        tir=5;//devient 5 car on a touché un bateau
        printf("Touché ! \n");
    }
    else{
        tir=9; // tir raté
        printf("Raté ! \n");
    }
}

void tiriavia(int map[MAP_H][MAP_W][MAP_ITEMS]){
    int tir , X , Y ,X1 , Y1 , X2 , Y2 ;
    X1=doRand(0 , MAP_W-1);
    Y1=doRand(0 , MAP_H-1);
    tir = X+Y;
    if(tir==8){
        tir=5;//devient 5 car on a touché un bateau
        printf("Touché ! \n");
    }
    else{
        tir=9; // tir raté
        printf("Raté ! \n");
    }

    X2=doRand(0 , MAP_W);
    Y2=doRand(0 , MAP_H);
    tir = X+Y;
    if(tir==8){
        tir=5;//devient 5 car on a touché un bateau
        printf("Touché ! \n");
    }
    else{
        tir=9; // tir raté
        printf("Raté ! \n");
    }
}

void jvj(){
    int map[MAP_H][MAP_W][MAP_ITEMS];
veriftir( map[MAP_H][MAP_W][MAP_ITEMS]);
tirjvj( map[MAP_H][MAP_W][MAP_ITEMS]);
affichetab( map[MAP_H][MAP_W][MAP_ITEMS]);
save(map[MAP_H][MAP_W][MAP_ITEMS]);
}

void jvia(){
    int map[MAP_H][MAP_W][MAP_ITEMS];
veriftir(map[MAP_H][MAP_W][MAP_ITEMS]);
tirjvia( map[MAP_H][MAP_W][MAP_ITEMS]);
affichetab( map[MAP_H][MAP_W][MAP_ITEMS]);
save(map[MAP_H][MAP_W][MAP_ITEMS]);
}

void iavia(){
    int map[MAP_H][MAP_W][MAP_ITEMS];

veriftir( map[MAP_H][MAP_W][MAP_ITEMS]);
tiriavia( map[MAP_H][MAP_W][MAP_ITEMS]);
affichetab( map[MAP_H][MAP_W][MAP_ITEMS]);
save(map[MAP_H][MAP_W][MAP_ITEMS]);
}

void save(int map[MAP_H][MAP_W][MAP_ITEMS]){
    FILE * fp;

    fp = fopen ("./savebn.txt", "w+");
    int i,j,k;
    for(i = 0;i < MAP_H; i++){
        for(j = 0;j < MAP_W; j++){
            for(k = 0;k < MAP_ITEMS; k++){
                fprintf(fp, "%d", (int)map[i][j][k]);
            }
        }
    }

    fclose(fp);
}
void load(int map[MAP_H][MAP_W][MAP_ITEMS]){
    FILE *fp;
    int i,j,k;
    int c;

    fp = fopen("./savebn.txt","r");
    for(i = 0;i < MAP_H; i++){
        for(j = 0;j < MAP_W; j++){
            for(k = 0;k < MAP_ITEMS; k++){
                c = fgetc(fp);
                if( feof(fp) )
                {
                    break;
                }
                map[i][j][k]=(int)c;
            }
        }
    }
    fclose(fp);

}
void verifpos(int map[MAP_H][MAP_W][MAP_ITEMS]){ //Permet de savoir si un bateau n'est pas déjà placé aux coordonnées saisies
int i,j,k;
int X , Y ;
if(X == 5 || Y == 5){
    printf("Un bateau est déjà présent sur cette case");
    X = 5 ;
    Y = 5 ;

}
}
void veriftir(int map[MAP_H][MAP_W][MAP_ITEMS] ){ //Permet de savoir si le tir n'est pas hors limites ou si le joueur n'as pas déjà tiré sur cette même case
    int X , Y ;
    if(X == 1 || Y == 1){
        printf("Vous avez déjà tiré sur cette case");
        //revenir a l'état d'avant, c'est a dire lui redemander de saisir des coordonnées de tirs valides
    }
    else if( X > MAP_H || X > MAP_W || Y > MAP_H || Y > MAP_W){
        printf("Tir hors limites");
        //revenir a l'état d'avant, c'est a dire lui redemander de saisir des coordonnées de tirs valides
    }

}
void placementjvia(int map[MAP_H][MAP_W][MAP_ITEMS]){
    verifpos( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementporteavion( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementdestroyer( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementcroiseur( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementcorvette( map[MAP_H][MAP_W][MAP_ITEMS]);
    verifpos( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementporteavionIA( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementdestroyerIA( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementcroiseurIA( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementcorvetteIA( map[MAP_H][MAP_W][MAP_ITEMS]);


}
void placementjvj(int map[MAP_H][MAP_W][MAP_ITEMS]){

        verifpos( map[MAP_H][MAP_W][MAP_ITEMS]);
        placementporteavion( map[MAP_H][MAP_W][MAP_ITEMS]);
        placementdestroyer( map[MAP_H][MAP_W][MAP_ITEMS]);
        placementcroiseur( map[MAP_H][MAP_W][MAP_ITEMS]);
        placementcorvette( map[MAP_H][MAP_W][MAP_ITEMS]);

    }
void placementiavia(int map[MAP_H][MAP_W][MAP_ITEMS]){
     verifpos( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementporteavionIA(map[MAP_H][MAP_W][MAP_ITEMS]);
    placementdestroyerIA( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementcroiseurIA( map[MAP_H][MAP_W][MAP_ITEMS]);
    placementcorvetteIA( map[MAP_H][MAP_W][MAP_ITEMS]);

}
void menu(){
    int map[MAP_H][MAP_W][MAP_ITEMS];
    int choix = -1;
    while(choix){
        printf("*****************\n*BATAILLE NAVALE*\n*****************\n\n\n");
        printf("Veuillez choisir votre mode jeu : \n\n");
        printf(" 1 : Joueur vs Joueur\n");
        printf(" 2 : Joueur vs IA\n");
        printf(" 3 : IA vs IA\n");
        printf(" 4 : Charger la partie\b");
        scanf("%d",&choix);
        fflush(stdin);
        switch(choix){
    case 1:
        placementjvj(map[MAP_H][MAP_W][MAP_ITEMS]);
        jvj();
        tirjvj(map[MAP_H][MAP_W][MAP_ITEMS]);
        break;
    case 2:
        placementjvia(map[MAP_H][MAP_W][MAP_ITEMS]);
        jvia();
        tirjvia(map[MAP_H][MAP_W][MAP_ITEMS]);
        break;
    case 3:
        placementiavia(map[MAP_H][MAP_W][MAP_ITEMS]);
        iavia();
        tiriavia(map[MAP_H][MAP_W][MAP_ITEMS]);
        break;
    case 4 :
        load(map[MAP_H][MAP_W][MAP_ITEMS]);
        }

    }
}

void affichetab(int map[MAP_H][MAP_W][MAP_ITEMS]){
int i,j,k;
    //printf("  1   2  3  4  5  6  7  8  9  10\n");
    for(i = -1 ; i < MAP_H ; i++){
        for(j = -1; j < MAP_W ; j++){
                for (k = -1 ; k < MAP_ITEMS ; k++){
                    printf("%d ", map[i][j][k]);
                }
        }
         printf("\n");
    }



}
int main()
{
    int map[MAP_H][MAP_W][MAP_ITEMS] = {0};
    menu();


}

