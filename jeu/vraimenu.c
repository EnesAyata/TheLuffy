#include "menu.h"


void createmenu(TTF_Font* font, SDL_Renderer* rend){
        Uint32 time;
        int x, y; //event motion
        
        bool boolMenu = false;
        
        char* label1= malloc(sizeof(char));
        char* label2= malloc(sizeof(char));
        label1 = "Play";
        label2 ="Exit";

        //load music
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music * son= Mix_LoadMUS("ressources/opening1.mp3");
    Mix_PlayMusic(son,-1);//-1 = le son joue a l'infini



        //tableau de chaines de caractères
        //printf("%s %s\n",labels[0],labels[1]);
        SDL_Surface* menu1;
        SDL_Surface* menu2;
        
        SDL_Color color1 = {255,255,255};
        SDL_Color color2={255,0,0};//couleurs blanche et rouge pour le menu
 
        menu1 = TTF_RenderText_Solid(font,label1,color1);//création TTF
        menu2 = TTF_RenderText_Solid(font,label2,color1);
        SDL_Rect pos1, pos2 ;

        bool selected=0;

        //textures du menu
        SDL_Texture* menuTex1;
        SDL_Texture* menuTex2; 
        menuTex1= SDL_CreateTextureFromSurface(rend, menu1);
        menuTex2 = SDL_CreateTextureFromSurface(rend, menu2);


        //positionnement du texte
        int menu1w, menu1h, menu2w, menu2h;
        SDL_QueryTexture(menuTex1, NULL, NULL, &menu1w, &menu1h);
        pos1.x = 640/2;
        pos1.y = 480/2;
        pos1.w = menu1w;
        pos1.h=menu1h;

        SDL_QueryTexture(menuTex2, NULL, NULL, &menu2w, &menu2h);
        pos2.x = 640/2;
        pos2.y = 275;
        pos2.w = menu2w;
        pos2.h=menu2h;

        SDL_RenderCopy(rend, menuTex1, NULL ,&pos1);
        SDL_RenderCopy(rend, menuTex2, NULL ,&pos2);
        SDL_RenderPresent(rend);
        SDL_RenderClear(rend);

       SDL_Event event;
       while(!boolMenu)
       
        {    
                
               //time = SDL_GetTicks();
                while(SDL_PollEvent(&event))
                
                        switch(event.type)
                        {
                                case SDL_QUIT:
                                        
                                        //SDL_RenderClear(rend);

                                        boolMenu=true;
                                        SDL_Quit();
              
                                  
                                        break;
                                /*case SDL_MOUSEMOTION:
                                        x = event.motion.x;
                                        y = event.motion.y;
                                        
                                        if(x>=pos1.x && x<=pos1.x+pos1.w && y>=pos1.y && y<=pos1.y+pos1.h) 
                                        {
                                                if(!selected)
         
                                                {
                                                        selected = 1;
                                                        //SDL_RenderClear(rend);                                                        
                                                        menu1 = TTF_RenderText_Solid(font,label1,color2);
                                                        menuTex1= SDL_CreateTextureFromSurface(rend, menu1);
                                                        //menuTex2 = SDL_CreateTextureFromSurface(rend, menu2);
                                                    
                                                        
                                                    
                                                }
                                                 
                                        }

                                        else
                                        {
                                                if(selected)
                                                {
                                                        selected = 0;
                                                        //SDL_RenderClear(rend);
                                                        menu1 = TTF_RenderText_Solid(font,label1,color1);
                                                        menuTex1= SDL_CreateTextureFromSurface(rend, menu1);
     
                                                      
                                                        
                                                      
                                                }
                                                 
                                        }

                                        if(x>=pos2.x && x<=pos2.x+pos2.w && y>=pos2.y && y<=pos2.y+pos2.h){
                                                if(!selected)
                                                {
                                                        selected = 1;
                                                        //SDL_RenderClear(rend);
                                                        menu2 = TTF_RenderText_Solid(font,label2,color2);
                                                        
                                                        menuTex2 = SDL_CreateTextureFromSurface(rend, menu2);
                                               
                                                        
                                                   
                                                }
                                                

                                        }

                                        else
                                        {
                                                if(selected)
                                                {
                                                        selected = 0;
                                                        //SDL_RenderClear(rend);
                                                        menu2 = TTF_RenderText_Solid(font,label2,color1);
        
                                                        menuTex2 = SDL_CreateTextureFromSurface(rend, menu2);
                                                       
                                                      
                                                }
                                                 
                                        }
                                 
                                        
                                        
                                        //SDL_RenderCopy(rend, menuTex1, &pos1, NULL);
                                        //SDL_RenderCopy(rend, menuTex2, &pos2, NULL);
                                        break;*/

                                case SDL_MOUSEBUTTONDOWN:
                                        x = event.button.x;
                                        y = event.button.y;
                                        if((x>=pos1.x && x<=pos1.x+pos1.w) && (y>=pos1.y && y<=pos1.y+pos1.h)) //|| ((x>=pos2.x && x<=pos2.x+pos2.w) && (y>=pos2.y && y<=pos2.y+pos2.h)))
                                        {
                                                //SDL_RenderClear(rend);
                                                boolMenu= true;
                                            
                                                
                                        }

                                        else if((x>=pos2.x && x<=pos2.x+pos2.w) && (y>=pos2.y && y<=pos2.y+pos2.h)){
                                                boolMenu=true;
                                                SDL_Quit();
                                        }
                                
                                        break;
                                
                        }
        }
               
                
  
        SDL_FreeSurface(menu1);
        SDL_FreeSurface(menu2);
        Mix_FreeMusic(son);
        SDL_DestroyTexture(menuTex1);
        SDL_DestroyTexture(menuTex2);

                //if(1000/30>(SDL_GetTicks()-time)){
                       // SDL_Delay(1000/30-(SDL_GetTicks()-time));
                //}
        
        
        

         
              
        
}