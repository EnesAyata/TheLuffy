/**
 * \file fonctions_sdl.h
 * \brief fichier header du fichier des pricipales fonctions polyvalentes
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 12 novembre 2019
 */
#include "collision.h"

#ifndef FONCTIONS_SDL_H
#define FONCTIONS_SDL_H



/**
 * \brief : chargement d'une image au format SDL_Texture
 * \param nomFichier Nom du fichier
 * \param renderer Rendu général du jeu
 * \return l'image au format SDL_Texture*
*/
SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer) ;

/**
 * \brief : ecrire un fichier txt via le code
 * \param nomFichier Nom du fichier
 * \param tab tableau de caractères à deux dimensions
 * \param n taille du tableau en longueur
 * \param m taille du tableau en largeur
*/
void ecrire_fichier(const char* nomFichier, char** tab, int n,int m);

/**
 * \brief : changement d'un élément du tableau à deux dimensions
 * \param tab tableau de caractères à deux dimensions
 * \param n taille du tableau en longueur
 * \param m taille du tableau en largeur
 * \param ancien caractère à substituer
 * \param nouveau caractère substituant
 * \return le nouveau tableau de char à deux dimensions
*/
char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau);

/**
 * \brief : allocation mémoire d'un tableau à deux dimensions
 * \param n taille du tableau en longueur
 * \param m taille du tableau en largeur
 * \return le tableau alloué
*/
char** allouer_tab_2D(int n, int m);

/**
 * \brief : libération de la mémoire d'un tableau à deux dimensions
 * \param tab tableau à desallouer
 * \param n taille du tableau en longueur
*/
void desallouer_tab_2D(char**tab, int n);

/**
 * \brief : affichage du tableau à deux dimensions
 * \param tab tableau à afficher
 * \param n taille du tableau en longueur
 * \param m taille du tableau en largeur
*/
void afficher_tab_2D(char** tab,int n,int m);

/**
 * \brief : taille du fichier txt
 * \param nomFichier nom du fichier
 * \param nbLig nombre de lignes du fichier txt
 * \param nbCol nombre de colonnes du fichier txt
*/
void taille_fichier(const char* nomFichier, int * nbLig, int* nbCol);

/**
 * \brief : procédure gérant les déplacements du perso principal Luffy
 * \param dep int definissant le type du deplacement
 * \param luffy SDL_Rect* source du sprite
 * \param regard SDL_Rect* destination du sprite, déplacement réaliste
 * \param map map du projet
*/
void deplacement_Luffy(int dep,SDL_Rect* luffy,SDL_Rect* regard, char** map);

/**
 * \brief : procédure gérant l'animation du perso principal
 * \param anim SDL_Rect* du perso principal
*/
void animation_Luffy(SDL_Rect*anim);

/**
 * \brief : lecture du fichier txt
 * \param nomFichier nom du fichier
 * \param nbLig nombre de lignes du fichier txt
 * \return le tableau à 2 dimensions représentant le fichier txt
*/
char** lire_fichier(const char* nomFichier);

/**
 * \brief : affichage de la map
 * \param tab tableau à deux dimensions
 * \param n nombre de lignes du tableau 
 * \param m nombre de colonnes du tableau 
 * \param rend rendu général du projet
 * \param tiles texture représentant les tiles de la map
*/
void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles);
char** affichage_map_tp(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles,luffy_t*j);//avec la tp

/**
 * \brief : modification du tableau à deux dimensions
 * \param tab tableau à deux dimensions
 * \param luffy pointeur de la structure représentant Luffy
 * \param n nombre de lignes du fichier txt
 * \param m nombre de colonnes du fichier txt
*/
void modif_tableau(char**tab,luffy_t* luffy,int n,int m);

/**
 * \brief : initialisation d'un SDL_Rect*
 * \param srcR SDL_Rect* source
 * \param DestL SDL_Rect* destination
*/
void init_rect(SDL_Rect* SrcR,SDL_Rect* DestL);

/**
 * \brief : charger une image transparente
 * \param nomFichier nom du fichier image
 * \param rend rendu général du projet
 * \param r entier non signé sur 8 bits représentant le rouge (code RGB)
 * \param g entier non signé sur 8 bits représentant le vert (code RGB)
 * \param b entier non signé sur 8 bits représentant le bleu (code RGB)
 * \return l'image en SDL_Texture*
*/
SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b);

/**
 * \brief : allocation mémoire pour un tableau à deux dimensions pour le joueur
 * \param n nombre de lignes à allouer
 * \param m nombre de colonnes à allouer
 * \return un tableau alloué à deux dimensions 
*/
char** allouer_tab_2D_joueur(int n, int m);

/**
 * \brief : animation des ennemis lors de leurs déplacement
 * \param anim SDL_Rect* source de l'ennemi
*/
void animation_ennemis(SDL_Rect*anim);

/**
 * \brief : déplacement du premier ennemi
 * \param ennemis SDL_Rect* source
 * \param regard_ennemi SDL_Rect* destination par rapport au type de déplacement
*/
void deplacement_ennemis(SDL_Rect* ennemis, SDL_Rect* regard_ennemi);

/**
 * \brief : déplacement du deuxième ennemi
 * \param ennemis SDL_Rect* source
 * \param regard SDL_Rect* destination par rapport au type de déplacement
*/
void deplacement_ennemis_deux(SDL_Rect* ennemis, SDL_Rect* regard);

/**
 * \brief : déplacement du troisième ennemi
 * \param ennemis SDL_Rect* source
 * \param regard SDL_Rect* destination par rapport au type de déplacement
*/
void deplacement_ennemis_trois(SDL_Rect* ennemis, SDL_Rect* regard);

void deplacement_ennemis_quatre(SDL_Rect* ennemis, SDL_Rect* regard);
/**
 * \brief : collision entre deux persos
 * \param perso SDL_Rect* Luffy
 * \param ennemis SDL_Rect* ennemi quelconque
*/
void collisions_persos(SDL_Rect* perso,SDL_Rect* perso_dest, SDL_Texture* perso_texture, SDL_Renderer* rend, SDL_Rect* ennemis);




#endif



