#ifndef Window_SDL
#define Window_SDL
#include <SDL.h>

int destroy_window(SDL_Window *window,SDL_Renderer *renderer);
int image_load(SDL_Window *window,SDL_Renderer *renderer,SDL_Texture *texture, SDL_Surface *picture);
int create_window();

#endif