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
    if(number_of_player > 1){
        for (int i = 0; i < number_of_player; i ++){
            *picture = IMG_Load(array_of_images_players[i]);
            player_image_load(renderer, &array_texture_player[i], picture, player_rects[i]);
        }
    }
    else if (number_of_player == 1){
        /*for (int i = 0; i < 5; i += 4){
            *picture = IMG_Load(array_of_images_players[i]);
            player_image_load(renderer, &array_texture_player[i-1], picture, player_rects[i-1]);
        }
        */
        *picture = IMG_Load(array_of_images_players[0]);
        player_image_load(renderer, &array_texture_player[0], picture, player_rects[0]);
        *picture = IMG_Load(array_of_images_players[4]);
        player_image_load(renderer, &array_texture_player[2], picture, player_rects[2]);
        
    }
    else{
        printf("number of player is incorrect, players are %d",number_of_player);
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


int player_move(int number_of_player, int *turn, int *roll_result, int players_pos[], SDL_Rect player_rects[]){
    //À qui le tour ?
    int i = *turn % number_of_player;
    //printf("turn = %d number of player = %d et rest = %d\n\n",*turn,number_of_player,i);
    //printf("\ni = %d      player_pos = %d    players_pos[i]%10 != %d\n",i,players_pos[i],players_pos[i]%10);
    
    *roll_result = roll_die_number(roll_result);
    
    calcul_new_pos(i, players_pos, player_rects, *roll_result);
    
    /*
    if(players_pos[i]%10 != 0){
        player_rects[i].x += WINDOW_WIDTH/10;
    }
    else{
        player_rects[i].y += WINDOW_WIDTH/10;
    }
    */
    //players_pos[i] += 1;
    
    *turn += 1;
    /* *picture = IMG_Load(array_of_images_players[1]);
            player_image_load(renderer, &array_texture_player[1], picture, player_rects[1]);  */
    //player_create_loop(number_of_player,renderer,player_rects,array_texture_player,picture,array_of_images_players);
    return 0;
    }