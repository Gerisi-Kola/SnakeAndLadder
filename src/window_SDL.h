#ifndef Window_SDL
#define Window_SDL
#include <SDL.h>

int create_window(SDL_Window **window,SDL_Renderer **renderer);
int image_load(SDL_Renderer *renderer,SDL_Texture **texture, SDL_Surface **picture);
int destroy_window(SDL_Window *window,SDL_Renderer *renderer);

#endif