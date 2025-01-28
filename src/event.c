#include <stdio.h> 
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"
#include "player.h"



int button_check(int *stop, SDL_Event *events, int *state_game, int *state_menu){
    while (SDL_PollEvent(events)){
        
        if (events->type == SDL_QUIT) {
            // Si l'événement est de type SDL_QUIT, on arrête la boucle
            *stop = 1;
            printf("\nFermeture de la fenetre\n");
            return 0;
        }
        
        else if (events->type == SDL_MOUSEBUTTONDOWN){
            //On vérifie si le bouton a été cliquer
            if (*state_game == 1){
                if (    events->button.x >= BUTTON_LOCATION_X
                    &&  events->button.x <= BUTTON_LOCATION_X+BUTTON_SIZE_W
                    &&  events->button.y >= BUTTON_LOCATION_Y
                    &&  events->button.y <= BUTTON_LOCATION_Y+BUTTON_SIZE_H){
                    return 1;
                }
            }
            
            else if (*state_menu == 1){
                if (    events->button.x >= BUTTON_LOCATION_X
                    &&  events->button.x <= BUTTON_LOCATION_X+BUTTON_SIZE_W
                    &&  events->button.y >= BUTTON_MENU_PLAYER1_Y
                    &&  events->button.y <= BUTTON_MENU_PLAYER1_Y+BUTTON_SIZE_H){
                    *state_game = 1;
                    return 1;
                }
                else if (    events->button.x >= BUTTON_LOCATION_X
                    &&  events->button.x <= BUTTON_LOCATION_X+BUTTON_SIZE_W
                    &&  events->button.y >= BUTTON_MENU_PLAYER2_Y
                    &&  events->button.y <= BUTTON_MENU_PLAYER2_Y+BUTTON_SIZE_H){
                    *state_game = 1;
                    return 2;
                }
                else if (    events->button.x >= BUTTON_LOCATION_X
                    &&  events->button.x <= BUTTON_LOCATION_X+BUTTON_SIZE_W
                    &&  events->button.y >= BUTTON_MENU_PLAYER3_Y
                    &&  events->button.y <= BUTTON_MENU_PLAYER3_Y+BUTTON_SIZE_H){
                    *state_game = 1;
                    return 3;
                }
                else if (    events->button.x >= BUTTON_LOCATION_X
                    &&  events->button.x <= BUTTON_LOCATION_X+BUTTON_SIZE_W
                    &&  events->button.y >= BUTTON_MENU_PLAYER4_Y
                    &&  events->button.y <= BUTTON_MENU_PLAYER4_Y+BUTTON_SIZE_H){
                    *state_game = 1;
                    return 4;
                }
            }
        }
    }
    return 0;
}

int event_create(){
    if (0 != SDL_InitSubSystem(SDL_INIT_EVENTS)){
        printf("\nSubSysteme Error : Les evenements n'ont pas ete initialiser !!\n");
        return 1;
    }
    return  0;
}