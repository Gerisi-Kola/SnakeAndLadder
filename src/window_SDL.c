#include <stdio.h> 
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"

int destroy_window(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture) {
    // Cette fonction ferme SDL et détruit tout ce qui doit l'être
    if (NULL != texture){
        SDL_DestroyTexture(texture);
    }
    if (NULL != renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (NULL != window) {
        SDL_DestroyWindow(window);
    }
    
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}

int renderer_refresh(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer); // Actualiser l'écran
    return 0;
}

int button_create(SDL_Renderer *renderer, SDL_Rect *rect_button, SDL_Surface **picture, SDL_Texture **texture_button) {
    // Créer la texture à partir de l'image
    *picture = IMG_Load(FILE_BUTTON);
    if(*picture == NULL) {
        fprintf(stderr, "Erreur IMG_Load : %s\n", IMG_GetError());
        return -1;
    }
    
    *texture_button = SDL_CreateTextureFromSurface(renderer, *picture);
    SDL_FreeSurface(*picture); // Libérer la surface après création de la texture
    *picture = NULL;
    
    if(*texture_button == NULL) {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
        return -1;
    }
    
    SDL_QueryTexture(*texture_button, NULL, NULL, &rect_button->w, &rect_button->h);
    SDL_RenderCopy(renderer, *texture_button, NULL, rect_button);
    return 0;
}

int image_bg_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg) {
    *picture = IMG_Load(FILE_BG);
    if(*picture == NULL) {
        fprintf(stderr, "Erreur IMG_Load : %s\n", IMG_GetError());
        return -1;
    }
    
    *texture = SDL_CreateTextureFromSurface(renderer, *picture);
    SDL_FreeSurface(*picture); // Libérer la surface après création de la texture
    *picture = NULL;
    
    if(*texture == NULL) {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
        return -1;
    }
    
    SDL_QueryTexture(*texture, NULL, NULL, &rect_bg.w, &rect_bg.h);
    SDL_RenderCopy(renderer, *texture, NULL, &rect_bg);
    return 0;
}

int create_window(SDL_Window **window, SDL_Renderer **renderer) {
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    *window = SDL_CreateWindow("Snake and ladder", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == *window) {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }
    
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == *renderer) {
        SDL_DestroyWindow(*window);
        *window = NULL;
        SDL_Quit();
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    return 0;
}