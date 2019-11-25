#include "collision.h"

#ifndef PERSONNE_H
#define PERSONNE_H



void detection_porte(char** map,SDL_Rect* luffy,luffy_t* personnage,int* n,int* m);
luffy_t* creation_perso(luffy_t* j);
void desallouer_perso(luffy_t* perso);
void afficherL(luffy_t *perso);



#endif