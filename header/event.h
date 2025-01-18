#ifndef EVENT_H
#define EVENT_H
#include <SDL.h>

int event_create();

int button_check(int *stop,
                SDL_Event *events
                );

#endif