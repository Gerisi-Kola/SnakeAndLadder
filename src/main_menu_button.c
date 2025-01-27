.#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>

/*
int main_menu_button_image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg) {
    // Libérer la texture existante si elle existe
    //SDL_Surface *picture = NULL;

    if (*texture != NULL) {
        SDL_DestroyTexture(*texture);
    }
    *texture = SDL_CreateTextureFromSurface(renderer, picture);
    SDL_FreeSurface(picture); // Libérer la surface après création de la texture
    
    SDL_QueryTexture(*texture, NULL, NULL, &rect_bg.w, &rect_bg.h);
    
    // Afficher l'image
    SDL_RenderCopy(renderer, *texture, NULL, &rect_bg);  // Afficher la texture dans la fenêtre
    return 0;
}

int main_menu_button_init(SDL_Texture *texture_button[], const char *array_of_images_button[], SDL_Renderer *renderer, SDL_Surface **picture, SDL_Rect rect_button[]){
    for (int i = 0; i < 4; i++){
        *picture = IMG_Load(array_of_images_button[i]);
        if (*picture == NULL) {
                printf("Erreur chargement image joueur %d: %s\n", i, IMG_GetError());
                return -1;
            }
            main_menu_button_image_load(renderer, &texture_button[i], picture, rect_button[i]);
    }
    return 0;
}

int main_menu_button_render(SDL_Texture *texture_button_play_1, SDL_Texture *texture_button_play_2, SDL_Texture *texture_button_play_3, SDL_Texture *texture_button_play_4, SDL_Renderer *renderer){

    return 0;
}
*/