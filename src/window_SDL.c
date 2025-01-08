#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>



int window_fonc(){
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("YO",600,600,600,600,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    
    SDL_Delay(1000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}