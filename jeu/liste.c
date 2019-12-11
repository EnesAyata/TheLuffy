
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
perso_t* creeEntite(SDL_Rect src,SDL_Rect dest,SDL_Texture*text,int vie){
    perso_t *nouveau = malloc(sizeof(perso_t));
    nouveau->src=src;
    nouveau->dest=dest;
    //nouveau->sprite=text;
    nouveau->vie=vie;
    nouveau->precedent=NULL;
    nouveau->suivant=NULL;
    return nouveau;
}

void supprimer(Liste_t*liste,perso_t* asupp){//ajouter un ID dans la struct et l'incrémenter a chaque fois qu'on supprimer ou ajoute un element
    
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->lenght !=0)
    {
        
        //Element_t * aSupprimer = liste->premier;
        if(liste->premier==asupp){
            
            liste->premier = liste->premier->suivant;
        }
        else{
            asupp->precedent->suivant=asupp->suivant;
            
        }
        free(asupp);
        
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
