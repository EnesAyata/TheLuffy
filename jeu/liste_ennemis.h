#ifndef LISTE_ENNEMIS_H
#define LISTE_ENNEMIS_H
#include "liste.h"



typedef struct ennemi_s ennemi_t;
 struct ennemi_s{
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* sprite;    
    //feu_t*feu;
    
    int vie;
    ennemi_t *precedent;
    ennemi_t *suivant;
};
typedef struct ennemi_s ennemi_t;

/* ************************** */
struct Liste_ennemis_s{
    int lenght;
    ennemi_t *premier;
};
typedef struct Liste_ennemis_s Liste_ennemis_t;

/* ************************** */

Liste_ennemis_t *initialisation_ennemi();
void insertion_ennemis(Liste_ennemis_t *liste,ennemi_t *aAjout);
ennemi_t* creeEntite_en1(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie);
ennemi_t* creeEntite_en2(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie);
ennemi_t* creeEntite_en3(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie);
void supprimer_ennemi(Liste_ennemis_t*liste, ennemi_t* asupp);
void afficherListe_en(Liste_ennemis_t *liste);

#endif