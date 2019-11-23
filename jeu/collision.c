#include "collision.h"



int detect_col(SDL_Rect* luffy,char** map, int dep){
    //printf("La pos x de luffy : %d , et y : %d\n",luffy->x,luffy->y);
    //printf("La pos en tab x : %d et en tab y: %d \n ",luffy->x/TLuffy,luffy->y/TLuffy);
    int posLX= (((luffy->x)+10)/TLuffy) ;//on crée un point au mileu de luffy
    int posLY= (((luffy->y)+10)/TLuffy) ;
    if(map[posLY][posLX]=='"'){
        printf("Luffy est dedans ! on recule ");

        /*switch(dep){
            case 0:luffy->x+=2;break;

        }*/
    }
    int X=luffy->x;
    int Y=luffy->y;
    printf("Pos en x %d et en y %d \n",posLX,posLY);
    printf("Le bloc a droite de luffy est : %c\n",map[posLY][posLX]);

    //on verif si ya rien a droite 
    posLX= (((luffy->x)+15)/TLuffy) ;//on crée un point au mileu de luffy
    posLY= (((luffy->y)+10)/TLuffy);
    if(map[posLY][posLX]=='"')
        printf("il ya collision a droite ! \n");
    //on verif a gauche 
    posLX= (((luffy->x)-5)/TLuffy) ;//on crée un point au mileu de luffy
    posLY= (((luffy->y)+10)/TLuffy);
    if(map[posLY][posLX]=='"')
        printf("il ya collision gauche ! \n");

    //on verif le bas
    //posLX= (((luffy->x)+10)/TLuffy) ;//on crée un point au mileu de luffy
    //posLY= (((luffy->y)+10)/TLuffy);


    return 0;
}
