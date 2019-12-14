/**
 * \file personnage.h
 * \brief fichier header du perso principal
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 14 décembre 2019
 */

#include "fonctions_sdl.h"

#ifndef PERSONNE_H
#define PERSONNE_H


/**
 * \brief permet de savoir si le perso entre dans une porte
 * \param map tableau 2D de la map
 * \param luffy  SDL_RECT* perso principal
 * \param PERSONNAGE PERSO PRINCIPAL
 * \param n longueur du tableau
 * \param m largeur du tableau
 */
void detection_porte(char** map,SDL_Rect* luffy,luffy_t* personnage,int* n,int* m);

/**
 * \brief creation perso
 * \param j perso non initalisé
 * \return luffy_t* soit le struct du perso principal
 */
luffy_t* creation_perso(luffy_t* j);

/**
 * \brief libérer la mémoire urilisé par le perso
 * \param perso perso initialisé
 */
void desallouer_perso(luffy_t* perso);

/**
 * \brief affiche le perso principal 
 * \param perso perso initialisé
 */
void afficherL(luffy_t *perso);



#endif