#include "map.h"

map_t* cree_map(char** tab2D,SDL_Renderer* rend,luffy_t*luffy,SDL_Texture*tiles,const char* nomMap){
map_t*map= malloc(sizeof(map_t));
int n,m;
taille_fichier(nomMap,&n,&m);
map->col=n;
map->lig=m;
map->luffy=luffy;
map->tab2D=tab2D;
map->tiles=tiles;
map->nomMap=nomMap;
return map;
}

void desallouer_map(map_t* map){
    free(map);
}

char** allouer_tab_2D(int n, int m){
    char** tab;
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
    }
}

char** affichage_map_tp(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles,luffy_t* perso){//avec la tp
    if(perso->map==1){
        tab=lire_fichier("map.txt");
        taille_fichier("map.txt",&n,&m);
        afficher_map(tab,n,m,rend,tiles);
        return tab;
    }
    if(perso->map==2){
      tab=lire_fichier("level.txt");
      taille_fichier("level.txt",&n,&m);
      afficher_map(tab,n,m,rend,tiles);
      return tab;
    }
    return NULL;   
}


void afficher_map(char** tab,int n,int m,SDL_Renderer* rend,SDL_Texture* tiles){
  SDL_Rect SrcR = {100,100,TLuffy,TLuffy};
  SDL_Rect DestL = {100,100,TLuffy,TLuffy};
  int cpt =0;
  char** temp= tab;
  init_rect(&SrcR,&DestL);
  for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cpt=(int)temp[i][j]-33;
            if(temp[i][j]==' '){
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if (cpt>=0 && cpt<NbTilesLargeur){
                SrcR.x+=cpt*TailleTiles;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=NbTilesLargeur && cpt<NbTilesLargeur*2 ){
                SrcR.x+=(cpt-NbTilesLargeur)*TailleTiles;
                SrcR.y+=TailleTiles;
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
            else if(cpt>=NbTilesLargeur*9 ){
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
        DestL.y+=TailleTiles;  
  }

  }


void afficher_map_struct(map_t*map,SDL_Renderer*rend,SDL_Texture*tilesLuffy){
    char**tab2DT=lire_fichier(map->nomMap);
    afficher_map(tab2DT,map->lig,map->col,rend,map->tiles);
    map->tab2D=affichage_map_tp(tab2DT,map->lig,map->col,rend,tilesLuffy,map->luffy);
    desallouer_tab_2D(tab2DT,20);
}