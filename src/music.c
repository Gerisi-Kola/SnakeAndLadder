#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include "constant.h"

int music_init(){
    // Initialiser SDL
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
        printf("Erreur SDL: %s\n", SDL_GetError());
        return -1;
    }
    
    // Initialiser SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Erreur SDL_mixer: %s\n", Mix_GetError());
        return -1;
    }
    return 0;
}


//      -------------------- MUSIC LOAD --------------------

int music_bg_load(Mix_Music **music){
    *music = Mix_LoadMUS(FILE_MUSIC_BG);
    if (*music == NULL) {
        printf("Erreur chargement musique: %s\n", Mix_GetError());
        return -1;
    }
    return 0;
}

int music_button_load(Mix_Chunk **music){
    *music = Mix_LoadWAV(FILE_MUSIC_BUTTON);
    if (*music == NULL) {
        printf("Erreur chargement musique: %s\n", Mix_GetError());
        return -1;
    }
    return 0;
}

int music_win_load(Mix_Chunk **music){
    *music = Mix_LoadWAV(FILE_MUSIC_WIN);
    if (*music == NULL) {
        printf("Erreur chargement musique: %s\n", Mix_GetError());
        return -1;
    }
    return 0;
}



//      -------------------- MUSIC PLAY --------------------

int music_bg_play(Mix_Music *music){
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(64); // 50% du volume
    return 0;
}

int music_button_play(Mix_Chunk *sound){
    if (sound == NULL) return -1;
    
    int channel = Mix_PlayChannel(-1, sound, 0); // Récupère le canal utilisé
    if (channel == -1) {
        printf("Erreur lors de la lecture du son: %s\n", Mix_GetError());
        return -1;
    }
    
    Mix_Volume(channel, 64); // Applique le volume uniquement au canal utilisé
    return 0;
}



int music_win_play(Mix_Chunk *sound){
    if (sound == NULL) return -1;
    
    int channel = Mix_PlayChannel(-1, sound, 0); // Récupère le canal utilisé
    if (channel == -1) {
        printf("Erreur lors de la lecture du son: %s\n", Mix_GetError());
        return -1;
    }
    
    Mix_Volume(channel, 64); // Applique le volume uniquement au canal utilisé
    return 0;
}




//      -------------------- MUSIC START --------------------

int start_music_bg(Mix_Music **music_bg, Mix_Chunk **music_button){
    music_init();
    music_bg_load(music_bg);
    music_button_load(music_button);
    music_bg_play(*music_bg);
    return 0;
}


int start_music_win(Mix_Chunk **music_win){
    if (*music_win == NULL) {
        music_win_load(music_win);
    }
    music_win_play(*music_win);
    //Mix_FreeChunk(*music_win);
    return 0;
}




//      -------------------- MUSIC CLEAR --------------------

int music_clear(Mix_Music **music_bg, Mix_Chunk **music_button, Mix_Chunk **music_win){
    Mix_FreeMusic(*music_bg);
    Mix_FreeChunk(*music_button);
    Mix_FreeChunk(*music_win);
    Mix_CloseAudio();
    return 0;
}
