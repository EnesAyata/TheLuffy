/**
 * \file map.h
 * \brief fichier header de la map
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 14 décembre 2019
 */

#include "personnage.h"

#ifndef MAP_H
#define MAP_H


/**
 * \brief allocation espace mémoire pour la création d'un tableau 2D pour la map
 * \param n longueur tableau
 * \param m largeur tableau
 * \return tableau 2D
*/
char** allouer_tab_2D(int n, int m);

/**
 * \brief affichage tableau 2D
 * \param n longueur tableau
 * \param m largeur tableau
 * \param tab tableau 2D
*/
void afficher_tab_2D(char** tab,int n,int m);

/**
 * \brief affichage map méthode tilemapping
 * \param tab tableau 2D
 * \param n longueur tableau
 * \param m largeur tableau
 * \param rend rendu final
 * \param tiles texture des tiles
 * \param perso struct du perso principal
 * \return tableau 2D
*/
char** affichage_map_tp(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles,luffy_t* perso);

/**
 * \brief affichage map méthode tilemapping
 * \param tab tableau 2D
 * \param n longueur tableau
 * \param m largeur tableau
 * \param rend rendu final
 * \param tiles texture des tiles
*/
void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles);

/**
 * \brief cree une map
 * \param tab2D tableau 2D
 * \param rend rendu final
 * \param tiles texture des tiles
 * \param luffy struct du perso principal
 * \param nomMap nom du fichier txt
 * \return une structure map_t représentant la map
*/
map_t* cree_map(char** tab2D,SDL_Renderer* rend,luffy_t*luffy,SDL_Texture*tiles,const char* nomMap);

/**
 * \brief affichage de la map par rapport à la structure map
 * \param map structure de la map
 * \param rend rendu final
 * \param tilesLuffy texture des tiles
 * \return une structure map_t représentant la map
*/
void afficher_map_struct(map_t*map,SDL_Renderer*rend,SDL_Texture*tilesLuffy);

/**
 * \brief initialisation de la structure map
 * \param map structure de la map
 */
void init_map(map_t* map);

/**
 * \brief désallocation de la mémoire attribuée à la structure de la map
 * \param map structure de la map
 */
void desallouer_map(map_t* map);
#endif