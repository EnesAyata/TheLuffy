/**
 * \file menu.h
 * \brief fichier source du menu
 * \author Enes AYATA / Alpaslan GEBESOGLU
 * \version 0.1
 * \date 12 novembre 2019
 */

#include "menu.h"


int createmenu(TTF_Font* font, SDL_Renderer* rend){
        int x, y;
        SDL_Surface* fond_surface = SDL_LoadBMP("ressources/fondgame.bmp");
        SDL_Texture* fond =  SDL_CreateTextureFromSurface(rend,fond_surface);
        SDL_Rect fond_pos;
        fond_pos.x=0;
        fond_pos.y=0;
        fond_pos.w=500;
        fond_pos.h=475;
        bool boolMenu = false;
        char* label1= malloc(sizeof(char));
        char* label2= malloc(sizeof(char));
        label1 = "Play";
        label2 ="Exit";
        SDL_Surface* menu1;
        SDL_Surface* menu2;
        SDL_Color color1 = {255,255,255};
        menu1 = TTF_RenderText_Solid(font,label1,color1);
        menu2 = TTF_RenderText_Solid(font,label2,color1);
        SDL_Rect pos1, pos2; 

        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        Mix_Music * son= Mix_LoadMUS("ressources/opening1.mp3");
        Mix_PlayMusic(son,-1);

        SDL_Texture* menuTex1;
        SDL_Texture* menuTex2; 
        menuTex1= SDL_CreateTextureFromSurface(rend, menu1);
        menuTex2 = SDL_CreateTextureFromSurface(rend, menu2);

        int menu1w, menu1h, menu2w, menu2h;
        SDL_QueryTexture(menuTex1, NULL, NULL, &menu1w, &menu1h);
        pos1.x = 250;
        pos1.y = 215;
        pos1.w = menu1w;
        pos1.h=menu1h;

        SDL_QueryTexture(menuTex2, NULL, NULL, &menu2w, &menu2h);
        pos2.x = 250;
        pos2.y = 250;
        pos2.w = menu2w;
        pos2.h=menu2h;
        
        SDL_RenderCopy(rend, fond, NULL ,&fond_pos);
        SDL_RenderCopy(rend, menuTex1, NULL ,&pos1);
        SDL_RenderCopy(rend, menuTex2, NULL ,&pos2);
        
        SDL_RenderPresent(rend);
        SDL_RenderClear(rend);

       SDL_Event event;
       while(!boolMenu)
        {    
                while(SDL_PollEvent(&event))
                
                        switch(event.type)
                        {
                                case SDL_QUIT:
                                        boolMenu=true;
                                        Mix_FreeMusic(son);
                                        SDL_Quit();
                                        return 1;
                                        break;
                                case SDL_MOUSEBUTTONDOWN:
                                        x = event.button.x;
                                        y = event.button.y;
                                        if((x>=pos1.x && x<=pos1.x+pos1.w) && (y>=pos1.y && y<=pos1.y+pos1.h))
                                        {
                                                boolMenu= true;
                                                Mix_FreeMusic(son);
                                                return 2;
                                        }

                                        else if((x>=pos2.x && x<=pos2.x+pos2.w) && (y>=pos2.y && y<=pos2.y+pos2.h)){
                                                boolMenu=true;
                                                Mix_FreeMusic(son);
                                                SDL_Quit();
                                                return 1;   
                                        }
                                        break;
                                        case SDL_KEYDOWN:
                                                if(event.key.keysym.sym == SDLK_ESCAPE){
                                                        boolMenu = true;
                                                        return 1;
                                                }
                                        break;
                                
                        }
        }
        SDL_FreeSurface(menu1);
        SDL_FreeSurface(menu2);
        SDL_DestroyTexture(menuTex1);
        SDL_DestroyTexture(menuTex2);
        SDL_DestroyTexture(fond);
        SDL_DestroyRenderer(rend);
        return 2;

         
              
        
}
