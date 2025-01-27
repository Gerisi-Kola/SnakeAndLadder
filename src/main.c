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
#include "music.h"
#include "main_menu_button.h"
#include "game_loop.h"

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
    SDL_Texture *texture_button_menu[4] = {NULL,NULL,NULL,NULL};
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
        
        // SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
        // SDL_RenderClear(renderer);
        // SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
        
        // main_menu_button_init(texture_button_menu, renderer);
        // SDL_Delay(500);
        
        
        //Effectue le déplacement du joueur concerner et rafraîchi l'affichage
        if (die_roll == 1){
            game_main_loop(number_of_player,
                            renderer,
                            &texture,
                            &texture_button,
                            rect_button,
                            player_rects,
                            array_texture_player,
                            rect_transition_player,
                            actual_player,
                            turn,
                            &roll_result,
                            players_pos,
                            area,
                            array_of_images_players);
            
            turn ++;
        }
        
        SDL_Delay(200);
    }
    
    // Nettoyage
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
    destroy_window(window, renderer, texture);
    
    return 0;
}