
#include "liste_ennemis.h"


int main(int argc, char *argv[])
{

  SDL_Window* fenetre; // Déclaration de la fenêtre
  SDL_Event evenements; // Événements liés à la fenêtre
  SDL_Renderer* rend;
  SDL_Texture* fond;
  SDL_Texture* luffy;
  SDL_Texture* monstre;
  SDL_Texture* monstre_deux;
  SDL_Texture* monstre_trois;
  SDL_Texture*tiles;

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


  /* SDL_Rect destination persos */
  //afficher luffy 
  SDL_Rect DestL;
  DestL.x = 70;
  DestL.y = 100;
  DestL.w =TLuffy;
  DestL.h = TLuffy;

  //afficher Monstres
  SDL_Rect DestM;
  DestM.x = 100;
  DestM.y = 100;
  DestM.w =TLuffy;
  DestM.h = TLuffy;

  SDL_Rect DestM_deux;
  DestM_deux.x = 0;
  DestM_deux.y = 50;
  DestM_deux.w =TLuffy;
  DestM_deux.h = TLuffy;

  SDL_Rect DestM_trois;
  DestM_trois.x = 100;
  DestM_trois.y = 150;
  DestM_trois.w =TLuffy;
  DestM_trois.h = TLuffy;


  /* *********************************************** */


  //chargement sprite luffy
  luffy = charger_image_transparente("ressources/liffyR.bmp", rend,r,g,b);

  //chargement sprites monstres
  monstre = charger_image_transparente("images/chrono.bmp",rend,r,g,b);
  monstre_deux = charger_image_transparente("images/oui.bmp",rend,r,g,b);
  monstre_trois = charger_image_transparente("images/serge.bmp",rend,r,g,b);


  /* sdl_rect pour les persos */
  SDL_Rect luffyR= {0,0,TLuffy,TLuffy};
  SDL_Rect monstreR={100,100,TLuffy,TLuffy};
  SDL_Rect monstreR_deux={0,50,TLuffy,TLuffy};
  SDL_Rect monstreR_trois={100,150,TLuffy,TLuffy};
  /* ****************************** */


  bool terminer = false;

  //test affichage map  
  int n,m;
  tiles=charger_image("ressources/dung.bmp",rend);



  taille_fichier("map.txt",&n,&m);
  printf("taille n : %d et m: %d\n",n,m);



  //char** tab2D=allouer_tab_2D(n,m);
  //verif_tab(tab2D);

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

  char ** tab2D=lire_fichier("map.txt");//modif_tableau(tab2D,perso);//=lire_fichier("map.txt");
      //tab2D =affichage_map_tp(tab2D,n,m,rend,tiles,perso);

    //afficher_tab_2D(tab2D,n,m);



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

afficherListe(listBf);

/* **************************** */
//test affichage monstres via listes chaînées

Liste_ennemis_t* liste_ennemis= initialisation_ennemi();
ennemi_t* ennemi1 = creeEntite_en1(monstreR,DestM,monstre,10);
ennemi_t* ennemi2 = creeEntite_en1(monstreR_deux,DestM_deux,monstre_deux,10);
ennemi_t* ennemi3 = creeEntite_en1(monstreR_trois,DestM_trois,monstre_trois,10);
insertion_ennemis(liste_ennemis, ennemi1);
insertion_ennemis(liste_ennemis, ennemi2);
insertion_ennemis(liste_ennemis, ennemi3);
ennemi_t* monstre_actu;

afficherListe_en(liste_ennemis);

/* **************************** */

  
  // Boucle principale
  while(!terminer)
  {

      
  while( SDL_PollEvent( &evenements ) )
    SDL_RenderClear(rend);
    tab2D=affichage_map_tp(tab2D,n,m,rend,luffy,perso);
    afficher_map(tab2D,n,m,rend,tiles);
    deplacement_ennemis(&DestM,&monstreR);
    deplacement_ennemis_deux(&DestM_deux,&monstreR_deux);
    deplacement_ennemis_trois(&DestM_trois,&monstreR_trois);
    animation_ennemis(&monstreR);  
    animation_ennemis(&monstreR_deux); 
    animation_ennemis(&monstreR_trois);  
    detection_porte(tab2D,&DestL,perso,&n,&m);  
    SDL_RenderCopy(rend,luffy,&luffyR,&DestL);
    SDL_RenderCopy(rend,monstre,&monstreR,&DestM);
    SDL_RenderCopy(rend,monstre_deux,&monstreR_deux,&DestM_deux);
    SDL_RenderCopy(rend,monstre_trois,&monstreR_trois,&DestM_trois);
    SDL_RenderPresent(rend);
     
    if(listBf->lenght!=0){
      actuel=listBf->premier;
    }
      

    if(check_colli(actuel->dest,DestL)|| listBf->lenght==0){
          supprimer(listBf,actuel);
      }
    else{
    
      animation_feu(actuel);
      SDL_RenderCopy(rend,feu,&actuel->src,&actuel->dest);
      actuel->dest.x+=1;
      actuel=actuel->suivant;
    }
        

    /* même méthode pour le monstre */
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


    /* **************************** */
      if(check_colli(DestM_deux,DestL)){
        SDL_DestroyTexture(monstre_deux);
      }
      if(check_colli(DestM,DestL)){
        SDL_DestroyTexture(monstre);
      }
      if(check_colli(DestM_trois,DestL)){
        SDL_DestroyTexture(monstre_trois);
      }
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
 

    //case SDLK_RCTRL:insertion(listBf,boule2);break;

    case SDLK_LEFT:/*launch_ball(feuAtk,1,&DestM,&DestL,rend)*/;deplacement_Luffy(0,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); break;
    case SDLK_RIGHT: deplacement_Luffy(1,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); break;
    case SDLK_UP:    deplacement_Luffy(2,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR);break;
    case SDLK_DOWN: deplacement_Luffy(3,&DestL,&luffyR,tab2D);animation_Luffy(&luffyR); break;


  }



  }
  
  }
  // Quitter SDL
  SDL_DestroyTexture(fond);
  SDL_DestroyTexture(luffy);
  SDL_DestroyTexture(monstre);
  SDL_DestroyTexture(monstre_deux);
  SDL_DestroyTexture(monstre_trois);
  //SDL_DestroyTexture(text);
  SDL_DestroyTexture(tiles);
  SDL_DestroyRenderer(rend); 
  SDL_DestroyWindow(fenetre);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
  return EXIT_SUCCESS;
}





  



