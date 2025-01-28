#ifndef GAME_LOOP_H
#define GAME_LOOP_H
#include <SDL.h>



int main_menu_button_image_load(SDL_Renderer *renderer,
                                SDL_Texture **texture,
                                SDL_Surface **picture,
                                SDL_Rect rect_bg
);

int area_creator(int area[]);

int check_snake_and_ladder( int area[],
                            int players_pos[],
                            int turn,
                            int number_of_player
);

int image_refresher_game(   int number_of_player,
                            SDL_Renderer *renderer,
                            SDL_Texture **texture,
                            SDL_Texture **texture_button,
                            SDL_Rect rect_button,
                            SDL_Rect player_rects[],
                            SDL_Texture *array_texture_player[],
                            char *array_of_images_players[]
);

int game_main_loop( int number_of_player,
                    SDL_Renderer *renderer,
                    SDL_Texture **texture,
                    SDL_Texture **texture_button,
                    SDL_Rect rect_button,
                    SDL_Rect player_rects[],
                    SDL_Texture *array_texture_player[],
                    SDL_Rect rect_transition_player[],
                    int actual_player,
                    int turn,
                    int *roll_result,
                    int players_pos[],
                    int area[],
                    char *array_of_images_players[]
);

#endif