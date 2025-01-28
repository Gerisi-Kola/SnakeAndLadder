#ifndef MUSIC_H
#define MUSIC_H

//#include "constant.h"
#include <SDL_mixer.h>

int music_init();
int music_bg_load(Mix_Music **music);
int music_button_load(Mix_Chunk **music);
int music_bg_play(Mix_Music *music);
int music_button_play(Mix_Chunk *music);

#endif  