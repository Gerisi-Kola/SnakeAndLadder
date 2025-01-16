#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

int player_image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg);
//int player2_image_load(SDL_Renderer *renderer, SDL_Texture **texture, SDL_Surface **picture, SDL_Rect rect_bg);

/*
int player_create_loop(  int number_of_player,
                        SDL_Renderer *renderer,
                        SDL_Texture **texture_j1,
                        SDL_Texture **texture_j2,
                        SDL_Texture **texture_j3,
                        SDL_Texture **texture_j4,
                        SDL_Surface **picture,
                        SDL_Rect rect_j1,
                        SDL_Rect rect_j2,
                        SDL_Rect rect_j3,
                        SDL_Rect rect_j4);
*/

int player_create_loop(  int number_of_player,
                        SDL_Renderer *renderer,
                        SDL_Rect player_rects[],
                        SDL_Texture *array_texture_player[],
                        SDL_Surface **picture,
                        const char *array_of_images_players[]
);


int player_move(int number_of_player, int *player_turn, int players_pos[], SDL_Rect player_rects[]);
/*              (int player,
                SDL_Renderer *renderer,
                SDL_Rect player_rects[],
                SDL_Texture *array_texture_player[],
                SDL_Surface **picture,
                const char *array_of_images_players[]
                );
*/
#endif