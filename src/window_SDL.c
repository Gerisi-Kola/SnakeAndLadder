#include <stdio.h> 
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"

int destroy_window(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture) {
    // Cette fonction ferme SDL et détruit tout ce qui doit l’être
    if (NULL != renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (NULL != window) {
        SDL_DestroyWindow(window);
    }
    
    if (NULL != texture){
        SDL_DestroyTexture(texture);
    }
    
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}

int renderer_refresh(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer); // Actualiser l'écran
    return 0;
}

/*
//int button_create(SDL_Renderer *renderer, SDL_Rect *rect_button, SDL_Surface **picture, SDL_Texture **texture_button) {
    // Définir la couleur du rectangle (jaune)
    //SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    // Dessiner le rectangle
    *picture = IMG_Load(FILE_BUTTON);
    *texture_button = SDL_CreateTextureFromSurface(renderer, *picture);
    
    SDL_QueryTexture(*texture_button, NULL, NULL, &rect_button->w, &rect_button->h);
    
    // Afficher l'image
    SDL_RenderCopy(renderer, *texture_button, NULL, rect_button);  // Afficher la texture dans la fenêtre
    //SDL_RenderFillRect(renderer, rect_button);
    return 0;
}
*/

// Modifie la fonction button_create pour accepter un SDL_Rect* au lieu d'un SDL_Rect
int button_create(SDL_Renderer *renderer, SDL_Rect *rect_button, SDL_Surface **picture, SDL_Texture **texture_button) {
    // Créer la texture à partir de l'image
    *picture = IMG_Load(FILE_BUTTON);
    *texture_button = SDL_CreateTextureFromSurface(renderer, *picture);
    
    SDL_QueryTexture(*texture_button, NULL, NULL, &rect_button->w, &rect_button->h); // Utilise '->' pour accéder aux membres du rect_button
    
    // Afficher la texture
    SDL_RenderCopy(renderer, *texture_button, NULL, rect_button);  // Utilise 'rect_button' directement
    return 0;
}

int image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg) {
    *picture = IMG_Load(FILE_BG);
    *texture = SDL_CreateTextureFromSurface(renderer, *picture);
    
    SDL_QueryTexture(*texture, NULL, NULL, &rect_bg.w, &rect_bg.h);
    
    // Afficher l'image
    SDL_RenderCopy(renderer, *texture, NULL, &rect_bg);  // Afficher la texture dans la fenêtre
    return 0;
}

int create_window(SDL_Window **window, SDL_Renderer **renderer) {
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        destroy_window(*window, *renderer, NULL);
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    *window = SDL_CreateWindow("Snake and ladder", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (NULL == *window) {
        destroy_window(*window, *renderer, NULL);
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == *renderer) {
        destroy_window(*window, *renderer, NULL);
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    return 0;
}