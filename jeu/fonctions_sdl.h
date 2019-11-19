#include "menu.h"

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer) ;
void ecrire_fichier(const char* nomFichier, char** tab, int n,int m);
char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau);
char** allouer_tab_2D(int n, int m);
void desallouer_tab_2D(char**tab, int n);
void afficher_tab_2D(char** tab,int n,int m);
void taille_fichier(const char* nomFichier, int * nbLig, int* nbCol);
void deplacement_Luffy(int dep,SDL_Rect* luffy,SDL_Rect* regard);
void animation_Luffy(SDL_Rect*anim);
char** lire_fichier(const char* nomFichier);
void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles);
SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b) ;

int detection_col(char** tabJ,char** map,SDL_Rect* luffy,int direction);
char** allouer_tab_2D_joueur(int n, int m);

