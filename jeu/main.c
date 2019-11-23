

#include "fonctions_sdl.h"
int main(int argc, char *argv[])
{




  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre
  SDL_Renderer* rend;
  //SDL_FreeSurface(rend);
  SDL_Surface* surface;
  //SDL_FreeSurface(surface);
  SDL_Texture* text;
  //SDL_FreeSurface(text);
  SDL_Texture* fond;
  //SDL_FreeSurface(fond);
  SDL_Texture* obj;
  SDL_Texture* luffy;
  SDL_Texture*tiles;
  //SDL_FreeSurface(obj);
  //SDL_FreeSurface(luffy);



  if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
  {
    printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }

  // Créer la fenêtre
  fenetre = SDL_CreateWindow("TheLuffy", SDL_WINDOWPOS_CENTERED,
  SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_RESIZABLE);//taille dynamique avec taille fichier + erreur lors de caract nn autorisé
  if(fenetre == NULL) // En cas d’erreur
  {
    printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }
  //créer un conexte de rendu pr image
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  rend = SDL_CreateRenderer(fenetre, -1, render_flags);

  // Convertir la surface de l’image au format texture avant de l’appliquer
  text = SDL_CreateTextureFromSurface(rend, surface);
  // Copier (une partie de) la texture dans le renderer

  // Récupérer les attributs d’une texture

  // Charger l’image
  fond = charger_image( "ressources/bleu.bmp", rend);

  // Charger l’image avec la transparence
  Uint8 r = 255, g = 255, b = 255;//palette rgb

  //afficher luffy
  SDL_Rect DestL;
  DestL.x = 0;
  DestL.y = 0;
  DestL.w =TLuffy;
  DestL.h = TLuffy;

  //jul
  luffy = charger_image_transparente("ressources/luffy.bmp", rend,r,g,b);

  SDL_Rect luffyR= {0,0,TLuffy,TLuffy};

  bool terminer = false;

  //test affichage map  
  int n,m;
  tiles=charger_image("ressources/dung.bmp",rend);



  taille_fichier("map.txt",&n,&m);
  printf("taille n : %d et m: %d\n",n,m);



  //char** tab2D=allouer_tab_2D(n,m);
  char ** tab2D=lire_fichier("map.txt");
  //verif_tab(tab2D);


  TTF_Init();
  SDL_Surface *message;
  SDL_Texture *txtmsg;
  SDL_Rect textRect;
  SDL_Color textColor ={0,0,0};
  TTF_Font *font;

  font =TTF_OpenFont("ressources/arial.ttf", 30);

  message = TTF_RenderText_Solid(font, "Enes le plus beau", textColor);
  //txtmsg= SDL_CreateTextureFromSurface(rend,message);
  textRect.x = 50;
  textRect.y= 150;
  //SDL_BlitSurface(message,NULL,surface,&textRect);
  //createmenu(surface, font, rend);
      
  

  afficher_tab_2D(tab2D,n,m);
  




  //SDL_Rect** tab= allouer_rect(n,m);
  //tab=remplir_rect(tab2D,n,m);

  //fin affich map

  //test col


  createmenu(font,rend);


  //fin col
  // Boucle principale
  while(!terminer)
  {
      //SDL_RenderCopy(rend, txtmsg, NULL, &textRect);
      
    while( SDL_PollEvent( &evenements ) )
    SDL_RenderClear(rend);
    afficher_map(tab2D,n,m,rend,tiles);
    
    SDL_RenderCopy(rend,luffy,&luffyR,&DestL);


    SDL_RenderPresent(rend);
    switch(evenements.type)
  {
    case SDL_QUIT:
      terminer = true; break;
    case SDL_KEYDOWN:
      switch(evenements.key.keysym.sym)
  {
    case SDLK_ESCAPE:
    case SDLK_q:
      terminer = true; break;
  }

  switch (evenements.key.keysym.sym)
  {
    case SDLK_LEFT:  deplacement_Luffy(0,&DestL,&luffyR);animation_Luffy(&luffyR); break;
    case SDLK_RIGHT: deplacement_Luffy(1,&DestL,&luffyR);animation_Luffy(&luffyR);  break;
    case SDLK_UP:    deplacement_Luffy(2,&DestL,&luffyR);animation_Luffy(&luffyR);  break;
    case SDLK_DOWN:  deplacement_Luffy(3,&DestL,&luffyR);animation_Luffy(&luffyR);  break;
  }

  }

  }
  // Quitter SDL
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(text);
  SDL_DestroyRenderer(rend); 
  SDL_DestroyWindow(fenetre);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
  return 0;

}



  



