#include <stdio.h> 
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"

int player_image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg) {
    *texture = SDL_CreateTextureFromSurface(renderer, *picture);
    
    SDL_QueryTexture(*texture, NULL, NULL, &rect_bg.w, &rect_bg.h);
    
    // Afficher l'image
    SDL_RenderCopy(renderer, *texture, NULL, &rect_bg);  // Afficher la texture dans la fenêtre
    return 0;
}

int player_create_loop( int number_of_player,
                        SDL_Renderer *renderer,
                        SDL_Rect player_rects[],
                        SDL_Texture *array_texture_player[],
                        SDL_Surface **picture,
                        const char *array_of_images_players[]
                        /*SDL_Texture **texture_j1,
                        SDL_Texture **texture_j2,
                        SDL_Texture **texture_j3,
                        SDL_Texture **texture_j4,
                        SDL_Surface **picture,
                        SDL_Rect rect_j1,
                        SDL_Rect rect_j2,
                        SDL_Rect rect_j3,
                        SDL_Rect rect_j4*/
                        ){
    
    for (int i = 0; i < number_of_player; i ++){
        *picture = IMG_Load(array_of_images_players[i]);
        player_image_load(renderer, &array_texture_player[i], picture, player_rects[i]);
    }
    //player2_image_load(renderer, &texture_j2, &picture, rect_j2);
    //player_image_load(renderer, &texture_j1, &picture, rect_j1);
    return 0;
}



int player2_image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg) {
    *texture = SDL_CreateTextureFromSurface(renderer, *picture);
    
    SDL_QueryTexture(*texture, NULL, NULL, &rect_bg.w, &rect_bg.h);
    
    // Afficher l'image
    SDL_RenderCopy(renderer, *texture, NULL, &rect_bg);  // Afficher la texture dans la fenêtre
    return 0;
}