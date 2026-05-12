#include "headers.h"
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_timer.h>

int main(void){
    SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Window* window=SDL_CreateWindow("fuckass drone",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_Surface* s=IMG_Load("assets/drone.png");
    SDL_Texture* drone=SDL_CreateTextureFromSurface(renderer,s);
    Uint32 currentime,lastime=0;
    int cur=0;
    int dir=0;//gonna use 0 for left and 1 for right 
    int frame_d=50;
    int px=300,py=300;
    
    bool running=true;
    SDL_Event event; //bitchass timing the mf wont start
    while (running){
        

        while(SDL_PollEvent(&event)){
            if (event.type==SDL_QUIT){
                running =false;

            }else if (event.type==SDL_KEYDOWN){
                SDL_KeyCode key=event.key.keysym.sym;
                if (key==SDLK_DOWN){
                    py+=10;
                }else if (key==SDLK_UP){
                    py-=10;

                }else if (key==SDLK_LEFT){
                    px-=10;
                    dir=0;
//here i was stuck for about 20 minutes just bcz i used =+ instead of -= .. bruh things be just overreacting walah
                }else if (key==SDLK_RIGHT){
                    px+=10;
                    dir=1;

                }

            }
        }
        currentime=SDL_GetTicks();
        if (currentime>lastime+frame_d){
            lastime=currentime;
            cur=(cur+1)%36;
        }
        
        SDL_SetRenderDrawColor(renderer,140,90,180,255);
        SDL_RenderClear(renderer);
        animate(px,py,dir,drone,renderer,currentime,lastime,cur);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();


}