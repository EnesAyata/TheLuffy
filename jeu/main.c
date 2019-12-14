
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

  // Créer la fenêtre

  fenetre = SDL_CreateWindow("TheLuffy", SDL_WINDOWPOS_CENTERED,
  SDL_WINDOWPOS_CENTERED, 500, 475, SDL_WINDOW_RESIZABLE);//taille dynamique avec taille fichier + erreur lors de caract nn autorisé
  if(fenetre == NULL)
  {
    printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  rend = SDL_CreateRenderer(fenetre, -1, render_flags);

  fond = charger_image( "ressources/bleu.bmp", rend);
  Uint8 r = 255, g = 255, b = 255;//palette rgb

  SDL_Rect DestL;
  DestL.x = 70;
  DestL.y = 100;
  DestL.w =TLuffy;
  DestL.h = TLuffy;

  


  /* *********************************************** */

  luffy = charger_image_transparente("ressources/liffyR.bmp", rend,r,g,b);

  monstre = charger_image_transparente("images/chrono.bmp",rend,r,g,b);
  monstre_deux = charger_image_transparente("images/oui.bmp",rend,r,g,b);
  monstre_trois = charger_image_transparente("images/serge.bmp",rend,r,g,b);
  monstre_trois = charger_image_transparente("images/chrono.bmp",rend,r,g,b);
  monstre_quatre = charger_image_transparente("images/grah.bmp",rend, r, g, b);



  /* sdl_rect pour les persos */
  SDL_Rect luffyR= {0,0,TLuffy,TLuffy};

  /// MONSTRE PREMIERE MAP !//////
  SDL_Rect map1_mst1_src={0,0,TLuffy,TLuffy};
  SDL_Rect map1_mst1_dest={100,50,TLuffy,TLuffy};

  SDL_Rect map1_mst2_src={0,0,TLuffy,TLuffy};
  SDL_Rect map1_mst2_dest={0,345,TLuffy,TLuffy};

  SDL_Rect map1_mst3_src={0,0,TLuffy,TLuffy};
  SDL_Rect map1_mst3_dest={107,245,TLuffy,TLuffy};

  SDL_Rect map1_mst4_src={0,0,TLuffy,TLuffy};
  SDL_Rect map1_mst4_dest={310,420,TLuffy,TLuffy};

  ////////////////////////////////////
  // MONSTRE DEUXIEME MAP /////////////
  SDL_Rect map2_mst1_src={0,0,TLuffy,TLuffy};
  SDL_Rect map2_mst1_dest={100,50,TLuffy,TLuffy};

  SDL_Rect map2_mst2_src={0,0,TLuffy,TLuffy};
  SDL_Rect map2_mst2_dest={0,345,TLuffy,TLuffy};

  SDL_Rect map2_mst3_src={0,0,TLuffy,TLuffy};
  SDL_Rect map2_mst3_dest={107,245,TLuffy,TLuffy};

  SDL_Rect map2_mst4_src={0,0,TLuffy,TLuffy};
  SDL_Rect map2_mst4_dest={310,420,TLuffy,TLuffy};

    ////////////////////////////////////
  // MONSTRE TROISIEME MAP /////////////
  SDL_Rect map3_mst1_src={0,0,TLuffy,TLuffy};
  SDL_Rect map3_mst1_dest={100,50,TLuffy,TLuffy};

  SDL_Rect map3_mst2_src={0,0,TLuffy,TLuffy};
  SDL_Rect map3_mst2_dest={0,345,TLuffy,TLuffy};

  SDL_Rect map3_mst3_src={0,0,TLuffy,TLuffy};
  SDL_Rect map3_mst3_dest={107,245,TLuffy,TLuffy};

  SDL_Rect map3_mst4_src={0,0,TLuffy,TLuffy};
  SDL_Rect map3_mst4_dest={310,420,TLuffy,TLuffy};

    ////////////////////////////////////
  // MONSTRE QUATRIEME MAP /////////////
  SDL_Rect map4_mst1_src={0,0,TLuffy,TLuffy};
  SDL_Rect map4_mst1_dest={100,50,TLuffy,TLuffy};

  SDL_Rect map4_mst2_src={0,0,TLuffy,TLuffy};
  SDL_Rect map4_mst2_dest={0,345,TLuffy,TLuffy};

  SDL_Rect map4_mst3_src={0,0,TLuffy,TLuffy};
  SDL_Rect map4_mst3_dest={107,245,TLuffy,TLuffy};

  SDL_Rect map4_mst4_src={0,0,TLuffy,TLuffy};
  SDL_Rect map4_mst4_dest={310,420,TLuffy,TLuffy};



  /* ****************************** */


  bool terminer = false;

  //test affichage map  
  int n,m;
  tiles=charger_image("ressources/dung.bmp",rend);



  taille_fichier("map.txt",&n,&m);
  printf("taille n : %d et m: %d\n",n,m);



  //char** tab2DDeplacement=allouer_tab_2D(n,m);
  //verif_tab(tab2DDeplacement);

/* ***** CREATION MENU ***** */
  TTF_Init();
  TTF_Font *font;
  font =TTF_OpenFont("ressources/oswald.ttf", 30);

  
  int imenu;// = createmenu(font, rend);
  imenu= createmenu(font, rend);
  if(imenu == 1){
    terminer = true;
  }




/* ***** ***** ***** */    


  //test création luffy 
  luffy_t* perso=NULL;
  perso=creation_perso(perso);
  afficherL(perso);

      //tab2DDeplacement =affichage_map_tp(tab2DDeplacement,n,m,rend,tiles,perso);

    //afficher_tab_2D(tab2DDeplacement,n,m);




//SDL_Texture*feu=charger_image_transparente("ressources/feu.bmp",rend,r,g,b);



//feu_t*feuAtk=init_feu(feu,rend);

//insertion(listBf,boule1);
//insertion(listBf,boule2);

//afficherListe(listBf);

/* **************************** */
//test affichage monstres via listes chaînées



//afficherListe_en(liste_ennemis);


/* **************************** */
// TEST AFFICHER MAP STRUCT //
  char ** tab2DMap1=lire_fichier("level1.txt");//modif_tableau(tab2DDeplacement,perso);//=lire_fichier("map.txt");
  char** tab2DMap2=lire_fichier("level2.txt");
  char** tab2DMap3=lire_fichier("level3.txt");
  char ** tab2DMap4=lire_fichier("map.txt");//modif_tableau(tab2DDeplacement,perso);//=lire_fichier("map.txt");

Liste_t*listBf=initialisation();
map_t*map1=cree_map(tab2DMap1,rend,luffy,tiles,"level1.txt");//,listBf);//ajouter liste de monstre,liste de boule de feu 
map_t*map2=cree_map(tab2DMap2,rend,luffy,tiles,"level2.txt");//,listBf);//ajouter liste de monstre,liste de boule de feu 
map_t*map3= cree_map(tab2DMap3,rend,luffy,tiles,"level3.txt");
map_t*map4= cree_map(tab2DMap4,rend,luffy,tiles,"map.txt");

//// TEST AVEC MST 

  
  

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

char** tab2DDeplacement;


  /****** MUSIQUE DE FOND DU JEU  ET BRUITAGE ENNEMI*/
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
  Mix_Music * son_fond= Mix_LoadMUS("ressources/musique_fond.mp3");
  Mix_PlayMusic(son_fond,-1);
  Mix_Music * son_en=Mix_LoadMUS("ressources/cri.mp3");
  
  /* ************** BOUCLE PRINCIPALE ************ */
  while(!terminer)
  {
    
      
  while( SDL_PollEvent( &evenements ) ){
    SDL_RenderClear(rend);
  }
    if(perso->map==1){
      tab2DDeplacement=tab2DMap1;
      afficher_map_struct(map1,rend,luffy);//,"level.txt");
      detection_porte(tab2DMap1,&DestL,perso,&n,&m); 
      
      gestion_mst(map1_mst1,map1_mst2,map1_mst3,map1_mst4,rend,monstre,listBf,perso,DestL);
      atk_luffy(listBf,rend,perso);
      }
    else if(perso->map==2){

        tab2DDeplacement=tab2DMap2;
        afficher_map_struct(map2,rend,luffy);//,"level.txt");
        detection_porte(tab2DMap2,&DestL,perso,&n,&m); 
        gestion_mst(map2_mst1,map2_mst2,map2_mst3,map2_mst4,rend,monstre_deux,listBf,perso,DestL);
        atk_luffy(listBf,rend,perso);
      }
      else if(perso->map==3){
        tab2DDeplacement=tab2DMap3;
        afficher_map_struct(map3,rend,luffy);//,"level.txt");
        detection_porte(tab2DMap3,&DestL,perso,&n,&m);  
        gestion_mst(map3_mst1,map3_mst2,map3_mst3,map3_mst4,rend,monstre_trois,listBf,perso, DestL);
        atk_luffy(listBf,rend,perso);
      }
      else if(perso->map==4){
        tab2DDeplacement=tab2DMap4;
        afficher_map_struct(map4,rend,luffy);//,"level.txt");
        detection_porte(tab2DMap4,&DestL,perso,&n,&m);  
        gestion_mst(map4_mst1,map4_mst2,map4_mst3,map4_mst4,rend,monstre_quatre,listBf,perso, DestL);
        atk_luffy(listBf,rend,perso);
      }

          //deplacement_ennemis(&(liste_ennemis->premier->src),&liste_ennemis->premier->dest);
              //deplacement_ennemis(&(ennemi1->dest),&(ennemi1->src));

    //animation_ennemis(&monstreR); 
      //SDL_RenderCopy(rend,liste_ennemis->premier->sprite,&liste_ennemis->premier->src,&liste_ennemis->premier->dest);
    //print_monstre_list(liste_ennemis,rend);
    

    //printf("le score : expe %d argent %d \n",perso->experience,perso->argent);
    SDL_RenderCopy(rend,luffy,&luffyR,&DestL);
    //detection_porte(tab2DDeplacement,&DestL,perso,&n,&m);  
    //deplacement_ennemis(&DestM,&monstreR);
    //animation_ennemis(&monstreR);  
    //SDL_RenderCopy(rend,monstre,&monstreR,&DestM);



    SDL_RenderPresent(rend);


    /*tab2DDeplacement=affichage_map_tp(tab2DDeplacement,n,m,rend,luffy,perso);
    afficher_map(tab2DDeplacement,n,m,rend,tiles);


    deplacement_ennemis(&DestM,&monstreR);
    deplacement_ennemis_deux(&DestM_deux,&monstreR_deux);
    deplacement_ennemis_trois(&DestM_trois,&monstreR_trois);
    animation_ennemis(&monstreR);  
    animation_ennemis(&monstreR_deux); 
    animation_ennemis(&monstreR_trois);  
    detection_porte(tab2DDeplacement,&DestL,perso,&n,&m);  
    SDL_RenderCopy(rend,luffy,&luffyR,&DestL);
    SDL_RenderCopy(rend,monstre,&monstreR,&DestM);
    SDL_RenderCopy(rend,monstre_deux,&monstreR_deux,&DestM_deux);
    SDL_RenderCopy(rend,monstre_trois,&monstreR_trois,&DestM_trois);

    SDL_RenderPresent(rend);


*/
      
/*
    if(check_colli(actuel->dest,DestL)|| listBf->lenght==0){

          //supprimer(listBf,actuel);
      }
    else{
    
      animation_feu(actuel);
      SDL_RenderCopy(rend,feu,&actuel->src,&actuel->dest);
      actuel->dest.x+=1;
      actuel=actuel->suivant;
    }

      */  

    /* même méthode pour le monstre */
    /*
    if(liste_ennemis->lenght!=0){
      monstre_actu=liste_ennemis->premier;
    }
    if(check_colli(monstre_actu->dest,DestL) || liste_ennemis->lenght==0){
      supprimer_ennemi(liste_ennemis,monstre_actu);

    }else{
      SDL_RenderCopy(rend,feu,&monstre_actu->src,&monstre_actu->dest);
      deplacement_ennemis(&monstre_actu->dest,&monstre_actu->src);
      animation_ennemis(&monstre_actu->src);  
      monstre_actu=monstre_actu->suivant;
    }
    */

    /* **************************** */
    /*
      if(check_colli(DestM_deux,DestL)){
        SDL_DestroyTexture(monstre_deux);
      }
      if(check_colli(DestM,DestL)){
        SDL_DestroyTexture(monstre);
      }
      if(check_colli(DestM_trois,DestL)){
        SDL_DestroyTexture(monstre_trois);
      }
      */
    /* **************************** */
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
    }
      /*imenu=createmenu(font,rend);
      
      if(imenu == 2){
        terminer = true;
      }*/
      
      break;

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
  // Quitter SDL
  ecriture_score(listBf,perso);
  freeList(listBf);
  desallouer_tab_2D(tab2DMap1,20);
  desallouer_tab_2D(tab2DMap2,20);
  desallouer_tab_2D(tab2DMap3,20);
  desallouer_tab_2D(tab2DMap4,20);
  desallouer_perso(perso);
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(luffy);
  SDL_DestroyTexture(monstre);
  SDL_DestroyTexture(monstre_deux);
  SDL_DestroyTexture(monstre_trois);
  SDL_DestroyTexture(monstre_quatre);

  //SDL_DestroyTexture(text);
  //freeListEn(liste_ennemis);
  SDL_DestroyTexture(tiles);
  SDL_DestroyRenderer(rend); 
  SDL_DestroyWindow(fenetre);
  TTF_CloseFont(font);
  Mix_FreeMusic(son_fond);
  TTF_Quit();
  SDL_Quit();
  return EXIT_SUCCESS;
}


  



