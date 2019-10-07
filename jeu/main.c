#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL_ttf.h>




//test 

  int main(int argc, char*argv[]){

      SDL_Rect position;
      if (SDL_Init(SDL_INIT_VIDEO)!=0){
          printf("Error initializing SDL: %s\n", SDL_GetError());

      }
    
    SDL_Window* win = SDL_CreateWindow("Bonjour",SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,640, 480, 0);

    if(!win){
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    
  
    //load renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    
     //load image
    SDL_Surface* surface = SDL_LoadBMP("Luffy.bmp") ;

    if(!surface){
        printf("erreur surface %s\n", SDL_GetError());
    }
    //load image data
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

    
    
    TTF_Font * police = NULL;
    SDL_Color couleurNoire = {255, 255, 255};
    TTF_Init();
    SDL_VM_SetCaption("Gestion du texte avec SDL_ttf", NULL);
    police = TTF_OpenFont("angelina.ttf",65);
    texte = TTF_RenderText_Blended(police, "Salut", couleurNoire).

    position.x = 60;
    position.y = 300;
    SDL_BlitSurface(texte, NULL, win, &position);
    
    SDL_FreeSurface(surface);


        
    //clear the window
    SDL_RenderClear(rend);

    //draw the image to the window
    SDL_RenderCopy(rend, tex, NULL,NULL);
    SDL_RenderPresent(rend);


    SDL_Delay(10000);


    

  


    //clean up resources before exiting
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);    
    SDL_DestroyWindow(win);
    SDL_Quit();
      
    return 0;
      
    
  }

  //gcc jeu/main.c -o bin/game -I include -L lib -lmingw32 -lSDL2main -lSDL2