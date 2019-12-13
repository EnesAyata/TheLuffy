#include "feu.h"

feu_t* init_feu(SDL_Texture*tiles,SDL_Renderer* rend){
    feu_t* feu= malloc(sizeof(feu_t));
    SDL_Rect dest={0,0,25,25};
    SDL_Rect src={0,0,25,25};
    feu->Dest=dest;
    feu->rend=rend;
    feu->tiles=tiles;
    feu->Src=src;
    return feu;
}
void desallouer_feu(feu_t*feu){
    free(feu->tiles);
    free(feu->rend);
}
bool check_colli(SDL_Rect A, SDL_Rect B ){
    int gaucheA,gaucheB;
    int droitA,droitB;
    int hautA,hautB;
    int basA,basB;

    gaucheA=A.x;
    droitA=A.x+A.w;
    hautA=A.y;
    basA=A.y+A.h;
    
    gaucheB=B.x;
    droitB=B.x+B.w;
    hautB=B.y;
    basB=B.y+B.h;

    if(basA <= hautB)
        return false;
    if(hautA >= basB)
        return false;
    if(droitA<=gaucheB)
        return false;
    if(gaucheA >= droitB)
        return false;
    return true;
}

void testFeu(int x, int y,SDL_Renderer* rend){
    SDL_Texture*feuT=charger_image("ressources/feu.bmp",rend);
    SDL_Rect dest={0,0,25,25};
    SDL_Rect src={0,0,25,25};
    SDL_RenderCopy(rend,feuT,&src,&dest);
}
void launch_ball(SDL_Rect* srcI,int cas,SDL_Rect*DestEnnemi,SDL_Rect*Lanceur,SDL_Renderer* rend){
    srcI->x+=1;
    printf("Il ya collision !!!\n");
}

