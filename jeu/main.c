


#include "map.h"
int main(int argc, char *argv[])
{




  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre
  SDL_Renderer* rend;
  //SDL_FreeSurface(rend);
  //SDL_Surface* surface;
  //SDL_FreeSurface(surface);
  //SDL_Texture* text;
  //SDL_FreeSurface(text);
  SDL_Texture* fond;
  //SDL_FreeSurface(fond);
  //SDL_Texture* obj;
  SDL_Texture* luffy;
  SDL_Texture* monstre;
  SDL_Texture* fireball;
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
  SDL_WINDOWPOS_CENTERED, 500, 475, SDL_WINDOW_RESIZABLE);//taille dynamique avec taille fichier + erreur lors de caract nn autorisé
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
  //text = SDL_CreateTextureFromSurface(rend, surface);
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

  //afficher Monstre
  SDL_Rect DestM;
  DestM.x = 100;
  DestM.y = 100;
  DestM.w =TLuffy;
  DestM.h = TLuffy;


  //chargement sprite luffy
  luffy = charger_image_transparente("ressources/liffyR.bmp", rend,r,g,b);

  //chargement sprite monstre
  monstre = charger_image_transparente("images/chrono.bmp",rend,r,g,b);



  SDL_Rect luffyR= {0,0,TLuffy,TLuffy};
  SDL_Rect monstreR={100,100,TLuffy,TLuffy};

  bool terminer = false;

  //test affichage map  
  int n,m;
  tiles=charger_image("ressources/dung.bmp",rend);



  taille_fichier("map.txt",&n,&m);
  printf("taille n : %d et m: %d\n",n,m);



  //char** tab2D=allouer_tab_2D(n,m);
  //verif_tab(tab2D);


  TTF_Init();
  TTF_Font *font;
  font =TTF_OpenFont("ressources/oswald.ttf", 30);
  createmenu(font, rend);
      
      
  

  /* Test création de l'attaque fireball */

  //afficher attaque 
  SDL_Rect DestF;
  DestF.x = 0;
  DestF.y = 0;
  DestF.w =10;
  DestF.h = 10;

   //chargement sprite attaque
  fireball = charger_image_transparente("ressources/fireball.bmp",rend,r,g,b);


  SDL_Rect fireballR= {0,0,10,10};

  




  //test création luffy 
  luffy_t* perso;
  perso=creation_perso(perso);
  afficherL(perso);

  char ** tab2D=lire_fichier("map.txt");//modif_tableau(tab2D,perso);//=lire_fichier("map.txt");
      //tab2D =affichage_map_tp(tab2D,n,m,rend,tiles,perso);

    //afficher_tab_2D(tab2D,n,m);





  //fin col
  // Boucle principale
  while(!terminer)
  {
      //SDL_RenderCopy(rend, txtmsg, NULL, &textRect);
      
    while( SDL_PollEvent( &evenements ) )
    SDL_RenderClear(rend);
    tab2D=affichage_map_tp(tab2D,n,m,rend,luffy,perso);
    afficher_map(tab2D,n,m,rend,tiles);
    deplacement_ennemis(&DestM,&monstreR);
    animation_ennemis(&monstreR);   
    detection_porte(tab2D,&DestL,perso,&n,&m);  
    //tab2D=affichage_map_tp(tab2D,&n,&m,rend,luffy,perso);

    SDL_RenderCopy(rend,luffy,&luffyR,&DestL);
    SDL_RenderCopy(rend,monstre,&monstreR,&DestM);
    SDL_RenderCopy(rend,fireball,&fireballR,&DestF);
    //deplacement_ennemies(&luffyR,&DestM);


    SDL_RenderPresent(rend);
    switch(evenements.type)
  {
    case SDL_QUIT:
      terminer = true; break;
    case SDL_KEYDOWN:
      switch(evenements.key.keysym.sym)
  {
    case SDLK_ESCAPE:
      createmenu(font, rend); break;
    case SDLK_q:
      terminer = true; break;
  }
   

  switch (evenements.key.keysym.sym)

  {
    case SDLK_LEFT:  deplacement_Luffy(0,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); break;
    case SDLK_RIGHT: deplacement_Luffy(1,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); break;
    case SDLK_UP:    deplacement_Luffy(2,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR);break;
    case SDLK_DOWN:  deplacement_Luffy(3,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); break;
    
    
  }


  }

  }
  // Quitter SDL
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(luffy);
  SDL_DestroyTexture(monstre);
  //SDL_DestroyTexture(text);
  SDL_DestroyTexture(tiles);
  SDL_DestroyTexture(luffy);
  SDL_DestroyRenderer(rend); 
  SDL_DestroyWindow(fenetre);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
  return EXIT_SUCCESS;
}





  



