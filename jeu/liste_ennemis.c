#include "liste_ennemis.h"




Liste_ennemis_t *initialisation_ennemi()
{
    Liste_ennemis_t *liste = malloc(sizeof(Liste_ennemis_t));
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


/* ****************************** */
void insertion_ennemis(Liste_ennemis_t *liste,ennemi_t *aAjout){//ajouter en param tout ce qu'il y aura dans le struct mob
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

/* *************************** */
ennemi_t* creeEntite_en1(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie){
    ennemi_t *nouveau = malloc(sizeof(ennemi_t));
    nouveau->src=src;
    nouveau->dest=dest;
    nouveau->sprite=text;
    nouveau->vie=vie;
    nouveau->precedent=NULL;
    nouveau->suivant=NULL;
    return nouveau;
}

/* *********************************** */
ennemi_t* creeEntite_en2(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie){
    ennemi_t *nouveau = malloc(sizeof(ennemi_t));
    nouveau->src=src;
    nouveau->dest=dest;
    //nouveau->sprite=text;
    nouveau->vie=vie;
    nouveau->precedent=NULL;
    nouveau->suivant=NULL;
    return nouveau;
}

/* *********************************** */
ennemi_t* creeEntite_en3(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie){
    ennemi_t *nouveau = malloc(sizeof(ennemi_t));
    nouveau->src=src;
    nouveau->dest=dest;
    //nouveau->sprite=text;
    nouveau->vie=vie;
    nouveau->precedent=NULL;
    nouveau->suivant=NULL;
    nouveau->estAffiche=0;
    return nouveau;
}

/* ************************************ */

void supprimer_ennemi(Liste_ennemis_t*liste, ennemi_t* asupp){//ajouter un ID dans la struct et l'incrémenter a chaque fois qu'on supprimer ou ajoute un element
    
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->lenght !=0)
    {
        
        //Element_t * aSupprimer = liste->premier;
        if(liste->premier==asupp){
            
            liste->premier = liste->premier->suivant;
            free(asupp);
        }
        else{
            asupp->precedent->suivant=asupp->suivant;
            free(asupp);
            
        }
        //free(asupp);
        liste->lenght--;
    }
    
}


void afficherListe_en(Liste_ennemis_t *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    ennemi_t *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("Point de vie du monstre X %d  \n", actuel->vie);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

void afficherListe_map(Liste_ennemis_t*liste,SDL_Renderer*rend){
    /*if(liste->lenght!=0){
        printf("liste length =!0\n");
        ennemi_t* actuel=liste->premier;
        while(actuel!=NULL && actuel->estAffiche==0){
            printf("la jaffiche normal\n");
                deplacement_ennemis(&(actuel->src),&(actuel->dest));
            animation_ennemis(&(actuel->src));
            SDL_Texture*text=charger_image("images/chrono.bmp",rend);
            SDL_RenderCopy(rend,actuel->sprite,&(actuel->src),&(actuel->dest));
            actuel=actuel->suivant;
        }
    }*/
                SDL_Rect Dest= {100,100,25,25};
                SDL_Rect Src= {0,0,25,25};
                SDL_Texture*mst=charger_image("ressources/oui.bmp",rend);
                ennemi_t*ennemi=creeEntite_en1(Src,Dest,mst,10);

                insertion_ennemis(liste,&ennemi);

}

void print_monstre_list(Liste_ennemis_t*list,SDL_Renderer*rend){
    int cpt=0;
    if(list->lenght!=0){
        perso_t*actuel=list->premier;
        while(actuel!=NULL){
            if(actuel->est_affiche==0){
                printf("je suis ici avec cpt\n");
                deplacement_ennemis(&actuel->dest,&actuel->src);
                animation_ennemis(&actuel->src);
                SDL_RenderCopy(rend,actuel->sprite,&actuel->src,&actuel->dest);
            }
            //actuel=actuel->suivant;
            actuel=actuel->suivant;
            
        }



    }
}

void freeListEn(Liste_ennemis_t*listBf){
    perso_t*perso=listBf->premier;
    for(int i=0;i<listBf->lenght;i++){
        if(perso!=NULL){
            free(perso);
            perso=perso->suivant;
        }
    }
}

int rand_a_b(int a,int b){
    return rand()%(b-a)+a;
}

void animation_ennemi_map(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis(dest,src);
        animation_ennemis(&src);
    
}   

void animation_ennemi_map_deux(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis_deux(dest,src);
        animation_ennemis(&src);
    
} 

void animation_ennemi_map_trois(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis_trois(dest,src);
        animation_ennemis(&src);
    
} 

void animation_ennemi_map_quatre(SDL_Rect*dest,SDL_Rect*src,SDL_Renderer* rend,SDL_Texture* text){
    
        deplacement_ennemis_quatre(dest,src);
        animation_ennemis(&src);
    
} 




