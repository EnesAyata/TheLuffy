#include "personnage.h"



void detection_porte(char** map,SDL_Rect* luffy,luffy_t* personnage,int* n,int* m){
    int posLX= (((luffy->x+10))/TLuffy) ;//on crée un point au mileu de luffy
    int posLY= (((luffy->y+10))/TLuffy) ;
    //printf("pos en x %d et en y %d\n",luffy->x,luffy->y);
    //printf("le caract actuel : %c \n",map[posLY][posLX]);
    if(map[posLY][posLX]=='?'){
        if(personnage->map==1)
            personnage->map=2;//on change la map
        else if(personnage->map==2)
            personnage->map=3;//on change la map
        else if(personnage->map==3)
            personnage->map=4;//on change la map
        luffy->x=0;
        luffy->y=0;
        printf("La map %d",personnage->map);
        //desallouer_tab_2D(map,n);
        //taille_fichier("level.txt",&n,&m);
        //tab2=allouer_tab_2D(n,m);
        //map=lire_fichier("level.txt");
        printf("ALLEZ ON Change ! \n");
        }

    //printf("la map du j : %d \n",personnage->map);
    
}


luffy_t* creation_perso(luffy_t* j){
    j= malloc(sizeof(luffy_t));
    j->vie=100;
    j->argent=0;
    j->map=1;
    j->experience=0;
    j->atk=10;
    j->deplacement=0;
    return j;
  
}

void desallouer_perso(luffy_t* perso){
    free(perso);//a refaire car jsuis pas sur ?
}

void afficherL(luffy_t *perso){
    printf("Vous avez %d argent et %d de vie et %d d'xp \n",perso->argent,perso->vie,perso->experience);
    printf("Et vous avez %d en atk et %d en map\n",perso->atk,perso->map);

}