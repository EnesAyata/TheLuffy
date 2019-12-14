/**
 * \file liste.h
 * \brief fichier header es liste chainées implémentées
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 14 décembre 2019
 */

#ifndef LISTE_H
#define LISTE_H
#include "feu.h"

/**
 * \brief struct des boules de feu lancées par le personnage
 */
typedef struct perso_s perso_t;
 struct perso_s{
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* sprite;    
    int est_affiche;
    int deplacement;
    int vie;
    perso_t *precedent;
    perso_t *suivant;
};
typedef struct perso_s perso_t;


/**
 * \brief struct des ennemis du personnage
 */
typedef struct mst_s mst_t;
 struct mst_s{
    SDL_Rect src;
    SDL_Rect dest;
    int est_affiche;
    int vie;
};
typedef struct mst_s mst_t;

/**
 * \brief liste des boules de feu
 */
struct Liste_s{
    int lenght;
    perso_t *premier;
};
typedef struct Liste_s Liste_t;
/**
 * \brief initialisation des listes de boule de feu
 * \return une liste de boules de feu
 */
Liste_t *initialisation();

/**
 * \brief ajoute une boule de feu dans la liste
 * \param liste liste de boules de deu
 * \param aAjout boule de feu
 */
void insertion(Liste_t *liste,perso_t*aAjout);

/**
 * \brief supprime une boule de feu de la liste
 * \param liste liste de boules de feu
 * \param asupp boule de feu
 */
void supprimer(Liste_t*liste,perso_t* asupp);

/**
 * \brief affiche la liste de boules de feu
 * \param liste liste de boules de feu
 */
void afficherListe(Liste_t *liste);

/**
 * \brief anime une boule de feu
 * \param perso boule de feu
 */
void animation_feu(perso_t* perso);

/**
 * \brief création d'une boule de feu
 * \param list liste de boules de feu
 * \param luffy SDL_Rect du personnage principal
 * \param rend rendu final
 * \param luffyPerso struct du perso principal
 */
void NewBouleFeu(Liste_t* list,SDL_Rect*luffy,SDL_Renderer* rend,luffy_t*luffyPerso);

/**
 * \brief transformation de la boule de feu en attaque du perso 
 * \param listBf liste de boules de feu
 * \param rend rendu final
 * \param luffy struct du perso principal
 */
void atk_luffy(Liste_t*listBf,SDL_Renderer*rend,luffy_t*luffy);

/**
 * \brief creation d'un monstre
 * \param dest SDL_Rect destination du monstre
 * \param src SDL_Rect source du monstre
 * \return un struct de monstre
 */
mst_t *creemst(SDL_Rect dest,SDL_Rect src);

/**
 * \brief animation du premier type de monstre
 * \param dest SDL_Rect destination du monstre
 * \param src SDL_Rect source du monstre
 * \param rend rendu final
 * \param text texture du monstre
 */
void animation_ennemi_map(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);

/**
 * \brief animation du deuxième type de monstre
 * \param dest SDL_Rect destination du monstre
 * \param src SDL_Rect source du monstre
 * \param rend rendu final
 * \param text texture du monstre
 */
void animation_ennemi_map_deux(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);

/**
 * \brief animation du troisième type de monstre
 * \param dest SDL_Rect destination du monstre
 * \param src SDL_Rect source du monstre
 * \param rend rendu final
 * \param text texture du monstre
 */
void animation_ennemi_map_trois(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);

/**
 * \brief animation du quatrième type de monstre
 * \param dest SDL_Rect destination du monstre
 * \param src SDL_Rect source du monstre
 * \param rend rendu final
 * \param text texture du monstre
 */
void animation_ennemi_map_quatre(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text);

/**
 * \brief gestion des monstres par rapport aux attaques qu'il reçoivent par Luffy
 * \param mst1 premier monstre
 * \param mst2 deuxième monstre
 * \param mst3 troisième monstre
 * \param mst4 quatrième monstre
 * \param rend rendu final
 * \param monstre texture du monstre
 * \param listBf liste de boules de feu
 * \param perso struct du perso principal
 * \param luffy SDL_Rect destination du perso principal
 */
void gestion_mst(mst_t*mst1,mst_t*mst2,mst_t*mst3,mst_t*mst4,SDL_Renderer*rend,SDL_Texture* monstre,Liste_t*listBf,luffy_t*perso, SDL_Rect luffy);

/**
 * \brief désalloue la mémoire utilisée par la liste de boules de feu
 * \param listBf liste de boules de feu
 */
void freeList(Liste_t*listBf);

/**
 * \brief Implante la collision entre deux sdl_Rect (mais ne fonctionne pas)
 * \param a premier SDL_Rect
 * \param b deuxième SDL_Rect
 */
void colli_perso(SDL_Rect a, SDL_Rect b);

/**
 * \brief écrit le score du joueur dans un fichier txt
 * \param list liste de boules de feu
 * \param luffy struct du perso principal
 */
void ecriture_score(Liste_t*list,luffy_t*luffy);


void free_mst(mst_t* mst1,mst_t* mst2,mst_t* mst3,mst_t* mst4);


/**
 * \brief création d'une entité de boule de feu
 * \param src SDL_Rect source
 * \param dest SDL_Rect destination
 * \param text texture boule de feu 
 * \param vie vie montre
 * \param deplacement deplacement monstre
 * \return struct de boule de feu
 */
perso_t* creeEntite(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie,int deplacement);


#endif