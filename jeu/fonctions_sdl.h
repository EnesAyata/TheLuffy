
#include "collision.h"

#ifndef FONCTIONS_SDL_H
#define FONCTIONS_SDL_H





SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer) ;
void ecrire_fichier(const char* nomFichier, char** tab, int n,int m);
char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau);
char** allouer_tab_2D(int n, int m);
void desallouer_tab_2D(char**tab, int n);
void afficher_tab_2D(char** tab,int n,int m);
void taille_fichier(const char* nomFichier, int * nbLig, int* nbCol);
void deplacement_Luffy(int dep,SDL_Rect* luffy,SDL_Rect* regard, char** map);
void animation_Luffy(SDL_Rect*anim);
char** lire_fichier(const char* nomFichier);
void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles);
char** affichage_map_tp(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles,luffy_t*j);//avec la tp

void modif_tableau(char**tab,luffy_t* luffy,int n,int m);
void init_rect(SDL_Rect* SrcR,SDL_Rect* DestL);


SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b);
char** allouer_tab_2D_joueur(int n, int m);
void animation_ennemis(SDL_Rect*anim);
void deplacement_ennemis(SDL_Rect* ennemis, SDL_Rect* regard_ennemi);
void fireball_att(SDL_Rect* perso, SDL_Rect* fireball_s, SDL_Rect* fireball_dest);

#endif



