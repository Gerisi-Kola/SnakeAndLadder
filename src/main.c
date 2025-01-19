//gcc -Wall -Wextra -I"D:_lib/include" .\src\Window_SDL.c -o ./bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//gcc -Wall -Wextra .\src\*.c -o bin/prog -I include -I header -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include "window_SDL.h"
#include "constant.h"
#include "event.h"
#include "player.h"


int image_refresher(int number_of_player,
                    int *turn,
                    int *roll_result,
                    int players_pos[],
                    SDL_Renderer *renderer,
                    SDL_Texture **texture,
                    SDL_Texture **texture_button,
                    SDL_Rect rect_button,
                    SDL_Rect rect_bg,
                    SDL_Rect player_rects[],
                    SDL_Texture *array_texture_player[],
                    SDL_Surface **picture,
                    const char *array_of_images_players[]){
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Créer et dessiner le bouton (rectangle jaune)
    button_create(renderer, &rect_button, picture, texture_button);
    
    // Charger et afficher l'image (si nécessaire)
    image_load(renderer, texture, picture, rect_bg);
    
    player_move(number_of_player,
                turn,roll_result,
                players_pos,
                player_rects);
    player_create_loop( number_of_player,
                        renderer,
                        player_rects,
                        array_texture_player,
                        picture,
                        array_of_images_players);
    
    renderer_refresh(renderer);
    
    return 0;
}

int area_creator(int area[]){
    //Cree le terrin (les serpents et les echelles) 
    //debut = 0 et fin = 99
    
    // Ladders
    area[2] = 36;  //38
    area[4] = 10;  //14
    area[9] = 22;  //31
    area[21] = 21; //42
    area[28] = 53; //81
    area[51] = 16; //67
    area[74] = 17; //91
    area[77] = 10; //87
    area[80] = 15; //95
    area[85] = 5;  //90
    
    //Snakes
    area[17] = -10; //7
    area[35] = -15; //20
    area[54] = -20; //34
    area[62] = -43; //19
    area[64] = -4;  //60
    area[87] = -50; //37
    area[93] = -20; //73
    area[94] = -19; //75
    area[96] = -20; //76
    area[98] = -5;  //93
    
    return 0;
}

int main(int argc, char *argv[]) {
    (void)argc; // Indique explicitement que tu n'utilises pas 'argc'
    (void)argv; // Indique explicitement que tu n'utilises pas 'argv'
    
    int stop = 0;
    int number_of_player = 4;
    int die_roll = 0;
    int roll_result = SEED_2;
    int turn = 0;
    int players_pos[4] = {1,1,1,1};
    int area[100] = {0};
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Texture *texture_button = NULL;
    SDL_Surface *picture = NULL;
    SDL_Event events;
    SDL_Rect rect_button = {BUTTON_LOCATION_X,BUTTON_LOCATION_Y,BUTTON_SIZE_W,BUTTON_SIZE_H};  // Position et taille du rectangle
    SDL_Rect rect_bg = {0, 0, WINDOW_WIDTH, WINDOW_WIDTH};  // Dimensions de l'image
    //Player
    SDL_Rect player_rects[4] = {
            {4,  550, 40, 40},  // Player 1
            {9,  550, 40, 40}, // Player 2
            {14, 550, 40, 40}, // Player 3
            {19, 550, 40, 40}  // Player 4
            };
    
    SDL_Texture* array_texture_player[4] = {NULL,NULL,NULL,NULL};
    
    const char* array_of_images_players[5] = {
            FILE_PLAYER,
            FILE_PLAYER2,
            FILE_PLAYER3,
            FILE_PLAYER4,
            FILE_IA
            };
    
    
    area_creator(area);
    
    // Créer la fenêtre et le renderer
    if (create_window(&window, &renderer) != 0) {
        return EXIT_FAILURE;
    }
    
    // Effacer l'écran (fond noir)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Créer et dessiner le bouton (rectangle jaune)
    button_create(renderer, &rect_button, &picture, &texture_button);
    
    // Charger et afficher l'image (si nécessaire)
    image_load(renderer, &texture, &picture, rect_bg);
    
    player_create_loop(number_of_player,renderer,player_rects,array_texture_player,&picture,array_of_images_players);
    // Actualiser l'affichage pour que les dessins soient visibles
    renderer_refresh(renderer);
    
    // Initialise les événements
    event_create();
    while (stop == 0){
        
        die_roll = button_check(&stop, &events);
        
        //Effectue le déplacement du joueur concerner et rafraîchi l'affichage
        if (die_roll == 1){
            die_roll = image_refresher(
                            number_of_player,
                            &turn,
                            &roll_result,
                            players_pos,
                            renderer,
                            &texture,
                            &texture_button,
                            rect_button,
                            rect_bg,
                            player_rects,
                            array_texture_player,
                            &picture,
                            array_of_images_players);
            
            //check_snake_and_ladder
        }
        SDL_Delay(200);
    }
    
    // Nettoyage
    destroy_window(window, renderer, texture);
    
    return 0;
}