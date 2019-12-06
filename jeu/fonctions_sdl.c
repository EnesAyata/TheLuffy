#include "fonctions_sdl.h"



SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer) {
    SDL_Surface* surface = SDL_LoadBMP(nomfichier) ;

    return SDL_CreateTextureFromSurface(renderer,surface );

}

SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b) {
  SDL_Surface* surface = SDL_LoadBMP(nomfichier) ;
  SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
  return SDL_CreateTextureFromSurface(renderer,surface);
}


void modif_tableau(char**tab2,luffy_t* luffy,int n,int m){
    //char** tab;
    
    if(luffy->map==1){
        desallouer_tab_2D(tab2,n);
        //taille_fichier("map.txt",&n,&m);
       
        //tab2=allouer_tab_2D(n,m);
        tab2=lire_fichier("map.txt");
    }
    if(luffy->map==2){
        desallouer_tab_2D(tab2,n);
        //taille_fichier("level.txt",&n,&m);
        //tab2=allouer_tab_2D(n,m);
        tab2=lire_fichier("level.txt");
    }
    //free(tab2);
    //return tab;

}
  

/*
char** allouer_tab_2D_joueur(int n, int m){
    char** tab;
    tab=malloc(n*sizeof(char*));
    for(int i = 0; i < n; i++){
        tab[i] = malloc(m*sizeof(char*));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tab[i][j]='0';
        }
    }
    return tab;
}
*/




SDL_Rect** allouer_rect(int n,int m){
  SDL_Rect** tab;
  SDL_Rect base={0,0,TailleTiles,TailleTiles};
  tab=malloc(n*sizeof(SDL_Rect));
    for(int i = 0; i < n; i++){
        tab[i] = malloc(m*sizeof(SDL_Rect));
    }
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){
            tab[i][j]=base;
        }
    }
    return tab;
}

void desallouer_tab_2D(char**tab, int n){
    for(int i=0;i<n;i++){
        free(tab[i]);
    }
    //free(tab);
}


void desallouer_rect(SDL_Rect** tab,int n){
  for(int i=0;i<n;i++){
        free(tab[i]);
    }
    free(tab);
}



/*
void verif_tab(char** tab){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(tab[i][j]=='\n')
                tab[i][j]=0;
        }
    }
}
*/

void init_rect(SDL_Rect* SrcR,SDL_Rect* DestL){
  SrcR->x=0;
  SrcR->y=0;
  SrcR->w=TailleTiles;//largeur objet a recup
  SrcR->h=TailleTiles;//hauteur objet a recup

  DestL->x=0;//position du tiles en x
  DestL->y=0;//position du tiles en y
  DestL->w=TailleTiles;
  DestL->h=TailleTiles;

}









void taille_fichier(const char* nomFichier, int * nbLig, int* nbCol){
    FILE* fichier = NULL;
    *nbLig=0;
    *nbCol=0;
    int comptLargeur=0;

    fichier=fopen(nomFichier,"r");
    char c= fgetc(fichier);

    //int caractActuel=0;

    //int tmaxC=0,tmaxL=0,tmpC=0;


    
     if(fichier!=NULL){
        while(c!=EOF){
       if(c=='\n'){
            *nbLig=*nbLig+1;
            if(comptLargeur>*nbCol)
                *nbCol=comptLargeur;//prq -1 ?
            comptLargeur=0;
       }
       else{comptLargeur=comptLargeur+1;}
        
        c=fgetc(fichier);
        }


    }
    else{printf("Impossible d'ouvrir le fichier\n");}
    *nbLig+=1;
    fclose(fichier);


}

char** lire_fichier(const char* nomFichier){

    int i=0,j=0;
    FILE* fichier = NULL;
    fichier=fopen(nomFichier,"r");

    int nbLig,nbCol;
    taille_fichier(nomFichier,&nbLig,&nbCol);
    char** tab=allouer_tab_2D(nbLig,nbCol);

    char c;
    if(fichier==NULL){
        printf("Impossible d'ouvrir le fichier");
    }
    else{
      c=fgetc(fichier);
      while(c!=EOF){
         if(c=='\n'){
              i=i+1;
              j=0;
         }
         else{
          tab[i][j]=c;
          j=j+1;
         } 
         c=fgetc(fichier);
      }  
    }
    fclose(fichier);
    return tab;

}

