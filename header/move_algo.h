#ifndef MOVE_ALGO_H
#define MOVE_ALGO_H
#include <SDL.h>

int roll_die_number(int *previous_result);

int calcul_new_pos( int i,
                    int players_pos[],
                    SDL_Rect player_rects[],
                    int roll_num,
                    int *win
                    );

#endif