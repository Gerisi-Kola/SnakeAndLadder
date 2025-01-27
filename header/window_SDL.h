#ifndef Window_SDL
#define Window_SDL
#include <SDL.h>

int create_window(  SDL_Window **window,
                    SDL_Renderer **renderer
                    );

int image_bg_load( SDL_Renderer *renderer,
                    SDL_Texture **texture
                    );

int destroy_window( SDL_Window *window,
                    SDL_Renderer *renderer,
                    SDL_Texture *texture
                    );

int button_create(  SDL_Renderer *renderer,
                    SDL_Rect *rect_button,
                    SDL_Texture **texture_button
                    );

int renderer_refresh(SDL_Renderer *renderer);

#endif