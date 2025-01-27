#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"
#include "move_algo.h"

int player_image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg) {
    // Libérer la texture existante si elle existe
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

int player_refresh_loop( int number_of_player,
                        SDL_Renderer *renderer,
                        SDL_Rect player_rects[],
                        SDL_Texture *array_texture_player[],
                        const char *array_of_images_players[]) {
    // Charger et afficher les textures des joueurs
    SDL_Surface *picture;
    picture = NULL;
    
    if(number_of_player > 1) {
        for (int i = 0; i < number_of_player; i++) {
            picture = IMG_Load(array_of_images_players[i]);
            if (picture == NULL) {
                printf("Erreur chargement image joueur %d: %s\n", i, IMG_GetError());
                return -1;
            }
            player_image_load(renderer, &array_texture_player[i], &picture, player_rects[i]);
        }
    }
    else if (number_of_player == 1) {
        picture = IMG_Load(array_of_images_players[0]);
        if (picture == NULL) {
            printf("Erreur chargement image joueur: %s\n", IMG_GetError());
            return -1;
        }
        player_image_load(renderer, &array_texture_player[0], &picture, player_rects[0]);
        
        picture = IMG_Load(array_of_images_players[4]);
        if (picture == NULL) {
            printf("Erreur chargement image IA: %s\n", IMG_GetError());
            return -1;
        }
        player_image_load(renderer, &array_texture_player[2], &picture, player_rects[2]);
    }
    
    return 0;
}

/*
int player_refresh_loop( int number_of_player,
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
*/

int player_animation(int actual_player, SDL_Rect player_rects[], SDL_Rect rect_old_player, SDL_Rect rect_transition_player[]){
    //printf("player_old_rect.x = %d, player_old_rect.y = %d\n", rect_old_player.x, rect_old_player.y);
    //printf("player_new_rect.x = %d, player_new_rect.y = %d\n", player_rects[actual_player].x, player_rects[actual_player].y);
    SDL_Rect rect_new_player;
    rect_new_player.x = player_rects[actual_player].x - rect_old_player.x;
    rect_new_player.y = player_rects[actual_player].y - rect_old_player.y;
    
    SDL_Rect rect_array_player[MOVE_STEP];
    for (int i = 0; i < MOVE_STEP-1; i++) {
        rect_array_player[i].w = rect_old_player.w;
        rect_array_player[i].h = rect_old_player.h;
        rect_array_player[i].x = rect_old_player.x + (rect_new_player.x*(i+1)/MOVE_STEP);
        rect_array_player[i].y = rect_old_player.y + (rect_new_player.y*(i+1)/MOVE_STEP);
    }
    rect_array_player[MOVE_STEP-1].x = player_rects[actual_player].x;
    rect_array_player[MOVE_STEP-1].y = player_rects[actual_player].y;
    for (int i = 0; i < MOVE_STEP; i++) {
        // printf("rect_array_player[%d].x = %d, rect_array_player[%d].y = %d\n", 
        //        i, rect_array_player[i].x, i, rect_array_player[i].y);
    }
    //printf("\n\n\n");
    
    for (int i = 0; i < MOVE_STEP; i++) {
        rect_transition_player[i] = rect_array_player[i];
    }
    
    //player_rects[actual_player].x = rect_array_player[9].x;
    //player_rects[actual_player].y = rect_array_player[9].y;
    return 0;
}

int player_move(int actual_player, int roll_result, int players_pos[], SDL_Rect player_rects[], SDL_Rect rect_transition_player[]){
    //À qui le tour ?
    //int actual_player = *turn % number_of_player;
    
    SDL_Rect rect_old_player = player_rects[actual_player];
    
    calcul_new_pos(actual_player, players_pos, player_rects, roll_result);
    
    player_animation(actual_player, player_rects, rect_old_player, rect_transition_player);
    
    return 0;
    }