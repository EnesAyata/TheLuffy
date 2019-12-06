

#include "fonctions_sdl.h"
#include "personnage.h"
#include "map.h"
//#include "feu.c"//test avec feu juste sans include rien
//#include "liste.c"//enlever include la
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
  SDL_Texture* mario;
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
  DestL.x = 70;
  DestL.y = 100;
  DestL.w =TLuffy;
  DestL.h = TLuffy;

  //afficher Mario
  SDL_Rect DestM;
  DestM.x = 100;
  DestM.y = 100;
  DestM.w =TLuffy;
  DestM.h = TLuffy;


  //chargement sprite luffy
  luffy = charger_image_transparente("ressources/liffyR.bmp", rend,r,g,b);

  //chargement sprite mario
  mario = charger_image_transparente("images/chrono.bmp",rend,r,g,b);



  SDL_Rect luffyR= {0,0,TLuffy,TLuffy};
  SDL_Rect marioR={100,100,TLuffy,TLuffy};

  bool terminer = false;

  //test affichage map  
  int n,m;
  tiles=charger_image("ressources/dung.bmp",rend);



  taille_fichier("map.txt",&n,&m);
  printf("taille n : %d et m: %d\n",n,m);



  //char** tab2D=allouer_tab_2D(n,m);
  //verif_tab(tab2D);


  TTF_Init();
  //SDL_Surface *message;
  //SDL_Texture *txtmsg;
  //SDL_Rect textRect;
  //SDL_Color textColor ={0,0,0};
  TTF_Font *font;

  font =TTF_OpenFont("ressources/oswald.ttf", 30);

  //message = TTF_RenderText_Solid(font, "Enes le plus beau", textColor);
  //txtmsg= SDL_CreateTextureFromSurface(rend,message);
  //textRect.x = 50;
  //textRect.y= 150;
  //SDL_BlitSurface(message,NULL,surface,&textRect);



  createmenu(font, rend);

      
  

  




  //SDL_Rect** tab= allouer_rect(n,m);
  //tab=remplir_rect(tab2D,n,m);

  //fin affich map

  //test col

  //createmenu(font,rend);

  //test création luffy 
  luffy_t* perso;
  perso=creation_perso(perso);
  afficherL(perso);

  char ** tab2D=lire_fichier("map.txt");//modif_tableau(tab2D,perso);//=lire_fichier("map.txt");
      //tab2D =affichage_map_tp(tab2D,n,m,rend,tiles,perso);

    //afficher_tab_2D(tab2D,n,m);

