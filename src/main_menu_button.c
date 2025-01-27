#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"


int main_menu_button_image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg) {
    // Libérer la texture existante si elle existe
    //SDL_Surface *picture = NULL;

    if (*texture != NULL) {
        SDL_DestroyTexture(*texture);
    }
    *texture = SDL_CreateTextureFromSurface(renderer, *picture);
    SDL_FreeSurface(*picture); // Libérer la surface après création de la texture
    
    SDL_QueryTexture(*texture, NULL, NULL, &rect_bg.w, &rect_bg.h);
    
    // Afficher l'image
    SDL_RenderCopy(renderer, *texture, NULL, &rect_bg);  // Afficher la texture dans la fenêtre
    return 0;
}

int main_menu_button_init(SDL_Texture *texture_button[], SDL_Renderer *renderer){
    printf("init button\n");
    SDL_Surface *picture;
    picture = NULL;
    SDL_Rect rect_button[4] = {
            {BUTTON_LOCATION_X,  BUTTON_MENU_PLAYER1_Y, BUTTON_SIZE_W, BUTTON_SIZE_H},  // Player 1
            {BUTTON_LOCATION_X,  BUTTON_MENU_PLAYER2_Y, BUTTON_SIZE_W, BUTTON_SIZE_H}, // Player 2
            {BUTTON_LOCATION_X,  BUTTON_MENU_PLAYER3_Y, BUTTON_SIZE_W, BUTTON_SIZE_H}, // Player 3
            {BUTTON_LOCATION_X,  BUTTON_MENU_PLAYER4_Y, BUTTON_SIZE_W, BUTTON_SIZE_H}  // Player 4
            };
    
    
    for (int i = 0; i < 4; i++){
        picture = IMG_Load(FILE_BUTTON_PLAY_1); //array_of_images_button[i]);
        if (picture == NULL) {
                printf("Erreur chargement image joueur %d: %s\n", i, IMG_GetError());
                return -1;
            }
        main_menu_button_image_load(renderer, &texture_button[i], &picture, rect_button[i]);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &rect_button[i]);
        SDL_RenderFillRect(renderer, &rect_button[i]); 
        
    }
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    return 0;
}

int main_menu_button_render(SDL_Texture *texture_button_play_1, SDL_Texture *texture_button_play_2, SDL_Texture *texture_button_play_3, SDL_Texture *texture_button_play_4, SDL_Renderer *renderer){

    return 0;
}
