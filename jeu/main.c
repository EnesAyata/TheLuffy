#include "liste.h"
int main(int argc, char *argv[])
{
  SDL_Window* fenetre; 
  SDL_Event evenements; 
  SDL_Renderer* rend;
  SDL_Texture* fond;
  SDL_Texture* luffy;
  SDL_Texture* monstre;
  SDL_Texture* monstre_deux;
  SDL_Texture* monstre_trois;
  SDL_Texture* monstre_quatre;
  SDL_Texture*tiles;
  if(SDL_Init(SDL_INIT_VIDEO) < 0) 
  {
    printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }
  fenetre = SDL_CreateWindow("TheLuffy", SDL_WINDOWPOS_CENTERED,
  SDL_WINDOWPOS_CENTERED, 500, 475, SDL_WINDOW_RESIZABLE);
  if(fenetre == NULL)
  {
    printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  rend = SDL_CreateRenderer(fenetre, -1, render_flags);
  fond = charger_image( "ressources/bleu.bmp", rend);
  Uint8 r = 255, g = 255, b = 255;
  SDL_Rect DestL={70,100,TLuffy,TLuffy};
  luffy = charger_image_transparente("ressources/liffyR.bmp", rend,r,g,b);
  monstre = charger_image_transparente("images/chrono.bmp",rend,r,g,b);
  monstre_deux = charger_image_transparente("images/oui.bmp",rend,r,g,b);
  monstre_trois = charger_image_transparente("images/serge.bmp",rend,r,g,b);
  monstre_quatre = charger_image_transparente("images/grah.bmp",rend, r, g, b);
  SDL_Rect luffyR= {0,0,TLuffy,TLuffy};
  bool terminer = false; 
  int n,m;
  tiles=charger_image("ressources/dung.bmp",rend);
 SDL_Rect map1_mst1_src,map1_mst1_dest,map1_mst2_src,map1_mst2_dest,map1_mst3_src,map1_mst3_dest,map1_mst4_src,map1_mst4_dest;
 SDL_Rect map2_mst1_src,map2_mst1_dest,map2_mst2_src,map2_mst2_dest,map2_mst3_src,map2_mst3_dest,map2_mst4_src,map2_mst4_dest;
 SDL_Rect map3_mst1_src,map3_mst1_dest,map3_mst2_src,map3_mst2_dest,map3_mst3_src,map3_mst3_dest,map3_mst4_src,map3_mst4_dest;
  SDL_Rect map4_mst1_src,map4_mst1_dest,map4_mst2_src,map4_mst2_dest,map4_mst3_src,map4_mst3_dest,map4_mst4_src,map4_mst4_dest;
  remplir_rect(&map1_mst1_src,&map1_mst2_src,&map1_mst3_src,&map1_mst4_src,&map1_mst1_dest,&map1_mst2_dest,&map1_mst3_dest,&map1_mst4_dest);
  remplir_rect(&map2_mst1_src,&map2_mst2_src,&map2_mst3_src,&map2_mst4_src,&map2_mst1_dest,&map2_mst2_dest,&map2_mst3_dest,&map2_mst4_dest);
  remplir_rect(&map3_mst1_src,&map3_mst2_src,&map3_mst3_src,&map3_mst4_src,&map3_mst1_dest,&map3_mst2_dest,&map3_mst3_dest,&map3_mst4_dest);
  remplir_rect(&map4_mst1_src,&map4_mst2_src,&map4_mst3_src,&map4_mst4_src,&map4_mst1_dest,&map4_mst2_dest,&map4_mst3_dest,&map4_mst4_dest);
  mst_t*map1_mst1=creemst(map1_mst1_dest,map1_mst1_src);
  mst_t*map1_mst2=creemst(map1_mst2_dest,map1_mst2_src);
  mst_t*map1_mst3=creemst(map1_mst3_dest,map1_mst3_src);
  mst_t*map1_mst4=creemst(map1_mst4_dest,map1_mst4_src);

  mst_t*map2_mst1=creemst(map2_mst1_dest,map2_mst1_src);
  mst_t*map2_mst2=creemst(map2_mst2_dest,map2_mst2_src);
  mst_t*map2_mst3=creemst(map2_mst3_dest,map2_mst3_src);
  mst_t*map2_mst4=creemst(map2_mst4_dest,map2_mst4_src);

  mst_t*map3_mst1=creemst(map3_mst1_dest,map3_mst1_src);
  mst_t*map3_mst2=creemst(map3_mst2_dest,map3_mst2_src);
  mst_t*map3_mst3=creemst(map3_mst3_dest,map3_mst3_src);
  mst_t*map3_mst4=creemst(map3_mst4_dest,map3_mst4_src);

  mst_t*map4_mst1=creemst(map4_mst1_dest,map4_mst1_src);
  mst_t*map4_mst2=creemst(map4_mst2_dest,map4_mst2_src);
  mst_t*map4_mst3=creemst(map4_mst3_dest,map4_mst3_src);
  mst_t*map4_mst4=creemst(map4_mst4_dest,map4_mst4_src);

  TTF_Init();
  TTF_Font *font;
  font =TTF_OpenFont("ressources/Pokemon_Solid.ttf", 30);
  //Creation menu
  int imenu;
  imenu= createmenu(font, rend);
  if(imenu == 1){
    terminer = true;
  }
/* ***** CREATION ECRAN FIN ****/
int iecran_fin =0;
/* *************** */
  luffy_t* perso=NULL;
  perso=creation_perso(perso);
/* **************************** */
  char ** tab2DMap1=lire_fichier("level1.txt");
  char** tab2DMap2=lire_fichier("level2.txt");
  char** tab2DMap3=lire_fichier("level3.txt");
  char ** tab2DMap4=lire_fichier("map.txt");
Liste_t*listBf=initialisation();
map_t*map1=cree_map(tab2DMap1,rend,perso,tiles,"level1.txt",luffy);
map_t*map2=cree_map(tab2DMap2,rend,perso,tiles,"level2.txt",luffy);
map_t*map3= cree_map(tab2DMap3,rend,perso,tiles,"level3.txt",luffy);
map_t*map4= cree_map(tab2DMap4,rend,perso,tiles,"map.txt",luffy);
char** tab2DDeplacement;

  /****** MUSIQUE DE FOND DU JEU  ET BRUITAGE ENNEMI*/
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
  Mix_Music * son_fond= Mix_LoadMUS("ressources/musique_fond.mp3");
  Mix_PlayMusic(son_fond,-1);
  /************** ****************** ************* */

  
  /* ************** BOUCLE PRINCIPALE ************ */
  while(!terminer)
  {
  while( SDL_PollEvent( &evenements ) ){
    SDL_RenderClear(rend);
  }
    if(perso->map==1){
      tab2DDeplacement=tab2DMap1;
      afficher_map_struct(map1,rend,luffy);
      if(map1_mst1->est_affiche==1 && map1_mst2->est_affiche==1 && map1_mst3->est_affiche==1 && map1_mst4->est_affiche==1){
          detection_porte(tab2DMap1,&DestL,perso,&n,&m);
        } 
      gestion_mst(map1_mst1,map1_mst2,map1_mst3,map1_mst4,rend,monstre,listBf,perso,DestL);
      atk_luffy(listBf,rend,perso);
      }
    else if(perso->map==2){
        tab2DDeplacement=tab2DMap2;
        afficher_map_struct(map2,rend,luffy);
        if(map2_mst1->est_affiche==1 && map2_mst2->est_affiche==1 && map2_mst3->est_affiche==1 && map2_mst4->est_affiche==1){
          detection_porte(tab2DMap2,&DestL,perso,&n,&m);
        } 
        gestion_mst(map2_mst1,map2_mst2,map2_mst3,map2_mst4,rend,monstre_deux,listBf,perso,DestL);
        atk_luffy(listBf,rend,perso);
      }
      else if(perso->map==3){
        tab2DDeplacement=tab2DMap3;
        afficher_map_struct(map3,rend,luffy);
        if(map3_mst1->est_affiche==1 && map3_mst2->est_affiche==1 && map3_mst3->est_affiche==1 && map3_mst4->est_affiche==1){
          detection_porte(tab2DMap3,&DestL,perso,&n,&m);
        }
        gestion_mst(map3_mst1,map3_mst2,map3_mst3,map3_mst4,rend,monstre_trois,listBf,perso, DestL);
        atk_luffy(listBf,rend,perso);
      }
      else if(perso->map==4){
        tab2DDeplacement=tab2DMap4;
        afficher_map_struct(map4,rend,luffy);
        if(map4_mst1->est_affiche==1 && map4_mst2->est_affiche==1 && map4_mst3->est_affiche==1 && map4_mst4->est_affiche==1){
          detection_porte(tab2DMap4,&DestL,perso,&n,&m);
        }    
        gestion_mst(map4_mst1,map4_mst2,map4_mst3,map4_mst4,rend,monstre_quatre,listBf,perso, DestL);
        atk_luffy(listBf,rend,perso);
        if(map4_mst1->est_affiche==1 && map4_mst2->est_affiche==1 && map4_mst3->est_affiche==1 && map4_mst4->est_affiche==1 && iecran_fin ==0){
              ecriture_score(listBf,perso);
              iecran_fin=create_exit(font,rend);     
        }
      }
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
    printf("%d",imenu);
    if(imenu==2){
      imenu=createmenu(font,rend);
    }break;
    case SDLK_q:
      terminer = true; break;
    case SDLK_RCTRL:NewBouleFeu(listBf,&DestL,rend,perso);break;
    case SDLK_LEFT:perso->deplacement=0;deplacement_Luffy(0,&DestL,&luffyR,tab2DDeplacement);animation_Luffy(&luffyR); break;
    case SDLK_RIGHT: perso->deplacement=1;deplacement_Luffy(1,&DestL,&luffyR,tab2DDeplacement);animation_Luffy(&luffyR); break;
    case SDLK_UP:    perso->deplacement=2;deplacement_Luffy(2,&DestL,&luffyR,tab2DDeplacement);animation_Luffy(&luffyR);break;
    case SDLK_DOWN: perso->deplacement=3;deplacement_Luffy(3,&DestL,&luffyR,tab2DDeplacement);animation_Luffy(&luffyR); break;
  }
  }
  }
  ecriture_score(listBf,perso);
  freeList(listBf);
  desallouer_tab_2D(tab2DMap1,20);
  desallouer_tab_2D(tab2DMap2,20);
  desallouer_tab_2D(tab2DMap3,20);
  desallouer_tab_2D(tab2DMap4,20);
  free_mst(map1_mst1,map1_mst2,map1_mst3,map1_mst4);
  free_mst(map2_mst1,map2_mst2,map2_mst3,map2_mst4);
  free_mst(map3_mst1,map3_mst2,map3_mst3,map3_mst4);
  free_mst(map4_mst1,map4_mst2,map4_mst3,map4_mst4);
  desallouer_perso(perso);
  desallouer_map(map1);
  desallouer_map(map2);
  desallouer_map(map3);
  desallouer_map(map4);
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(luffy);
  SDL_DestroyTexture(monstre);
  SDL_DestroyTexture(monstre_deux);
  SDL_DestroyTexture(monstre_trois);
  SDL_DestroyTexture(monstre_quatre);
  SDL_DestroyTexture(tiles);
  SDL_DestroyRenderer(rend); 
  SDL_DestroyWindow(fenetre);
  TTF_CloseFont(font);
  Mix_FreeMusic(son_fond);
  TTF_Quit();
  SDL_Quit();
  return EXIT_SUCCESS;
}