//cree une boule de feu (l'init); //test pour bouyle de feu 
/*
SDL_Texture*feu=charger_image("ressources/feu.bmp",rend);
//SDL_Texture*feu=charger_image_transparente("ressources/feu.bmp",rend,r,g,b);
//feu_t*feuAtk=init_feu(feu,rend);
  SDL_Rect bouleFeuDest= {0,0,25,25};
  SDL_Rect bouleFeuSrc= {0,0,25,25};
Liste_t*listBf=initialisation();
perso_t*boule1=creeEntite(bouleFeuSrc,bouleFeuDest,feu,10);
bouleFeuDest.x+=25;
bouleFeuDest.y+=25;
perso_t*boule2=creeEntite(bouleFeuSrc,bouleFeuDest,feu,2);
insertion(listBf,boule1);
insertion(listBf,boule2);


perso_t*actuel;

afficherListe(listBf);*/
int i=0;

  //fin co
  // Boucle principale
  while(!terminer)
  {
      //SDL_RenderCopy(rend, txtmsg, NULL, &textRect);
      
    while( SDL_PollEvent( &evenements ) )
    SDL_RenderClear(rend);
    tab2D=affichage_map_tp(tab2D,n,m,rend,luffy,perso);
    afficher_map(tab2D,n,m,rend,tiles);
    deplacement_ennemis(&DestM,&marioR);
    animation_ennemis(&marioR);   
    detection_porte(tab2D,&DestL,perso,&n,&m);  
    //tab2D=affichage_map_tp(tab2D,&n,&m,rend,luffy,perso);
    //SDL_RenderCopy(feuAtk->rend,feuAtk->tiles,&(feuAtk->Src),&(feuAtk->Dest));
    //animation_feu(feuAtk);
    //feuAtk->Dest.x+=1;

    //testFeu(0,0,rend);
    SDL_RenderCopy(rend,luffy,&luffyR,&DestL);
    SDL_RenderCopy(rend,mario,&marioR,&DestM);
    //SDL_RenderCopy(rend,listBf->premier->sprite,&listBf->premier->src,&boule2->dest);

    //deplacement_ennemies(&luffyR,&DestM);


    
      //perso_t* bf=creeEntite(feuAtk->Src,feuAtk->Dest,feuAtk->tiles);
      //SDL_RenderCopy(rend,listBf->premier->sprite,&listBf->premier->src,&listBf->premier->dest);
     //TEST AFFICHER BOULE DE FEU DANS LE JEU 
     /*
      if(listBf->lenght!=0)
        actuel=listBf->premier;
      if(check_colli(actuel->dest,DestL)|| listBf->lenght==0){
            supprimer(listBf,actuel);
            //desallouer_feu(feuAtk);
        }
        else{
        
        animation_feu(actuel);
        SDL_RenderCopy(rend,feu,&actuel->src,&actuel->dest);
        actuel->dest.x+=1;
        actuel=actuel->suivant;
        }
        */
      //launch_ball(&(actuel->dest),1,&DestL,&DestL,rend);
      /*
      while(actuel->suivant!=NULL){
        actuel->suivant=actuel;
        if(check_colli(actuel->dest,DestL)){
            supprimer(listBf,actuel);
            //desallouer_feu(feuAtk);
        }
              //printf("je rentre ici aiiso \n");
        else{SDL_RenderCopy(rend,actuel->sprite,&actuel->src,&actuel->dest);
        
        actuel->dest.x+=1;}
          //printf("Il ya colli! \n");
          //supprimer(listBf,actuel);
      
        //launch_ball(&(actuel->dest),1,&DestL,&DestL,rend);
        //actuel=actuel->suivant;
      }
      */
  
     /*
     printf("length %d\n",listBf->lenght);
     //printf("vie du prems : %d\n et vie du suivant %d\n",listBf->premier->vie,listBf->premier->suivant->vie);
       for(int i=1;i<=listBf->lenght;i++){
         printf("je rentre ici\n");/*
         if(i==0){
           actuel=listBf->premier;
         }
         else{actuel=actuel->suivant;}
         SDL_RenderCopy(rend,actuel->sprite,&actuel->src,&actuel->dest);
         animation_feu(actuel);
         actuel->dest.x+=1;
         if(!(check_colli(actuel->dest,DestL))){
            supprimer(listBf,actuel);
            //perso_t* bf=creeEntite(feuAtk->Src,feuAtk->Dest,feuAtk->tiles,40);
            //desallouer_feu(feuAtk);
        }
        actuel=listBf->premier;
        SDL_RenderCopy(rend,actuel->sprite,&actuel->src,&actuel->dest);
        if(check_colli(actuel->dest,DestL)){
            printf("Il y a colli\n");supprimer(listBf,actuel);
            //perso_t* bf=creeEntite(feuAtk->Src,feuAtk->Dest,feuAtk->tiles,40);
            //desallouer_feu(feuAtk);
        }

       }*/
        
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
    //case SDLK_RCTRL:insertion(listBf,boule2);break;

    case SDLK_LEFT:/*launch_ball(feuAtk,1,&DestM,&DestL,rend)*/;deplacement_Luffy(0,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); /*deplacement_Luffy(0,&DestM,&marioR,tab2D);animation_ennemis(&marioR); deplacement_ennemis(&DestM,&marioR);*/break;
    case SDLK_RIGHT: deplacement_Luffy(1,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); /*deplacement_Luffy(1,&DestM,&marioR,tab2D);animation_ennemis(&marioR); deplacement_ennemis(&DestM,&marioR);*/break;
    case SDLK_UP:    deplacement_Luffy(2,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR);/*deplacement_Luffy(2,&DestM,&marioR,tab2D);animation_ennemis(&marioR);deplacement_ennemis(&DestM,&marioR);*/break;
    case SDLK_DOWN: deplacement_Luffy(3,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); /*deplacement_Luffy(3,&DestM,&marioR,tab2D) ;animation_ennemis(&marioR);deplacement_ennemis(&DestM,&marioR);*/break;

  }



  }
 
  }
  // Quitter SDL
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(luffy);
  SDL_DestroyTexture(mario);
  //SDL_DestroyTexture(text);
  SDL_DestroyTexture(tiles);
  //SDL_DestroyTexture(luffy);
  SDL_DestroyRenderer(rend); 
  SDL_DestroyWindow(fenetre);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
  return EXIT_SUCCESS;
}





  



