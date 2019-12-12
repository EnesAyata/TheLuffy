
#include "liste.h"



Liste_t *initialisation()
{
    Liste_t *liste = malloc(sizeof(Liste_t));
    //perso_t *element = malloc(sizeof(perso_t));

    if (liste == NULL )//|| element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    //element->vie = 0;
    //element->suivant = NULL;
    //element->precedent=NULL;
    liste->lenght=0;
    //liste->premier = element;

    return liste;
}

void insertion(Liste_t *liste,perso_t*aAjout){//ajouter en param tout ce qu'il y aura dans le struct mob
//comme la vie, les 2 rect, la texture...
    //perso_t *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL )//|| nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    //nouveau->vie = vie;

    /* Insertion de l'élément au début de la liste */

    if(liste->lenght!=0){
        aAjout->suivant = liste->premier;
        liste->premier->precedent=aAjout;
        liste->premier = aAjout;
        liste->lenght++;
    }
    else{
        liste->premier=aAjout;
        liste->lenght++;
    }
}

//crée un mstr perso_t vite
perso_t* creeEntite(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie,int deplacement){
    perso_t *nouveau = malloc(sizeof(perso_t));
    nouveau->src=src;
    nouveau->dest=dest;
    nouveau->sprite=text;
    nouveau->vie=vie;
    nouveau->precedent=NULL;
    nouveau->suivant=NULL;
    nouveau->est_affiche=0;
    nouveau->deplacement=deplacement;
    return nouveau;
}

void supprimer(Liste_t*liste,perso_t* asupp){//ajouter un ID dans la struct et l'incrémenter a chaque fois qu'on supprimer ou ajoute un element
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    if(asupp!=NULL){
        if (liste->lenght !=0)
        {
            
            //Element_t * aSupprimer = liste->premier;
            if(liste->premier==asupp){
                
                    liste->premier = liste->premier->suivant;
                asupp->precedent=NULL;
                asupp->suivant=NULL;
                //asupp=NULL;
                free(asupp);
            }
            else{
                asupp->precedent=asupp->suivant;
                asupp->suivant=NULL;
                asupp->precedent=NULL;
                //asupp->suivant=NULL;
                //asupp=NULL;
                free(asupp);
                
            }
            //free(asupp);
            /*//FREE A REAFIRE !!!!!!!!!!!!!!!!!!!!
            //free(asupp->dest);
            //free(asupp->feu);
            free(asupp->precedent);
            free(asupp->sprite);
            //free(asupp->src);
            free(asupp->suivant);
            //free(asupp->vie);
            free(asupp);
            */
            liste->lenght--;
        }
    }
    
}

void freeList(Liste_t*listBf){
    perso_t*perso=listBf->premier;
    for(int i=0;i<listBf->lenght;i++){
        if(perso!=NULL){
            free(perso);
            perso=perso->suivant;
        }
    }
        

}




