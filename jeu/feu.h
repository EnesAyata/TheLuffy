#ifndef FEU_H
#define FEU_H
#include "map.h"

#define TFeu 25

struct feu_s {
    SDL_Texture*tiles;
    SDL_Renderer* rend;
    SDL_Rect Dest;
    SDL_Rect Src;

    

};typedef struct feu_s feu_t;

feu_t* init_feu(SDL_Texture*tiles,SDL_Renderer* rend);
void desallouer_feu(feu_t*feu);
bool check_colli(SDL_Rect A, SDL_Rect B );
void testFeu(int x, int y,SDL_Renderer* rend);
void launch_ball(SDL_Rect* srcI,int cas,SDL_Rect*DestEnnemi,SDL_Rect*Lanceur,SDL_Renderer* rend);




#endif