char** modifier_caractere(char** tab, int n, int m, char ancien, char nouveau) {
    char** tabl=allouer_tab_2D(n,m);
    for(int i=0;i<n;i++){
            for(int j=0;j<m+2;j++){
                if(tab[i][j]!=' '){
                    if(tab[i][j]==ancien){
                        tabl[i][j]=nouveau;
                    }
                    else{tabl[i][j]=tab[i][j];}
                }
            }
    }
    return tabl;
}

void ecrire_fichier(const char* nomFichier, char** tab, int n,int m){
    FILE* fichier = NULL;
    fichier=fopen(nomFichier,"w");

    for(int i=0;i<n;i++){
            for(int j=0;j<m+2;j++){
                if(tab[i][j]!=' '){
                    fputc(tab[i][j],fichier);
                }
            }
            fputc('\n',fichier);
    }
    fclose(fichier);
}

void deplacement_Luffy(int dep,SDL_Rect* luffy,SDL_Rect* regard, char** map){

    
    //    printf("le carac a guche: %c ",map[(luffy->x/30)-1][(luffy->y/30)]);
    //int posX=luffy->x/22,posY=(luffy->y)/22;
    // if((luffy->x/30)!=0)
   // printf("Le car a droite : %c \n" , map[(luffy->y+6)/31][(luffy->x/31)+1]);
    //printf("La c'est : %d",detect_col(luffy,map,dep));
  switch(dep){
    case 0: if(luffy->x-2>=0 && detect_col(luffy,map,dep)==0 )
                luffy->x-=2;
            regard->x=TLuffy;
            regard->y=TLuffy;break;
    case 1: if(luffy->x+2<=500-20 && detect_col(luffy,map,dep)==0)
                luffy->x+=2;
            regard->x=TLuffy*2;
            regard->y=TLuffy*2;break;
    case 2: if(luffy->y-2>=0 && detect_col(luffy,map,dep)==0)
                luffy->y-=2;
            regard->x=TLuffy*3;
            regard->y=TLuffy*3;break;
    case 3: if(luffy->y+2<=500-20 && detect_col(luffy,map,dep)==0)
                luffy->y+=2;
            regard->x=0;
            regard->y=0;break;
  }
  return ;
}


void animation_Luffy(SDL_Rect*anim){
    
  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 100;
  Uint32 sprite = seconds % 5;
  anim->x=sprite*25;
}

void animation_ennemis(SDL_Rect*anim){
    
  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 100;
  Uint32 sprite = seconds % 4;
  anim->x=sprite*25;
}


void deplacement_ennemis(SDL_Rect* ennemis, SDL_Rect* regard){
    srand(time(NULL));
    int dep ;//= rand()%4;
    Uint32 lastTime =0, currentTime;

    currentTime= SDL_GetTicks();

    
    dep=rand()%4;

    
    
    

    switch(dep){
        case 0: if(ennemis->x + 2 <= 500-TLuffy){
                
                ennemis->x+=2;
                
                regard->x=TLuffy*2;
                regard->y=TLuffy*2;
                
                
            
        }break;
        case 1: if (ennemis->y+2 <= 475-TLuffy){
            ennemis->y+=2;
            regard->x=TLuffy*3;
            regard->y=TLuffy*3;
            
        }break;
        case 2: if (ennemis->x-2> 0){
            ennemis->x-=2;
            regard->x=TLuffy;
            regard->y=TLuffy;
            
        }break;
        case 3: if (ennemis->y-2>0){
            ennemis->y-=2;
            regard->x=0;
            regard->y=0;
            
        }break;
    }

    




    
    

        
}



