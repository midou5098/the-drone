#include "headers.h"

int main(void){
    SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    SDL_Window* window=SDL_CreateWindow("fuckass drone",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
bool running=true;
SDL_Event event;
while (running){
    while(SDL_PollEvent(&event)){
        if (event.type==SDL_QUIT){
            running =false;

        }
    }
    SDL_SetRenderDrawColor(renderer,140,90,180,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}
TTF_Quit();
IMG_Quit();
SDL_Quit();


}