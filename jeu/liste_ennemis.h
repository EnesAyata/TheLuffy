#ifndef LISTE_ENNEMIS_H
#define LISTE_ENNEMIS_H
#include "liste.h"



typedef struct ennemi_s ennemi_t;
 struct ennemi_s{
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* sprite;    
    //feu_t*feu;
    int estAffiche;//0 pour oui 1 pr non
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

int rand_a_b(int a,int b);
void afficherListe_map(Liste_ennemis_t*liste,SDL_Renderer*rend);

void print_monstre_list(Liste_ennemis_t*list,SDL_Renderer*rend);
void freeListEn(Liste_ennemis_t*listBf);
/*void animation_ennemi_map(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);
void animation_ennemi_map_deux(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);
void animation_ennemi_map_trois(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);
void animation_ennemi_map_quatre(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);*/

#endif
