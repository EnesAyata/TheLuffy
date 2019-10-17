#ifndef WORLD_H
#define WORLD_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>


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
 * \brief Taille du bonhomme (sprite)
 */
#define SPRITE_SIZE 32





 /**
 * \brief Structure du sprite pricipal
 */
 struct sprite_s {
     double sprite_x;
     double sprite_y;
 };
 typedef struct sprite_s sprite_t;


 /**
 * \brief Structure du world
 */
struct world_s{
    SDL_Surface* background;
    SDL_Surface* img_sprite;
};
typedef struct world_s world_t;

SDL_Surface* load_image(char path[]);



 #endif