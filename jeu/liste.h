#ifndef LISTE_H
#define LISTE_H
#include "feu.h"

typedef struct perso_s perso_t;
 struct perso_s{
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* sprite;    
    //feu_t*feu;
    
    int vie;
    perso_t *precedent;
    perso_t *suivant;
};
typedef struct perso_s perso_t;


struct Liste_s{
    int lenght;
    perso_t *premier;
};
typedef struct Liste_s Liste_t;

Liste_t *initialisation();
void insertion(Liste_t *liste,perso_t*aAjout);
perso_t* creeEntite(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie);
void supprimer(Liste_t*liste,perso_t* asupp);
void afficherListe(Liste_t *liste);
void animation_feu(perso_t* perso);


#endif