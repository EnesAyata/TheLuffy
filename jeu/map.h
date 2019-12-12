#include "personnage.h"

#ifndef MAP_H
#define MAP_H

char** allouer_tab_2D(int n, int m);
void afficher_tab_2D(char** tab,int n,int m);
char** affichage_map_tp(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles,luffy_t* perso);
void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles);
map_t* cree_map(char** tab2D,SDL_Renderer* rend,luffy_t*luffy,SDL_Texture*tiles,const char* nomMap);//,Liste_t*listBf);
void afficher_map_struct(map_t*map,SDL_Renderer*rend,SDL_Texture*tilesLuffy);
void init_map(map_t* map);
void desallouer_map(map_t* map);
//void gestion_liste(Liste_t*list);








#endif