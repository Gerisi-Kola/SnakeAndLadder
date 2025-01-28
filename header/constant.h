#ifndef CONSTANT_h
#define CONSTANT_h

#define WINDOW_HEIGHT        700
#define WINDOW_WIDTH         600

#define SEED                 199 //0x5f3759df //2151901553968352745
#define SEED_2               3

#define POS_Y                550
#define POS_X                4
#define POS_X_MAX            600

#define MAX_CASE             99

#define MOVE_STEP            20
#define DELAY_MOVE_MAX       00


#define FILE_BG              "image/Sans20titre.png" // 600x600 !!! Taille importante
/*
#define FILE_BUTTON          "image/go_image.png"
#define FILE_PLAYER          "image/j1.png"
#define FILE_PLAYER2         "image/j2_v2.png"
#define FILE_PLAYER3         "image/j3.png"
#define FILE_PLAYER4         "image/j4_v2.png"
#define FILE_IA              "image/ia.png"
*/

#define FILE_BUTTON          "image/go_image.png"
#define FILE_PLAYER          "image/j1_manuscrit.png"
#define FILE_PLAYER2         "image/j2_manuscrit.png"
#define FILE_PLAYER3         "image/j3_manuscrit.png"
#define FILE_PLAYER4         "image/j4_manuscrit.png"
#define FILE_IA              "image/ia_manuscrit.png"

#define FILE_BUTTON_1_PLAYER   "image/go_image.png" //"image/play_1.png"
#define FILE_BUTTON_2_PLAYER   "image/go_image.png" //"image/play_2.png"
#define FILE_BUTTON_3_PLAYER   "image/go_image.png" //"image/play_3.png"
#define FILE_BUTTON_4_PLAYER   "image/go_image.png" //"image/play_4.png"

#define FILE_MUSIC_BG        "music/dreams.ogg"
#define FILE_MUSIC_BUTTON    "music/iphone_son_de_touche.ogg"
#define FILE_MUSIC_WIN       "music/violin-win.ogg"

#define SIZE_PLAYER          ((WINDOW_WIDTH)/10)
#define BUTTON_LOCATION_Y    (WINDOW_WIDTH + (WINDOW_HEIGHT-WINDOW_WIDTH)/4)
#define BUTTON_LOCATION_X    ((WINDOW_WIDTH) /4)

#define BUTTON_SIZE_H        ((WINDOW_HEIGHT-WINDOW_WIDTH)/2)
#define BUTTON_SIZE_W        (WINDOW_WIDTH/2)

#define BUTTON_MENU_PLAYER1_Y  (WINDOW_HEIGHT/5)-BUTTON_SIZE_H/2          // 120
#define BUTTON_MENU_PLAYER2_Y  (WINDOW_HEIGHT/5*2)-BUTTON_SIZE_H/2         // 240
#define BUTTON_MENU_PLAYER3_Y  (WINDOW_HEIGHT/5*3)-BUTTON_SIZE_H/2         // 360
#define BUTTON_MENU_PLAYER4_Y  (WINDOW_HEIGHT/5*4)-BUTTON_SIZE_H/2         // 480


#endif