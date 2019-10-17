#include "world.h"





//test 

  int main(int argc, char*argv[]){

      

    bool terminer = false;
    SDL_Event evenements;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)!=0){
        printf("Error initializing SDL: %s\n", SDL_GetError());

    }
    
        
        SDL_Window* win = SDL_CreateWindow("Bonjour",SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,640, 480, 32);


    if(!win){
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    
    //load music
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music * son= Mix_LoadMUS("ressources/opening.mp3");

    //load renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    
     //load image
    SDL_Surface* surface = IMG_Load("ressources/Luffy.png") ;

    if(!surface){
        printf("erreur surface %s\n", SDL_GetError());
    }
    //load image data
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    
    //play music
    Mix_PlayMusic(son,-1);
    SDL_FreeSurface(surface);


        
    //clear the window
    SDL_RenderClear(rend);


    //draw the image to the window
    SDL_RenderCopy(rend, tex, NULL,NULL);
    SDL_RenderPresent(rend);


    //boucle principale
    while(!terminer){
        while(SDL_PollEvent(&evenements))
            switch(evenements.type){
                case SDL_QUIT:
                    terminer = true; break;
                case SDL_KEYDOWN:
                switch(evenements.key.keysym.sym){
                    case SDLK_ESCAPE:
                    case SDLK_s:
                        terminer = true; break;
                }
            }

    }


    //clean up resources before exiting
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);    
    SDL_DestroyWindow(win);
    Mix_FreeMusic(son);
    SDL_Quit();
      
    return EXIT_SUCCESS;
      
    
  }