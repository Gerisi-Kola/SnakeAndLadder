#ifndef MUSIC_H
#define MUSIC_H

//#include "constant.h"
#include <SDL_mixer.h>

int music_init();

int music_bg_load(Mix_Music **music);
int music_button_load(Mix_Chunk **music);
int music_win_load(Mix_Chunk **music);

int music_bg_play(Mix_Music *music);
int music_button_play(Mix_Chunk *music);
int music_win_play(Mix_Chunk *music);

int start_music_bg(Mix_Music **music_bg, Mix_Chunk **music_button);
int start_music_win(Mix_Chunk **music_win);

int music_clear(Mix_Music **music_bg, Mix_Chunk **music_button, Mix_Chunk **music_win);

#endif  