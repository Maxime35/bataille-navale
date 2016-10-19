#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
/*Condition victoire, il reste un ou des bateaux au gagnant
On tire sur la grille de l'autre joueur, ce qui sous entends au moins 3 grilles (une pour le joueur 1, une pour le joueur 2 et une pour un affichage à chaque tour) ce qui donne donc un tableau à 3 dimensions
*/

#define MAP_H 18  //provisoire
#define MAP_W 24  // provisoire
#define MAP_ITEMS 3
#define MAP_DEBUT 0
#define TOT_BATEAUX 5
#define PORTE_AVION 6
#define CROISEUR 5
#define CORVETTE 1
#define DESTROYER 3
#define HAUT 1
#define BAS 2
#define GAUCHE 3
#define DROITE 4
#define JOUEUR1 0
#define JOUEUR2 1
#define EAU 0
#define BATEAUX 4
#define TOUCHE 5
#define RATE 9
#define HOR 0
#define VER 1

// besoin de définir un booléen pour chaque joueur pour pouvoir alterner entre les deux (faire un random pour déterminer lequel des deux Joueurs commence)
void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}
void porteavion(int*Xposj , int*Yposj){
     printf("Veuillez saisir les coordonnées de votre Porte Avions :\n");
    printf("X : " );
    scanf("%d",&Xposj);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj);
    fflush(stdin);
}
void croiseur(int*Xposj , int*Yposj){
    printf("Veuillez saisir les coordonnées de votre Croiseur :\n");
    printf("X : " );
    scanf("%d",&Xposj);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj);
    fflush(stdin);
}
void destroyer(int*Xposj , int*Yposj){
    printf("Veuillez saisir les coordonnées de votre Destroyer :\n");
    printf("X : " );
    scanf("%d",&Xposj);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj);
    fflush(stdin);
}
void corvette(int*Xposj , int*Yposj){
    printf("Veuillez saisir les coordonnées de votre Corvette :\n");
    printf("X : " );
    scanf("%d",&Xposj);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj);
    fflush(stdin);
}
void  dirplac(int*Xposj , int*Yposj){
    int /*Xposj , Yposj*/ choixdir ;
    bool
    if (Xposj != MAP_H+1 || Xposj != MAP_W+1 || Yposj != MAP_H+1 || Yposj != MAP_W+1){
        printf("Dans quelle direction voulez vous placer votre bateau ? \n");
        printf("1 : En haut\n");
        printf("1 : En bas\n");
        printf("1 : A droite\n");
        printf("1 : A gauche\n");
        scanf("%d",&choixdir);
        fflush(stdin);
        switch(choixdir){
        case 1:
            //définir une variable pouvant prendre chaun leur tour la pos du bateau en question  = &Yposj - /* taille du bateau max concerné*/;
            //peut être avec une boucle en déterminant une incrémetation de 1 en 1 jusqu'au nombre max de bateaux
            break;
        case 2:
             //définir une variable pouvant prendre chaun leur tour la pos du bateau en question = &Yposj + /* taille du bateau max concerné*/ ;
             //peut être avec une boucle en déterminant une incrémetation de 1 en 1 jusqu'au nombre max de bateaux
            break;
        case 3 :
            //définir une variable pouvant prendre chaun leur tour la pos du bateau en question  = &Xposj + /* taille du bateau max concerné*/ ;
            //peut être avec une boucle en déterminant une incrémetation de 1 en 1 jusqu'au nombre max de bateaux
            break;
        case 4:
             //définir une variable pouvant prendre chaun leur tour la pos du bateau en question = &Xposj - /* taille du bateau max concerné*/ ;
             //peut être avec une boucle en déterminant une incrémetation de 1 en 1 jusqu'au nombre max de bateaux
            break;
        }
    }
}
void tirjvj(int*Xposj , int*Yposj){
    int tir;
    printf("Veuillez saisir vos coordonnées de tir\n");
    printf("X : ?\n");
    scanf("%d",&tir);
    printf("Y : ?\n");
    scanf("%d",&tir);
    if(tir==4){
        pos=5;//la position devient 5 car on a touché un bateau
        printf("Touché ! \n");
    }
    else{
        pos=9; // tir raté
        printf("Raté ! \n");
    }
}
void tirjvia(){
}
void tiriavia(){
}
void jvj(){

}
void jvia(){
}
void iavia(){
}
void save(int map[MAP_H][MAP_W][MAP_ITEMS]){
    FILE * fp;

    fp = fopen ("./savebn.txt", "w+");
    int i,j,k;
    for(i = 0;i < MAP_H; i++){
        for(j = 0;j < MAP_W; j++){
            for(k = 0;k < MAP_ITEMS; k++){
                fprintf(fp, "%c", (char)map[i][j][k]);
            }
        }
    }

    fclose(fp);
}
void load(int map[MAP_H][MAP_W][MAP_ITEMS]){
    FILE *fp;
    int i,j,k;
    char c;

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
     /*for(i = 0;i < MAP_H; i++){          Boucle qui sert à ??
        for(j = 0;j < MAP_W; j++){         Utilise une constante de jeurencontre, déterminer à quoi elle sert pluq tard
            map[i][j][MAP_PLAYER]=0;
        }
    }*/

}
void verifpos(int x , int y , int*Xpos , int*Ypos){
int i,j,k;
if(&Xpos == 5 || &Ypos == 5){
    printf("Un bateau est déjà présent sur cette case");

}
}
void veriftir(int x , int y ){
    if()

}
void placementjvia(int x , int y , int*Xposj1, int*Yposj1){
    int choixdir ;
    int i ;
    int choix ;
    int porteavion , croiseur , destroyer , corvette;

    printf("Veuillez choisir le type de navire que vous voulez placer (un de chaque) :\n");
    printf("1 : Porte Avions (6  cases)\n");
    printf("2 : Croiseur (4 cases) x 2 \n");
    printf("4 : Destroyer (3 cases) x 2\n");
    printf("5 : Corvette (1 cases)\n");
    scanf("%d",&choix);
    fflush(stdin);


}
void placementjvj(int x , int y , int*Xposj1, int*Yposj1 , int*Xposj2 , int*Yposj2){

    int choixdir ;
    int i ;
    int choix ;
    int porteavion , croiseur , destroyer , corvette ;

    printf("Veuillez choisir le type de navire que vous voulez placer  :\n");
    printf("1 : Porte Avions (6 cases) \n");
    printf("2 : Croiseur (4 cases) x 2 \n");
    printf("3 : Destroyer (3 cases) x 2 \n");
    printf("4 : Corvette (1 case ) \n");
    scanf("%d",&choix);
    fflush(stdin);

    for( i = 0 ; i < TOT_BATEAUX ; i++){
    switch(choix){
    case 1:
        /*printf("Veuillez saisir les coordonnées de votre Porte Avions :\n");
    printf("X : " );
    scanf("%d",&Xposj1);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj1);
    fflush(stdin);*/

    if (Xposj1 != MAP_H+1 || Xposj1 != MAP_W+1 || Yposj1 != MAP_H+1 || Yposj1 != MAP_W+1){
        printf("Dans quelle direction voulez vous placer votre bateau ? \n");
        printf("1 : En haut\n");
        printf("1 : En bas\n");
        printf("1 : A droite\n");
        printf("1 : A gauche\n");
        scanf("%d",&choixdir);
        fflush(stdin);
        switch(choixdir){
        case 1:
            porteavion = &Yposj1 - 6;
            break;
        case 2:
            porteavion = &Yposj1 + 6 ;
            break;
        case 3 :
            porteavion = &Xposj1 + 6 ;
            break;
        case 4:
            porteavion = &Xposj1 - 6 ;
            break;
        }
    }
        break;
    case 2:
        /*printf("Veuillez saisir les coordonnées de votre Croiseur :\n");
    printf("X : " );
    scanf("%d",&Xposj1);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj1);
    fflush(stdin);*/

    if (Xposj1 != MAP_H+1 || Xposj1 != MAP_W+1 || Yposj1 != MAP_H+1 || Yposj1 != MAP_W+1){
        printf("Dans quelle direction voulez vous placer votre bateau ? \n");
        printf("1 : En haut\n");
        printf("1 : En bas\n");
        printf("1 : A droite\n");
        printf("1 : A gauche\n");
        scanf("%d",&choixdir);
        fflush(stdin);
        switch(choixdir){
        case 1:
            croiseur = &Yposj1 - 5 ;
            break;
        case 2:
            croiseur = &Yposj1 + 5 ;
            break;
        case 3 :
            croiseur=  &Xposj1 + 5 ;
            break;
        case 4:
            croiseur = &Xposj1 - 5 ;
            break;
        }
    }
        break;
    case 3:
        /*printf("Veuillez saisir les coordonnées de votre Destroyer :\n");
    printf("X : " );
    scanf("%d",&Xposj1);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj1);
    fflush(stdin);*/
    if (Xposj1 != MAP_H+1 || Xposj1 != MAP_W+1 || Yposj1 != MAP_H+1 || Yposj1 != MAP_W+1){
        printf("Dans quelle direction voulez vous placer votre bateau ? \n");
        printf("1 : En haut\n");
        printf("1 : En bas\n");
        printf("1 : A droite\n");
        printf("1 : A gauche\n");
        scanf("%d",&choixdir);
        fflush(stdin);

        switch(choixdir){
        case 1:
            destroyer = &Yposj1 - 3 ;
            break;
        case 2:
            destroyer = &Yposj1 + 3 ;
            break;
        case 3 :
            destroyer = &Xposj1 + 3 ;
            break;
        case 4:
            destroyer = &Xposj1 - 3 ;
            break;
        }
    }
        break;
    case 4:
        /*printf("Veuillez saisir les coordonnées de votre Corvette :\n");
    printf("X : " );
    scanf("%d",&Xposj1);
    fflush(stdin);
    printf("Y : ");
    scanf("%d",&Yposj1);
    fflush(stdin);*/
    if (Xposj1 != MAP_H+1 || Xposj1 != MAP_W+1 || Yposj1 != MAP_H+1 || Yposj1 != MAP_W+1){
        printf("Dans quelle direction voulez vous placer votre bateau ? \n");
        printf("1 : En haut\n");
        printf("1 : En bas\n");
        printf("1 : A droite\n");
        printf("1 : A gauche\n");
        scanf("%d",&choixdir);
        fflush(stdin);
        switch(choixdir){
        case 1:
            corvette = &Yposj1 - 1 ;
            break;
        if (Xposj1 != MAP_H+1 || Xposj1 != MAP_W+1 || Yposj1 != MAP_H+1 || Yposj1 != MAP_W+1){
        printf("Dans quelle direction voulez vous placer votre bateau ? \n");
        printf("1 : En haut\n");
        printf("1 : En bas\n");
        printf("1 : A droite\n");
        printf("1 : A gauche\n");
        scanf("%d",&choixdir);
        fflush(stdin);

        switch(choixdir){
        case 1:
            destroyer = &Yposj1 - 3 ;
            break;
        case 2:
            destroyer = &Yposj1 + 3 ;
            break;
        case 3 :
            destroyer = &Xposj1 + 3 ;
            break;
        case 4:
            destroyer = &Xposj1 - 3 ;
            break;
        }
    }case 2:
            corvette = &Yposj1 + 1 ;
            break;
        case 3 :
            corvette = &Xposj1 + 1 ;
            break;
        case 4:
            corvette = &Xposj1 - 1 ;
            break;



        }
    }
        break;

    }

    }
}

