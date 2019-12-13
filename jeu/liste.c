
#include "liste.h"



Liste_t *initialisation()
{
    Liste_t *liste = malloc(sizeof(Liste_t));
    if (liste == NULL )
    {
        exit(EXIT_FAILURE);
    }
    liste->lenght=0;
    return liste;
}

void insertion(Liste_t *liste,perso_t*aAjout){//ajouter en param tout ce qu'il y aura dans le struct mob
    if (liste == NULL )
    {
        exit(EXIT_FAILURE);
    }
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

void supprimer(Liste_t*liste,perso_t* asupp){
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    if(asupp!=NULL){
        if (liste->lenght !=0)
        {
            if(liste->premier==asupp){
                liste->premier = liste->premier->suivant;
                asupp->precedent=NULL;
                asupp->suivant=NULL;
                free(asupp);
            }
            else{
                asupp->precedent=asupp->suivant;
                asupp->suivant=NULL;
                asupp->precedent=NULL;
                free(asupp);
                
            }
            liste->lenght--;
        }
    }  
}

void freeList(Liste_t*listBf){
    perso_t*perso=listBf->premier;
    perso_t*suivant;
    for(int i=0;i<listBf->lenght;i++){
        if(perso!=NULL){
            suivant=perso->suivant;
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
    SDL_Rect bouleFeuDest= {luffy->x,luffy->y,25,25};
    SDL_Rect bouleFeuSrc= {0,0,25,25};
    SDL_Texture*feu=charger_image("ressources/feu.bmp",rend);
    perso_t*boule1=creeEntite(bouleFeuSrc,bouleFeuDest,feu,10,luffyPerso->deplacement);
    insertion(list,boule1);
}

void atk_luffy(Liste_t*listBf,SDL_Renderer*rend,luffy_t*luffy){
    if(listBf->lenght!=0){
          perso_t*actuel=listBf->premier;
          for(int i=0;i<listBf->lenght;i++){
          if(actuel->dest.x>=475 ||actuel->dest.x<0 || actuel->dest.y>=500 || actuel->dest.y<0){
              actuel->est_affiche=1;
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
            }
            actuel=actuel->suivant;
          }
      }
          return 0;
}


mst_t*creemst(SDL_Rect dest,SDL_Rect src){
    mst_t*new= malloc(sizeof(mst_t));
    new->est_affiche=0;
    new->vie=150;
    new->dest=dest;
    new->src=src;
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
void gestion_mst(mst_t*mst1,mst_t*mst2,mst_t*mst3,mst_t*mst4,SDL_Renderer*rend,SDL_Texture* monstre,Liste_t* listBf,luffy_t*perso){
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
              if(mst1->vie<0 && mst2->est_affiche==0){
                perso->argent+=5;
                perso->experience+=10;
                mst1->est_affiche=1;
              }
              else{mst1->vie-=1;}
            }
            if(check_colli(actuel->dest,mst2->dest) && actuel->est_affiche==0){
              if(mst2->vie<0 && mst2->est_affiche==0){
                perso->argent+=5;
                perso->experience+=10;
                mst2->est_affiche=1;
              }
              else{mst2->vie-=1;}
            }
            if(check_colli(actuel->dest,mst3->dest) && actuel->est_affiche==0){
             if(mst3->vie<0 && mst3->est_affiche==0){
                perso->argent+=5;
                perso->experience+=10;
                mst3->est_affiche=1;
              }
              else{mst3->vie-=1;}
            }
            if(check_colli(actuel->dest,mst4->dest) && actuel->est_affiche==0){
              if(mst4->vie<0 && mst4->est_affiche==0){
                perso->argent+=5;
                perso->experience+=10;
                mst4->est_affiche=1;
              }
              else{mst4->vie-=1;}
            }
          } 
          actuel=actuel->suivant;

        }
        
}



void ecriture_score(Liste_t*list,luffy_t*luffy){
    FILE* fichier = NULL;
 
    fichier = fopen("scoreJoueur.txt", "w");
 
    if (fichier != NULL)
    {
 
        // On l'écrit dans le fichier
        fputs("SCORE DU JOUEUR POUR TheLuffy : \n",fichier);
        fprintf(fichier, "Vous avez utilisé %d boules de feu pour venir à bout des ennemis", list->lenght);
        fprintf(fichier,"Vous avez %d argent et %d experience \n",luffy->argent,luffy->experience);
        fprintf(fichier,"Vous avez fini le jeu avec %d de point de vie.\n ",luffy->vie);
        fclose(fichier);
    }
 
    return 0;
}