#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>


int destroy_window(SDL_Window *window,SDL_Renderer *renderer){
    // Cette fonction ferme SDL et détruit tout ce qui doit l’être
    if (NULL != renderer){
        SDL_DestroyRenderer(renderer);
    }
    if (NULL != window){
        SDL_DestroyWindow(window);
    }
    
    SDL_Quit();
    
    return 0;
}

int image_load(SDL_Window *window,SDL_Renderer *renderer,SDL_Texture *texture, SDL_Surface *picture){
    picture = IMG_Load("image/chateau_qui_brule_honkai.jpg");
    texture = SDL_CreateTextureFromSurface(renderer, picture);
    
    // Afficher l'image
    SDL_RenderClear(renderer);  // Effacer l'écran
    SDL_RenderCopy(renderer, texture, NULL, NULL);  // Afficher la texture dans la fenêtre
    SDL_RenderPresent(renderer);  // Actualiser l'écran
    return 0;
}

int create_window(){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture = NULL;
    
    if (0 != SDL_Init(SDL_INIT_VIDEO)){
        SDL_Quit();
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    window = SDL_CreateWindow("Snake and ladder",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,SDL_WINDOW_SHOWN);
    if (NULL == window){
        SDL_Quit();
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (NULL == renderer){
        SDL_Quit();
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    image_load(window,renderer,texture,picture);
    SDL_Delay(5000);
    
    
    return 0;
}