void afficherListe(Liste_t *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    perso_t *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("Point de vie du monstre X(ajouter ID) %d  \n", actuel->vie);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

void animation_feu(perso_t* perso){
    
  Uint32 ticks = SDL_GetTicks();
  Uint32 seconds = ticks / 100;
  Uint32 sprite = seconds % 4;
 perso->src.x=sprite*25;
}

void NewBouleFeu(Liste_t* list,SDL_Rect*luffy,SDL_Renderer* rend,luffy_t*luffyPerso){
    /*
    if(list->lenght<10000 ){
        if(list->lenght=5){
            if(list->premier->dest.x>luffy->x+25 || list->premier->dest.y>luffy->y+25){
                SDL_Rect bouleFeuDest= {luffy->x,luffy->y,25,25};
                SDL_Rect bouleFeuSrc= {0,0,25,25};
                SDL_Texture*feu=charger_image("ressources/feu.bmp",rend);
                perso_t*boule1=creeEntite(bouleFeuSrc,bouleFeuDest,feu,10,luffyPerso->deplacement);

                insertion(list,boule1);
                //free(boule1);
            }
        }
        else{
            SDL_Rect bouleFeuDest= {luffy->x,luffy->y,25,25};
                SDL_Rect bouleFeuSrc= {0,0,25,25};
                SDL_Texture*feu=charger_image("ressources/feu.bmp",rend);
                perso_t*boule1=creeEntite(bouleFeuSrc,bouleFeuDest,feu,10,luffyPerso->deplacement);

                insertion(list,boule1);
        }
    }
    //else{freeList(list);}
    
    SDL_Rect bouleFeuDest= {luffy->x,luffy->y,25,25};
                SDL_Rect bouleFeuSrc= {0,0,25,25};
                SDL_Texture*feu=charger_image("ressources/feu.bmp",rend);
                perso_t*boule1=creeEntite(bouleFeuSrc,bouleFeuDest,feu,10,luffyPerso->deplacement);

                insertion(list,boule1);
                */
               SDL_Rect bouleFeuDest= {luffy->x,luffy->y,25,25};
                SDL_Rect bouleFeuSrc= {0,0,25,25};
                SDL_Texture*feu=charger_image("ressources/feu.bmp",rend);
                perso_t*boule1=creeEntite(bouleFeuSrc,bouleFeuDest,feu,10,luffyPerso->deplacement);

                insertion(list,boule1);
}

void atk_luffy(Liste_t*listBf,SDL_Renderer*rend,luffy_t*luffy){
    printf("Direction de luffy %d\n",luffy->deplacement);
if(listBf->lenght!=0){
        printf("Taille liste %d\n",listBf->lenght);
          perso_t*actuel=listBf->premier;
          for(int i=0;i<listBf->lenght;i++){
          if(/*check_colli(actuel->dest,DestL)*/actuel->dest.x>=475 ||actuel->dest.x<0 || actuel->dest.y>=500 || actuel->dest.y<0){
              actuel->est_affiche=1;//on l'aff plus
                //supprimer(listBf,actuel);
                //desallouer_feu(feuAtk);
            }
            else if(actuel->est_affiche==0){
            
            
            animation_feu(actuel);
            SDL_RenderCopy(rend,actuel->sprite,&actuel->src,&actuel->dest);
            switch(actuel->deplacement){
                case 0:actuel->dest.x-=2;break;
                case 1:actuel->dest.x+=2;break;
                case 2:actuel->dest.y-=2;break;
                case 3:actuel->dest.y+=2;break;

            }
            //actuel->dest.x+=1;
            }
            actuel=actuel->suivant;
          }
      }


}


/*
int main()
{

  //  SDL_Texture*feu=charger_image("ressources/feu.bmp",rend);
//SDL_Texture*feu=charger_image_transparente("ressources/feu.bmp",rend,r,g,b);
//feu_t*feuAtk=init_feu(feu,rend);
  SDL_Rect bouleFeuDest= {0,0,25,25};
  SDL_Rect bouleFeuSrc= {0,0,25,25};
//Liste_t*listBf=initialisation();
//perso_t*boule1=creeEntite(bouleFeuSrc,bouleFeuDest,feu,10);


    Liste_t *maListe = initialisation();
    perso_t*perso1=creeEntite(bouleFeuSrc,bouleFeuDest,10);
    perso_t*perso2=creeEntite(bouleFeuSrc,bouleFeuDest,0);
    perso_t*perso3=creeEntite(bouleFeuSrc,bouleFeuDest,245);
    insertion(maListe,perso1);
    insertion(maListe,perso2);
    insertion(maListe,perso3);
    afficherListe(maListe);
        printf("lenght %d\n",maListe->lenght);
    supprimer(maListe,perso1);
    printf("lenght %d\n",maListe->lenght);
    supprimer(maListe,perso3);
        printf("lenght %d\n",maListe->lenght);

    supprimer(maListe,perso2);
        printf("lenght %d\n",maListe->lenght);


    afficherListe(maListe);

    return 0;
}
*/

mst_t*creemst(SDL_Rect dest,SDL_Rect src){
    mst_t*new= malloc(sizeof(mst_t));
    new->est_affiche=0;
    new->vie=100;
    new->dest=dest;
    new->src=src;//pas oublier de free
    return new;
}


void animation_ennemi_map(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis(dest,src);
        animation_ennemis(src);
    
}   

void animation_ennemi_map_deux(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis_deux(dest,src);
        animation_ennemis(src);
    
} 

void animation_ennemi_map_trois(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis_trois(dest,src);
        animation_ennemis(src);
    
} 

void animation_ennemi_map_quatre(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis_quatre(dest,src);
        animation_ennemis(src);
    
} 
void gestion_mst(mst_t*mst1,mst_t*mst2,mst_t*mst3,mst_t*mst4,SDL_Renderer*rend,SDL_Texture* monstre,Liste_t* listBf){
    if(mst1->est_affiche==0){
        SDL_RenderCopy(rend,monstre,&mst1->src,&mst1->dest);
        animation_ennemi_map(&mst1->dest,&mst1->src,rend,monstre);
    }

    if(mst2->est_affiche==0){

        SDL_RenderCopy(rend,monstre,&mst2->src,&mst2->dest);
        animation_ennemi_map_deux(&mst2->dest,&mst2->src,rend,monstre);
    }

    if(mst3->est_affiche==0){
        SDL_RenderCopy(rend,monstre,&mst3->src,&mst3->dest);
        animation_ennemi_map_trois(&mst3->dest,&mst3->src,rend,monstre);
    }


    if(mst4->est_affiche==0){
        SDL_RenderCopy(rend,monstre,&mst4->src,&mst4->dest);
        animation_ennemi_map_quatre(&mst4->dest,&mst4->src,rend,monstre);
    }

    perso_t*actuel=listBf->premier;
        for(int i=0;i<listBf->lenght;i++){
          if(actuel!=NULL){
            if(check_colli(actuel->dest,mst1->dest) && actuel->est_affiche==0){
              printf("ya collision ! \n");
              mst1->est_affiche=1;
            }
            if(check_colli(actuel->dest,mst2->dest) && actuel->est_affiche==0){
              printf("ya collision ! \n");
              mst2->est_affiche=1;
            }
            if(check_colli(actuel->dest,mst3->dest) && actuel->est_affiche==0){
              printf("ya collision ! \n");
              mst3->est_affiche=1;
            }
            if(check_colli(actuel->dest,mst4->dest) && actuel->est_affiche==0){
              printf("ya collision ! \n");
              mst4->est_affiche=1;
            }

          } 
          actuel=actuel->suivant;
        }

    

}