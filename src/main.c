//gcc -Wall -Wextra -I"D:_lib/include" .\src\Window_SDL.c -o ./bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//gcc -Wall -Wextra .\src\*.c -o bin/prog -I include -I header -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include "window_SDL.h"
#include "constant.h"
#include "event.h"
#include "player.h"
#include "move_algo.h"
//#include "music.h"

int image_refresher_game(int number_of_player,
                    SDL_Renderer *renderer,
                    SDL_Texture **texture,
                    SDL_Texture **texture_button,
                    SDL_Rect rect_button,
                    SDL_Rect player_rects[],
                    SDL_Texture *array_texture_player[],
                    const char *array_of_images_players[]){
    
    // Créer et dessiner le bouton (rectangle jaune)
    button_create(renderer, &rect_button, texture_button);
    
    // Charger et afficher l'image (si nécessaire)
    image_bg_load(renderer, texture);
    
    player_refresh_loop(number_of_player,
                        renderer,
                        player_rects,
                        array_texture_player,
                        array_of_images_players);
    
    // Actualiser l'affichage pour que les dessins soient visibles
    renderer_refresh(renderer);
    return 0;
}

int area_creator(int area[]){
    //Cree le terrin (les serpents et les échelles) 
    //debut = 0 et fin = 99
    
    //Il y a un décalage de 1 entre l'index de la case et la case
    // Ladders
    area[1]  = 36; //38
    area[3]  = 10; //14
    area[8]  = 22; //31
    area[20] = 21; //42
    area[24] = 10; //35
    area[44] = 12; //57
    area[50] = 17; //68
    area[64] = 12; //77
    area[71] = 21; //93
    area[81] = 16; //98
    
    //Snakes
    area[12] = -6;  //7
    area[16] = -10; //7
    area[32] = -4;  //29
    area[53] = -27; //27
    area[55] = -12; //44
    area[61] = -43; //19
    area[69] = -21; //49
    area[93] = -19; //75
    area[95] = -20; //76
    area[98] = -16; //83
    return 0;
}


int check_snake_and_ladder(int area[],int players_pos[],int turn,int number_of_player){
    int actual_player = turn % number_of_player;
    int pos =  players_pos[actual_player];
    return area[pos];
}


int main(int argc, char *argv[]) {
    (void)argc; // Indique explicitement que tu n'utilises pas 'argc'
    (void)argv; // Indique explicitement que tu n'utilises pas 'argv'
    
    int stop = 0;
    int actual_player = 0;
    int number_of_player = 3;
    int die_roll = 0;
    int roll_result = SEED_2;
    int turn = 0;
    int players_pos[4] = {0,0,0,0};
    int area[100] = {0};
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Texture *texture_button = NULL;
    SDL_Event events;
    // Mix_Music *music_bg = NULL;
    // Mix_Music *music_button = NULL;
    SDL_Rect rect_button = {BUTTON_LOCATION_X,BUTTON_LOCATION_Y,BUTTON_SIZE_W,BUTTON_SIZE_H};  // Position et taille du rectangle
    //SDL_Rect rect_bg = {0, 0, WINDOW_WIDTH, WINDOW_WIDTH};  // Dimensions de l'image
    SDL_Rect rect_transition_player[MOVE_STEP] = {0};
    //Player
    SDL_Rect player_rects[4] = {
            {POS_X,  POS_Y, 40, 40},  // Player 1
            {POS_X*2,  POS_Y, 40, 40}, // Player 2
            {POS_X*3,  POS_Y, 40, 40}, // Player 3
            {POS_X*4,  POS_Y, 40, 40}  // Player 4
            };
    
    SDL_Texture* array_texture_player[4] = {NULL,NULL,NULL,NULL};
    
    const char *array_of_images_players_4[] = {
            FILE_PLAYER,
            FILE_PLAYER2,
            FILE_PLAYER3,
            FILE_PLAYER4,
            FILE_IA
            };
    
    const char *array_of_images_players_2[] = {
            FILE_PLAYER,
            FILE_IA
        };
    
    const char **array_of_images_players;
    
    if (number_of_player == 1){
        array_of_images_players = array_of_images_players_2;
        number_of_player = 2;
    }
    else{
        array_of_images_players = array_of_images_players_4;
    }
    
    area_creator(area);
    
    // Créer la fenêtre et le renderer
    if (create_window(&window, &renderer) != 0) {
        return EXIT_FAILURE;
    }
    
    // Effacer l'écran (fond rouge)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    image_refresher_game(
                            number_of_player,
                            renderer,
                            &texture,
                            &texture_button,
                            rect_button,
                            player_rects,
                            array_texture_player,
                            array_of_images_players);
    
    /*
    music_init();
    music_bg_load(&music_bg);
    music_button_load(&music_button);
    music_bg_play(music_bg);
    */
    
    // Initialise les événements
    stop = event_create();
    while (stop == 0){
        
        die_roll = button_check(&stop, &events);
        
        //Effectue le déplacement du joueur concerner et rafraîchi l'affichage
        if (die_roll == 1){
            //music_button_play(music_button);
            
            actual_player = turn % number_of_player;
        if (actual_player == 3
            || (number_of_player == 2 && actual_player == 1)
            || (number_of_player == 3 && actual_player == 2)
            ){
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rouge
            }
            else if (actual_player == 0){
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Bleu
            }
            else if (actual_player == 1){
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Vert
            }
            else if (actual_player == 2){
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Jaune
            }
            SDL_RenderClear(renderer);
            
            roll_result = roll_die_number(&roll_result);
                        
            player_move(    actual_player,
                            roll_result,
                            players_pos,
                            player_rects,
                            rect_transition_player);
            for (int i = 0; i < MOVE_STEP; i++){
                //printf("rect_transition_player[%d].x = %d, rect_transition_player[%d].y = %d\n", i, rect_transition_player[i].x, i, rect_transition_player[i].y);
                //printf("player_rects[%d].x = %d, player_rects[%d].y = %d\n", actual_player, player_rects[actual_player].x, actual_player, player_rects[actual_player].y);
                player_rects[actual_player] = rect_transition_player[i];
                image_refresher_game(
                            number_of_player,
                            renderer,
                            &texture,
                            &texture_button,
                            rect_button,
                            player_rects,
                            array_texture_player,
                            array_of_images_players);
                SDL_Delay(DELAY_MOVE_MAX/MOVE_STEP);
            }
            
            renderer_refresh(renderer);
            
            int area_table = check_snake_and_ladder(area, players_pos, turn, number_of_player);
            
            if (area_table != 0){
                SDL_Delay(300);
                player_move(actual_player,
                            area_table,
                            players_pos,
                            player_rects,
                            rect_transition_player);
                
                for (int i = 0; i < MOVE_STEP; i++){
                    player_rects[actual_player] = rect_transition_player[i];
                    image_refresher_game(
                            number_of_player,
                            renderer,
                            &texture,
                            &texture_button,
                            rect_button,
                            player_rects,
                            array_texture_player,
                            array_of_images_players);
                    SDL_Delay(((DELAY_MOVE_MAX/MOVE_STEP)*2)/3);
                }
                
                renderer_refresh(renderer);
            }
        turn ++;
        
        }
        SDL_Delay(200);
    }
    
    // Nettoyage
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
    destroy_window(window, renderer, texture);
    
    return 0;
}