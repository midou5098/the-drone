#include "headers.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>

void animate(int x, int y, int dir, SDL_Texture *drone,SDL_Renderer* renderer,Uint32 currentime,Uint32 lastime,int cur_fra){
    int texw,texh;
    SDL_QueryTexture(drone,NULL,NULL,&texw,&texh);

    
    int framewidth=texw/6;
    int frameheight=texh/6;
    
    int framex=cur_fra%6;
    int framey=cur_fra/6;
    SDL_Rect rect={framex*framewidth,framey*frameheight,framewidth,frameheight};
    SDL_Rect dst={x,y,150,150};
    if(dir==1){
        SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer,drone,&rect,&dst,0.0,NULL,flip);
    }else{
        SDL_RenderCopy(renderer,drone,&rect,&dst);

    }
    
    
    
    
    
    

}