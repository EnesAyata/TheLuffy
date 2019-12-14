/**
 * \file feu.h
 * \brief fichier header de la boule de feu
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 14 décembre 2019
 */


#ifndef FEU_H
#define FEU_H
#include "map.h"

#define TFeu 25 /** Taille de la boule de feu */


 /**
 * \brief Structure de la boule de feu
 */
struct feu_s {
    SDL_Texture*tiles;
    SDL_Renderer* rend;
    SDL_Rect Dest;
    SDL_Rect Src;

    

};typedef struct feu_s feu_t;


/**
 * \brief initialise la structure de la boule de feu
 * \param tiles tiles de la map
 * \param rend rendu final
 * \return struct feu_t représentant la boule de feu
 */
feu_t* init_feu(SDL_Texture*tiles,SDL_Renderer* rend);

/**
 * \brief désallocation espace mémoire attribuée au struct feu_t
 * \param feu struct feu_t
 */
void desallouer_feu(feu_t*feu);

/**
 * \brief Procédure vérifiant la collision entre deux SDL_Rect
 * \param a premier SDL_Rect
 * \param b deuxième SDL_Rect
 * \return true si les deux SDL_Rect se touchent, false sinon
 */
bool check_colli(SDL_Rect A, SDL_Rect B );

/**
 * \brief Procédure de test de la boule de feu
 * \param x abscisse de la boule de feu
 * \param y ordonnée de la boule de feu
 * \param rend rendu final
 */
void testFeu(int x, int y,SDL_Renderer* rend);

/**
 * \brief Procédure de lancement de boule de feu
 * \param srcI SDL_Rect source
 * \param cas variable représentant les différents cas
 * \param DestEnnemi SDL_Rect dest de l'ennemi
 * \param Lanceur sdl_rect du lanceur de boules de feu
 * \param rend rendu final
 */
void launch_ball(SDL_Rect* srcI,int cas,SDL_Rect*DestEnnemi,SDL_Rect*Lanceur,SDL_Renderer* rend);




#endif