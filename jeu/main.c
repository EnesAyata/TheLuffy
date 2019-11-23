

#include "fonctions_sdl.h"
int main(int argc, char *argv[])
{

SDL_Window* fenetre; // Déclaration de la fenêtre
SDL_Event evenements; // Événements liés à la fenêtre
SDL_Renderer* rend;

SDL_Surface* surface;

SDL_Texture* text;
SDL_Texture* obj;
SDL_Texture* luffy;
SDL_Texture*tiles;




if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
{
  printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
  SDL_Quit();
  return EXIT_FAILURE;
}
// Créer la fenêtre
fenetre = SDL_CreateWindow("TheLuffy", SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);//taille dynamique avec taille fichier + erreur lors de caract nn autorisé
if(fenetre == NULL) // En cas d’erreur
{
  printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
  SDL_Quit();
  return EXIT_FAILURE;
}
//créer un conexte de rendu pr image
Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
rend = SDL_CreateRenderer(fenetre, -1, render_flags);
//charger une image 
  surface = SDL_LoadBMP("sprites.bmp") ;



  /*int main(int argc, char*argv[]){

    bool terminer = false;
    SDL_Event evenements;


    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)!=0){
        printf("Error initializing SDL: %s\n", SDL_GetError());

    }

    SDL_Window* win = SDL_CreateWindow("Bonjour",SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,640, 480, 32);*/



// Convertir la surface de l’image au format texture avant de l’appliquer
text = SDL_CreateTextureFromSurface(rend, surface);




// Charger l’image avec la transparence
Uint8 r = 255, g = 255, b = 255;
obj = charger_image_transparente("obj.bmp", rend,r,g,b);
SDL_Rect SrcR,DestR;



SrcR.x = 0;
SrcR.y = 0;
int objetW=640;
int objetH=192;
SrcR.w = objetW; // Largeur de l’objet en pixels (à récupérer)
SrcR.h = objetH; // Hauteur de l’objet en pixels (à récupérer)


DestR.x = 0;
DestR.y = 0;
DestR.w = objetW/3;
DestR.h = objetH/3;

//afficher luffy
SDL_Rect DestL;
DestL.x = 0;
DestL.y = 0;
DestL.w =38;
DestL.h = 38;

//jul
luffy = charger_image_transparente("Luffy.bmp", rend,r,g,b);

SDL_Rect luffyR= {0,0,38,38};

bool terminer = false;

//test affichage map  
int n,m;
tiles=charger_image("pavage.bmp",rend);



taille_fichier("map.txt",&n,&m);
printf("taille n : %d et m: %d\n",n,m);



//char** tab2D=allouer_tab_2D(n,m);
 char ** tab2D=lire_fichier("map.txt");
 //verif_tab(tab2D);


TTF_Init();
/*SDL_Surface *message;
SDL_Texture *txtmsg;
SDL_Rect textRect;
SDL_Color textColor ={0,0,0};*/
TTF_Font *font;

font =TTF_OpenFont("ressources/oswald.ttf", 30);



createmenu(font,rend);
    
 

 afficher_tab_2D(tab2D,n,m);


//test col
char** tabJ;


//createmenu(font,rend);


//fin col
// Boucle principale
while(!terminer)
{
    //SDL_RenderCopy(rend, txtmsg, NULL, &textRect);
    
  while( SDL_PollEvent( &evenements ) )
    SDL_RenderClear(rend);
    afficher_map(tab2D,n,m,rend,tiles);
    //createmenu(font,rend);
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
//SDL_DestroyTexture(fond);
SDL_DestroyTexture(text);
SDL_DestroyRenderer(rend); 
SDL_DestroyWindow(fenetre);
TTF_CloseFont(font);
TTF_Quit();
SDL_Quit();
return 0;

}



  



