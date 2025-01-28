#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"
#include "move_algo.h"

//Fonction qui permet de vérifier le nombre de joueur et de charger les images des joueurs
int check_number_of_player(int *number_of_player, char **array_of_images_players, int *ia_player){
    if (*number_of_player == 1) {
        array_of_images_players[0] = FILE_PLAYER;
        array_of_images_players[1] = FILE_IA;
        *ia_player = 1;
        *number_of_player = 2;
    }
    else {
        array_of_images_players[0] = FILE_PLAYER;
        array_of_images_players[1] = FILE_PLAYER2;
        array_of_images_players[2] = FILE_PLAYER3;
        array_of_images_players[3] = FILE_PLAYER4;
    }
    
    return 0;
}



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
                        char *array_of_images_players[]) {
    // Charger et afficher les textures des joueurs
    SDL_Surface *picture;
    picture = NULL;
    
    for (int i = 0; i < number_of_player; i++) {
        picture = IMG_Load(array_of_images_players[i]);
        if (picture == NULL) {
            printf("Erreur chargement image joueur %d: %s\n", i, IMG_GetError());
            return -1;
        }
        player_image_load(renderer, &array_texture_player[i], &picture, player_rects[i]);
    }
    
    return 0;
}




int player_animation(int actual_player, SDL_Rect player_rects[], SDL_Rect rect_old_player, SDL_Rect rect_transition_player[]){
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
    }
    
    for (int i = 0; i < MOVE_STEP; i++) {
        rect_transition_player[i] = rect_array_player[i];
    }
    
    return 0;
}




int player_move(int actual_player, int roll_result, int players_pos[], SDL_Rect player_rects[], SDL_Rect rect_transition_player[], int *win){    
    SDL_Rect rect_old_player = player_rects[actual_player];
    
    calcul_new_pos(actual_player, players_pos, player_rects, roll_result, win);
    
    player_animation(actual_player, player_rects, rect_old_player, rect_transition_player);
    
    return 0;
    }