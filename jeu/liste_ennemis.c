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
    //nouveau->sprite=text;
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

