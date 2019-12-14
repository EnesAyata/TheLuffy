#include "personnage.h"

void remplir_rect(SDL_Rect*A,SDL_Rect*B,SDL_Rect*C,SDL_Rect*D,SDL_Rect*AA,SDL_Rect*BB,SDL_Rect*CC,SDL_Rect*DD){
    A->x=0;A->y=0;A->h=TLuffy;A->w=TLuffy;
    AA->x=100;AA->y=50;AA->h=TLuffy;AA->w=TLuffy;

    B->x=0;B->y=0;B->h=TLuffy;B->w=TLuffy;
    BB->x=0;BB->y=345;BB->h=TLuffy;BB->w=TLuffy;

    C->x=0;C->y=0;C->h=TLuffy;C->w=TLuffy;
    CC->x=107;CC->y=245;CC->h=TLuffy;CC->w=TLuffy;

    D->x=0;D->y=0;D->h=TLuffy;D->w=TLuffy;
    DD->x=310;DD->y=420;DD->h=TLuffy;DD->w=TLuffy;
}


void detection_porte(char** map,SDL_Rect* luffy,luffy_t* personnage,int* n,int* m){
    int posLX= (((luffy->x+10))/TLuffy) ;
    int posLY= (((luffy->y+10))/TLuffy) ;
    if(map[posLY][posLX]=='?'){
        if(personnage->map==1)
            personnage->map=2;
        else if(personnage->map==2)
            personnage->map=3;
        else if(personnage->map==3)
            personnage->map=4;
        luffy->x=0;
        luffy->y=0;
        }
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
    free(perso);
}

void afficherL(luffy_t *perso){
    printf("Vous avez %d argent et %d de vie et %d d'xp \n",perso->argent,perso->vie,perso->experience);
    printf("Et vous avez %d en atk et %d en map\n",perso->atk,perso->map);

}