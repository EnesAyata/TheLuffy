#include "personnage.h"
#ifndef MAP_H
#define MAP_H

char** allouer_tab_2D(int n, int m);
void afficher_tab_2D(char** tab,int n,int m);
char** affichage_map_tp(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles,luffy_t* perso);
void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles);







#endif