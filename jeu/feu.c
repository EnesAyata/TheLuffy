#define TFeu 25
#include "world.h"


struct feu_s {
    SDL_Texture*tiles;

    SDL_Renderer* rend;
    SDL_Rect Dest;
    SDL_Rect Src;

    

};typedef struct feu_s feu_t;


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
    //free(feu->Dest);//pas sur ici aussi ?
    //free(feu->Src);
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
/*
void animation_feu(perso_t* perso){
    
  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 100;
  Uint32 sprite = seconds % 4;
 perso->dest.x=sprite*TFeu;
}
*/
void testFeu(int x, int y,SDL_Renderer* rend){
    SDL_Texture*feuT=charger_image("ressources/feu.bmp",rend);

    SDL_Rect dest={0,0,25,25};
    SDL_Rect src={0,0,25,25};
    SDL_RenderCopy(rend,feuT,&src,&dest);


}
void launch_ball(SDL_Rect* srcI,int cas,SDL_Rect*DestEnnemi,SDL_Rect*Lanceur,SDL_Renderer* rend){
    //printf("Je rentre ici ! ????,\n");
    srcI->x+=1;
    ///if(check_colli(srcI,Lanceur)){
        //desallouer_feu(feu);
        printf("Il ya collision !!!\n");
    //}
    //SDL_Rect dest={0,0,25,25};
    //SDL_Rect src={0,0,25,25};
    //SDL_Texture*feuT=charger_image("ressources/feu.bmp",rend);
/*
    switch (cas)
    {
    case 1://droite

        //SDL_RenderCopy(feu->rend,feu->tiles,&(feu->Src),&(feu->Dest));
        /*
       while(feu->Dest->x<500 || feu->Dest->y<500){
            printf("J'entre ici ! \n");
            
            feu->Dest->x+=5;
            animation_feu(feu);
            if(feu->Dest->x>500 || feu->Dest->y>500){
                desallouer_feu(feu);//on le fait disparaitre
                break;
            }
            
        }
        printf("Il ya collision ! \n");
        desallouer_feu(feu);
        
        break;
    
    case 2:

        break;
    
    case 3:

        break;

    case 4:

        break;
    
    default:
        break;
    }
*/

}