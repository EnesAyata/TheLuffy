#include "map.h"



void desallouer_map(map_t* map){
    free(map);
}
char** allouer_tab_2D(int n, int m){
    char** tab;
    //char init=;
    tab=malloc(n*sizeof(char*));
    for(int i = 0; i < n; i++){
        tab[i] = malloc(m*sizeof(char*));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tab[i][j]='&';
        }
    }
    return tab;
}

void afficher_tab_2D(char** tab,int n,int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
                printf("%c ",(char)tab[i][j]);
            
        }
        printf("je passe a la ligne");
        printf("\n");
    }

}

char** affichage_map_tp(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles,luffy_t* perso){//avec la tp
    //char** tab2;
    if(tab!=NULL){
        desallouer_tab_2D(tab,n);
    }
    if(perso->map==1){
        //desallouer_tab_2D(tab,n);
        //printf("Nv 1\n");
        tab=lire_fichier("map.txt");
        taille_fichier("map.txt",&n,&m);
        afficher_map(tab,n,m,rend,tiles);
        return tab;
        //desallouer_tab_2D(tab2,n);
    }
    if(perso->map==2){
        //printf("Nv 2\n");
      //desallouer_tab_2D(tab,n);
      tab=lire_fichier("level.txt");
      taille_fichier("level.txt",&n,&m);
      
       // afficher_tab_2D(tab,n,m);
      afficher_map(tab,n,m,rend,tiles);
      return tab;
      //desallouer_tab_2D(tab,n);
    }
    return NULL;

    //desallouer_tab_2D(tab2,n);
    


}


void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles){

  SDL_Rect SrcR,DestL;
  int cpt;
  init_rect(&SrcR,&DestL);
 // DestL.x=64;//x en position a afficher
  //DestL.y=64;//y en position a afficher "#$%&'()*+'-./0123!


  for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cpt=(int)tab[i][j]-33;//tiles a afficher // 33 = 1;
            


            if(tab[i][j]==' '){
                //on affiche de la terre
                //SrcR.x=0;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if (cpt>=0 && cpt<NbTilesLargeur){
                SrcR.x+=cpt*TailleTiles;
                //SrcR.y+=32;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
          //tile.y=40*(j+1);
          //SrcR.x=0;
            }
            else if(cpt>=NbTilesLargeur && cpt<NbTilesLargeur*2 ){
                SrcR.x+=(cpt-NbTilesLargeur)*TailleTiles;
                SrcR.y+=TailleTiles;
                //printf(" le del %d , %d \n ",SrcR.x,SrcR.y);

                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);

            }
            else if(cpt>=NbTilesLargeur*2 && cpt<NbTilesLargeur*3 ){
                SrcR.x+=(cpt-(NbTilesLargeur*2))*TailleTiles;
                SrcR.y+=TailleTiles*2;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur*3 && cpt<NbTilesLargeur*4 ){
                SrcR.x+=(cpt-(NbTilesLargeur*3))*TailleTiles;
                SrcR.y+=TailleTiles*3;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur*4 && cpt<NbTilesLargeur*5 ){
                SrcR.x+=(cpt-(NbTilesLargeur*4))*TailleTiles;
                SrcR.y+=TailleTiles*4;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur*5 && cpt<NbTilesLargeur*6 ){
                SrcR.x+=(cpt-(NbTilesLargeur*5))*TailleTiles;
                SrcR.y+=TailleTiles*5;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur*6 && cpt<NbTilesLargeur*7 ){
                SrcR.x+=(cpt-(NbTilesLargeur*6))*TailleTiles;
                SrcR.y+=TailleTiles*6;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur*7 && cpt<NbTilesLargeur*8){
                SrcR.x+=(cpt-(NbTilesLargeur*7))*TailleTiles;
                SrcR.y+=TailleTiles*7;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur*8 && cpt<NbTilesLargeur*9){
                SrcR.x+=(cpt-(NbTilesLargeur*8))*TailleTiles;
                SrcR.y+=TailleTiles*8;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur*9 /*&& cpt<NbTilesLargeur*9*/){
                SrcR.x+=(cpt-(NbTilesLargeur*9))*TailleTiles;
                SrcR.y+=TailleTiles*9;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            SrcR.x=0;
            DestL.x+=TailleTiles;
            SrcR.y=0;
            
        }
        SrcR.y=0;
        DestL.x=0;
        DestL.y+=TailleTiles;//on saute la ligne ""
        
  }
  //SDL_DestroyRenderer(rend);
}