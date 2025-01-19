#include <stdio.h> 
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "constant.h"
//#include "window_SDL.h"



int button_check(int *stop, SDL_Event *events){
    while (SDL_PollEvent(events)){
        
        if (events->type == SDL_QUIT) {
            // Si l'événement est de type SDL_QUIT, on arrête la boucle
            *stop = 1;
            printf("Fermeture de la fenetre\n");
            return 0;
        }
        
        else if (events->type == SDL_MOUSEBUTTONDOWN){
            //On vérifie si le bouton a été cliquer
            if (    events->button.x >= BUTTON_LOCATION_X
                &&  events->button.x <= BUTTON_LOCATION_X+BUTTON_SIZE_W
                &&  events->button.y >= BUTTON_LOCATION_Y
                &&  events->button.x <= BUTTON_LOCATION_Y+BUTTON_SIZE_H){
                    return 1;
            }
        }
    }
    return 0;
}

int event_create(){
    if (0 != SDL_InitSubSystem(SDL_INIT_EVENTS)){
        printf("SubSysteme Error : Les evenements n'ont pas ete initialiser !!");
    }
    return  0;
}