void placementiavia(){
    int x = doRand(0,MAP_H-1);
    int y = doRand(0,MAP_W-1);
}
void menu(){
    int choix = -1;
    while(choix){
        printf("*****************\n*BATAILLE NAVALE*\n*****************\n\n\n");
        printf("Veuillez choisir votre mode jeu : \n\n");
        printf(" 1 : Joueur vs Joueur\n");
        printf(" 2 : Joueur vs IA\n");
        printf(" 3 : IA vs IA\n");
        scanf("%d",&choix);
        fflush(stdin);
        switch(choix){
    case 1:
        //placementjvj();
        //jvj();
        break;
    case 2:
        //placementjvia();
        //jvia();
        break;
    case 3:
        //placementiavia();
        //iavia();
        break;
        }

    }
}
void affichetab(int map[MAP_H][MAP_W][MAP_ITEMS]){
int i,j,k;
    //printf("  1   2  3  4  5  6  7  8  9  10\n");
    for(i = -1 ; i < MAP_H+1 ; i++){
        for(j = -1; j < MAP_W+1; j++){
                for (k = 0 ; k < MAP_ITEMS ; k++){

                }
            /*if(i == -1 || i == MAP_H || j == -1 || j == MAP_W){
                printf("%d",&i);
                printf("%d",&j);
            }
            else{
                printf("0");*/
            printf(" 0 ");

        }
        printf("\n");
    }

}
int main()
{
    int map[MAP_H][MAP_W][MAP_ITEMS] = {0};
    affichetab(map);
    menu();


}

