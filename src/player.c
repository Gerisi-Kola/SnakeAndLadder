#include <stdio.h> 
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"
#include "move_algo.h"

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
                        ){
    if(number_of_player > 1){
        for (int i = 0; i < number_of_player; i ++){
            *picture = IMG_Load(array_of_images_players[i]);
            player_image_load(renderer, &array_texture_player[i], picture, player_rects[i]);
        }
    }
    else if (number_of_player == 1){
        *picture = IMG_Load(array_of_images_players[0]);
        player_image_load(renderer, &array_texture_player[0], picture, player_rects[0]);
        *picture = IMG_Load(array_of_images_players[4]);
        player_image_load(renderer, &array_texture_player[2], picture, player_rects[2]);
        
    }
    else{
        printf("number of player is incorrect, players are %d",number_of_player);
    }
    
    return 0;
}


int player_move(int number_of_player, int *turn, int *roll_result, int players_pos[], SDL_Rect player_rects[]){
    //À qui le tour ?
    int i = *turn % number_of_player;
    
    *roll_result = roll_die_number(roll_result);
    
    calcul_new_pos(i, players_pos, player_rects, *roll_result);
    
    *turn += 1;
    
    return 0;
    }