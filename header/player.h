#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>

int check_number_of_player( int *number_of_player,
                            char **array_of_images_players,
                            int *ia_player
);

int player_image_load(  SDL_Renderer *renderer,
                        SDL_Texture **texture,
                        SDL_Surface **picture,
                        SDL_Rect rect_bg
                        );

int player_refresh_loop(  int number_of_player,
                        SDL_Renderer *renderer,
                        SDL_Rect player_rects[],
                        SDL_Texture *array_texture_player[],
                        char *array_of_images_players[]
                        );

int player_move(int actual_player,
                int roll_result,
                int players_pos[],
                SDL_Rect player_rects[],
                SDL_Rect rect_transition_player[]
                );

#endif