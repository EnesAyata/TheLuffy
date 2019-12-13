#include "collision.h"



int detect_col(SDL_Rect* luffy,char** map, int dep){
    int posLX= (((luffy->x))/TLuffy) ;
    int posLY= (((luffy->y))/TLuffy) ;
    if(dep==1){
        posLX= (((luffy->x)+15)/TLuffy) ;
        posLY= (((luffy->y)+10)/TLuffy);
        if(map[posLY][posLX]=='"')
            return 1;
    }
    else if(dep==0){
        posLX= (((luffy->x)-5)/TLuffy) ;
        posLY= (((luffy->y)+10)/TLuffy);
        if(map[posLY][posLX]=='"')
            return 1;
    }

    else if(dep==2){
        posLX= (((luffy->x)+10)/TLuffy) ;
        posLY= (((luffy->y)-5)/TLuffy);
        if(map[posLY][posLX]=='"')
            return 1;
    }

    else if(dep==3){
        posLX= (((luffy->x)+10)/TLuffy) ;
        posLY= (((luffy->y)+30)/TLuffy);
        if(map[posLY][posLX]=='"')
            return 1;
    }

    return 0;
}
