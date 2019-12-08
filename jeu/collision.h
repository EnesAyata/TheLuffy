#ifndef COLLISION_H
#define COLLISION_H
#include "menu.h"


/**
 * \brief : détéction d'une collision entre un tile et le perso principal
 * \param luffy SDL_Rect* du perso principal Luffy
 * \param map carte du jeu
 * \param dep type de déplacement
 * \return 1 s'il y a une collision, 0 sinon
*/
int detect_col(SDL_Rect* luffy,char** map,int dep);





#endif 
