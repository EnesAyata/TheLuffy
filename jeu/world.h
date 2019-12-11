#ifndef WORLD_H
#define WORLD_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include<math.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <time.h>


/**
 * \file world.h
 * \brief fichier header du monde pricipal
 * \author Enes AYATA
 * \version 0.1
 * \date 16 octobre 2019
 */

/**
 * \brief Largeur de l'écran de jeu
 */
#define SCREEN_WIDTH 640

/**
 * \brief Hauteur de l'écran de jeu
 */
#define SCREEN_HEIGHT 480
/**
 * \brief Moving step
 */
 #define MOVING_STEP 5


#define TLuffy 25

#define luffyLarg 5
#define LuffyHaut 4
#define LargMap 500
#define HautMap 500
#define TailleTiles 25
#define NbTilesLargeur 10
#define NbTilesHauteur 10



 /**
 * \brief Structure du sprite pricipal (luffy)
 */
 struct luffy_s {
     int map;//la map ou est luffy
     int vie;//les pdv de luffy
     int atk;//l'atk de luffy
     int experience;//l'xp de luffy
     int argent;//l'argent de luffy
 };
 typedef struct luffy_s luffy_t;


struct map_s {
    SDL_Texture*tiles;
    char**tab2D;
    int lig;
    int col;
    SDL_Renderer* rend;
    luffy_t* luffy;

};
typedef struct map_s map_t;
 /**
 * \brief Structure du world
 */
 /**
 * \brief Structure du world
 */
/*struct luffy_s{
    int vie;//vie de luffy
    int map;//map sur laquelle est luffy

};
typedef struct world_s world_t;*/

//map
typedef unsigned char tileindex; 
 
typedef struct 
{ 
    SDL_Rect R; 
    int plein; 
} TileProp; 

typedef struct 
{ 
    int LARGEUR_TILE,HAUTEUR_TILE; 
    int nbtilesX,nbtilesY; 
    SDL_Surface* tileset; 
    TileProp* props; 
    tileindex** schema; 
    int nbtiles_largeur_monde,nbtiles_hauteur_monde; 
} Map;


SDL_Surface* load_image(char path[]);



 #endif