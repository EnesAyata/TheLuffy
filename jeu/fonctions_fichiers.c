

SDL_Texture* charger_image (const char* nomfichier, SDL_Renderer*renderer) {
    SDL_Surface* surface = SDL_LoadBMP(nomfichier) ;

    return SDL_CreateTextureFromSurface(renderer,surface );

}

SDL_Texture* charger_image_transparente(const char* nomfichier,SDL_Renderer* renderer,Uint8 r, Uint8 g, Uint8 b) {
 SDL_Surface* surface = SDL_LoadBMP(nomfichier) ;
  int i=SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, r, g, b));
  return SDL_CreateTextureFromSurface(renderer,surface );
}


  
  
char** allouer_tab_2D(int n, int m){
    char** tab;
    tab=malloc(n*sizeof(char*));
    for(int i = 0; i < n; i++){
        tab[i] = malloc(m*sizeof(char*));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            tab[i][j]='!';
        }
    }
    return tab;
}

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

int detection_col(char** tabJ,char** map,SDL_Rect* luffy,int direction){
        tabJ=allouer_tab_2D_joueur(20,20);//ici je mets 20,20 car taille de la map mais faut dynamique (en parametre?)
        int a,b;
        a=(luffy->x)/28;
        b=(luffy->y)/28;
        switch (direction)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
        printf("La pos de luffy en a : %d et en b: %d\n ",a,b);
}



SDL_Rect** allouer_rect(int n,int m){
  SDL_Rect** tab;
  SDL_Rect base={0,0,38,38};
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
    free(tab);
}


void desallouer_rect(SDL_Rect** tab,int n){
  for(int i=0;i<n;i++){
        free(tab[i]);
    }
    free(tab);
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

void verif_tab(char** tab){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(tab[i][j]=='\n')
                tab[i][j]=0;
        }
    }
}

void init_rect(SDL_Rect* SrcR,SDL_Rect* DestL){
  SrcR->x=0;
  SrcR->y=0;
  SrcR->w=32;//largeur objet a recup
  SrcR->h=32;//hauteur objet a recup

  DestL->x=0;//position du tiles en x
  DestL->y=0;//position du tiles en y
  DestL->w=32;
  DestL->h=32;

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
            


            /*if(tab[i][j]=='0' || tab[i][j]==' '){
                //on affiche de la terre
                SrcR.x=0;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            elseù*/ if (cpt>=0 && cpt<16){
                SrcR.x+=cpt*32;
                //SrcR.y+=32;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
          //tile.y=40*(j+1);
          //SrcR.x=0;
            }
            else if(cpt>=16 && cpt<32 ){
                SrcR.x+=(cpt-16)*32;
                SrcR.y+=32;
                //printf(" le del %d , %d \n ",SrcR.x,SrcR.y);

                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);

            }
            else if(cpt>=32 && cpt<48 ){
                SrcR.x+=(cpt-32)*32;
                SrcR.y+=64;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=48 && cpt<64 ){
                SrcR.x+=(cpt-48)*32;
                SrcR.y+=92;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=64 && cpt<80 ){
                SrcR.x+=(cpt-64)*32;
                SrcR.y+=128;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            else if(cpt>=80 && cpt<96 ){
                SrcR.x+=(cpt-80)*32;
                SrcR.y+=160;
                SDL_RenderCopy(rend,tiles,&SrcR,&DestL);
            }
            SrcR.x=0;
            DestL.x+=32;
            SrcR.y=0;
            
        }
        SrcR.y=0;
        DestL.x=0;
        DestL.y+=32;//on saute la ligne ""
        
  }
}
/*
SDL_Rect** remplir_rect(char** tab2D,int n,int m){
  SDL_Rect** tab;
  

  int nb;
SDL_Rect base={0,0,32,32};
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      base.x=(atoi(tab2D[i][j]))*32;
      tab[i][j]=base;
      base.x=0;
    }
    base.y+=32;
  }
  return tab;
}

*/

void taille_fichier(const char* nomFichier, int * nbLig, int* nbCol){
    FILE* fichier = NULL;
    *nbLig=0;
    *nbCol=0;
    int comptLargeur=0;

    fichier=fopen(nomFichier,"r");
    char c= fgetc(fichier);

    int caractActuel=0;

    int tmaxC=0,tmaxL=0,tmpC=0;


    
     if(fichier!=NULL){
        while(c!=EOF){
        /*/
            if(caractActuel=='\n'){
                tmaxL++;
                if(tmaxC<tmpC){
                    tmaxC=tmpC;
                }

                tmpC=0;
            }

            tmpC++;
        */

       if(c=='\n'){
            *nbLig=*nbLig+1;
            if(comptLargeur>*nbCol)
                *nbCol=comptLargeur;//prq -1 ?
            comptLargeur=0;
       }
       else{comptLargeur=comptLargeur+1;}
        
        c=fgetc(fichier);

        

       /*/
        if(c==10 || c==13){
            if(comptLargeur!=0)
                *nbLig=*nbLig+1;
            if(comptLargeur>*nbCol)
                *nbCol=comptLargeur;
            comptLargeur=0;
            c=fgetc(fichier);
        }
        */
        }


    }
    else{printf("Impossible d'ouvrir le fichier\n");}
    *nbLig+=1;
    fclose(fichier);


}


int ** lire_fichier_2(const char* nomFichier){
    int** tab2D= allouer_tab_2D(20,20);
    int n,m;
    taille_fichier(nomFichier,&n,&m);
    FILE* fichier = NULL;
    fichier=fopen(nomFichier,"r");
    char c;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(i<n && j<m){
                if(c!='\n')
                    tab2D[i][j]=fgetc(fichier);
                else
                {
                    for(int p=j;p<20;p++)
                        tab2D[i][j]=0;
                }
                
            }
            c=fgetc(fichier);

        }
    }




    fclose(fichier);
    return tab2D;
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
    //desallouer_tab_2D(tab,n);
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

void deplacement_Luffy(int dep,SDL_Rect* luffy,SDL_Rect* regard){
    printf("La pos x de luffy : %d , et y : %d\n",luffy->x,luffy->y);
  switch(dep){
    case 0: if(luffy->x-2>=0)
                luffy->x-=2;
            regard->x=40;
            regard->y=40;break;
    case 1: if(luffy->x+2<=600)
                luffy->x+=2;
            regard->x=80;
            regard->y=80;break;
    case 2: if(luffy->y-2>=0)
                luffy->y-=2;
            regard->x=120;
            regard->y=120;break;
    case 3: if(luffy->y+2<=600)
                luffy->y+=2;
            regard->x=0;
            regard->y=0;break;
  }
}

void animation_Luffy(SDL_Rect*anim){
    
  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 100;
  Uint32 sprite = seconds % 5;
  anim->x=sprite*40;
  
}
/*/
SDL_Rect[][] initialisation_tiles(const char* nomFichier,char** tab){
  SDL_Rect[] tableautiles;
  for(int i=0;i<160;i++){
    SDL_Rect[i]={i*(i+1),i*(i+1),32,32};
  }
  return 
}

void destroy_tiles(SDL_Rect[] tab){
  for(int i=0;i<160;i++){
    
  }
}
/*/

