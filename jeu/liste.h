#ifndef LISTE_H
#define LISTE_H
#include "feu.h"


typedef struct perso_s perso_t;
 struct perso_s{
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* sprite;    
    //feu_t*feu;
    int est_affiche;
    int deplacement;
    int vie;
    perso_t *precedent;
    perso_t *suivant;
};
typedef struct perso_s perso_t;

typedef struct mst_s mst_t;
 struct mst_s{
    SDL_Rect src;
    SDL_Rect dest;
    //feu_t*feu;
    int est_affiche;
    int vie;
};
typedef struct mst_s mst_t;

struct Liste_s{
    int lenght;
    perso_t *premier;
};
typedef struct Liste_s Liste_t;

Liste_t *initialisation();
void insertion(Liste_t *liste,perso_t*aAjout);
void supprimer(Liste_t*liste,perso_t* asupp);
void afficherListe(Liste_t *liste);
perso_t* creeEntite(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie,int deplacement);
void animation_feu(perso_t* perso);
void NewBouleFeu(Liste_t* list,SDL_Rect*luffy,SDL_Renderer* rend,luffy_t*luffyPerso);
void atk_luffy(Liste_t*listBf,SDL_Renderer*rend,luffy_t*luffy);
mst_t *creemst(SDL_Rect dest,SDL_Rect src);
void gestion_mst(mst_t*mst1,mst_t*mst2,mst_t*mst3,mst_t*mst4,SDL_Renderer*rend,SDL_Texture* monstre,Liste_t*listBf);

void colli_perso(SDL_Rect a, SDL_Rect b);


#endif