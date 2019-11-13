#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_sdl.h"
int main(int argc, char *argv[])
{
/*/
// Test lire fichier 
int n,m;

taille_fichier("map.txt",&n,&m);
printf("taille n : %d et m: %d\n",n,m);
char** tab2D=lire_fichier("map.txt");
afficher_tab_2D(tab2D,n,m);
return 0;
*/




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
fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
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
//charger une image 
  surface = SDL_LoadBMP("sprites.bmp") ;




// Convertir la surface de l’image au format texture avant de l’appliquer
text = SDL_CreateTextureFromSurface(rend, surface);
// Copier (une partie de) la texture dans le renderer

// Récupérer les attributs d’une texture

// Charger l’image
fond = charger_image( "fond.bmp", rend);

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

 

 afficher_tab_2D(tab2D,n,m);


//SDL_Rect** tab= allouer_rect(n,m);
//tab=remplir_rect(tab2D,n,m);

//fin affich map

//test col
char** tabJ;




//fin col
// Boucle principale
while(!terminer)
{
    
while( SDL_PollEvent( &evenements ) )
SDL_RenderClear(rend);
//SDL_RenderCopy(rend, fond, NULL, NULL);

//SDL_RenderCopy(rend, obj, &SrcR, &DestR);
afficher_map(tab2D,n,m,rend,tiles);
SDL_RenderCopy(rend,luffy,&luffyR,&DestL);
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
SDL_RenderPresent(rend);
}
// Quitter SDL
SDL_DestroyTexture(fond);
SDL_DestroyTexture(text);
SDL_DestroyRenderer(rend); 
SDL_DestroyWindow(fenetre);
SDL_Quit();
return 0;

}


