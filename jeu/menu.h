/**
 * \file world.h
 * \brief fichier header du monde pricipal
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 14 décembre 2019
 */


#include"world.h"

#ifndef MENU_H
#define MENU_H

/**
 * \file menu.h
 * \brief fichier header du menu
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 12 novembre 2019
 */


 /**
 * \brief Procédure affichant le menu
 * \param font font TTF
 * \param rend rendu final
 * \return un entier étarminant l'état du menu
 */
int createmenu( TTF_Font* font, SDL_Renderer* rend);

/**
 * \brief Procédure affichant l'écran de fin
  * \param font font TTF
 * \param rend rendu final
 * \return un entier étarminant l'état de l'écran de fin
 */
int create_exit(TTF_Font* font, SDL_Renderer* rend);


#endif