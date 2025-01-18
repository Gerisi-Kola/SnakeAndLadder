//gcc -Wall -Wextra -I"D:_lib/include" .\src\Window_SDL.c -o ./bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
//gcc -Wall -Wextra .\src\*.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include "window_SDL.h"
#include "constant.h"
#include "event.h"
#include "player.h"


int image_refresher(int number_of_player,
                    int *turn,
                    int *roll_result,
                    int players_pos[],
                    SDL_Renderer *renderer,
                    SDL_Texture **texture,
                    SDL_Rect rect_button,
                    SDL_Rect rect_bg,
                    SDL_Rect player_rects[],
                    SDL_Texture *array_texture_player[],
                    SDL_Surface **picture,
                    const char *array_of_images_players[]){
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Créer et dessiner le bouton (rectangle jaune)
    button_create(renderer, &rect_button);
    
    // Charger et afficher l'image (si nécessaire)
    image_load(renderer, texture, picture, rect_bg);
    
    player_move(number_of_player,turn,roll_result,players_pos,player_rects);
    player_create_loop(number_of_player,renderer,player_rects,array_texture_player,picture,array_of_images_players);
    
    renderer_refresh(renderer);
    
    return 0;
}

int main(int argc, char *argv[]) {
    (void)argc; // Indique explicitement que tu n'utilises pas 'argc'
    (void)argv; // Indique explicitement que tu n'utilises pas 'argv'
    
    int stop = 0;
    int number_of_player = 1;
    int die_roll = 0;
    int roll_result = SEED_2;
    int turn = 0;
    int players_pos[4] = {1,1,1,1};
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_Surface *picture = NULL;
    SDL_Event events;
    SDL_Rect rect_button = {BUTTON_LOCATION_X,BUTTON_LOCATION_Y,BUTTON_SIZE_W,BUTTON_SIZE_H};  // Position et taille du rectangle
    SDL_Rect rect_bg = {0, 0, WINDOW_WIDTH, WINDOW_WIDTH};  // Dimensions de l'image
    //Player
    /*
    SDL_Rect rect_j1 = {5,10, 40, 40};
    SDL_Rect rect_j2 = {10,10, 40, 40};
    SDL_Rect rect_j3 = {15,10, 40, 40};
    SDL_Rect rect_j4 = {20,10, 40, 40};
    */
    SDL_Rect player_rects[4] = {
            {4, 10, 40, 40},  // Player 1
            {9, 10, 40, 40}, // Player 2
            {14, 10, 40, 40}, // Player 3
            {19, 10, 40, 40}  // Player 4
            };
    
    SDL_Texture* array_texture_player[4] = {NULL,NULL,NULL,NULL};
    /*texture_j1 = NULL;
    SDL_Texture *texture_j2 = NULL;
    SDL_Texture *texture_j3 = NULL;
    SDL_Texture *texture_j4 = NULL;
    */
    
    const char* array_of_images_players[5] = {
            FILE_PLAYER,
            FILE_PLAYER2,
            FILE_PLAYER3,
            FILE_PLAYER4,
            FILE_IA
            };
    
    // Créer la fenêtre et le renderer
    if (create_window(&window, &renderer) != 0) {
        return EXIT_FAILURE;
    }
    
    // Effacer l'écran (fond noir)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // Créer et dessiner le bouton (rectangle jaune)
    button_create(renderer, &rect_button);
    
    // Charger et afficher l'image (si nécessaire)
    image_load(renderer, &texture, &picture, rect_bg);
    
    player_create_loop(number_of_player,renderer,player_rects,array_texture_player,&picture,array_of_images_players);
    // Actualiser l'affichage pour que les dessins soient visibles
    renderer_refresh(renderer);
    
    // Attendre 5 secondes avant de fermer
    //SDL_Delay(5000);
    
    event_create();
    while (stop == 0){
        
        die_roll = button_check(&stop, &events);
        if (die_roll == 1){
            die_roll = image_refresher(
                            number_of_player,
                            &turn,
                            &roll_result,
                            players_pos,
                            renderer,
                            &texture,
                            rect_button,
                            rect_bg,
                            player_rects,
                            array_texture_player,
                            &picture,
                            array_of_images_players);
        }
        SDL_Delay(200);
    }
    
    // Nettoyage
    destroy_window(window, renderer, texture);
    
    return 0;
}


/*
int main (int argc, char *argv[]){
    (void)argc; // Indique explicitement que tu n'utilises pas 'argc'
    (void)argv; // Indique explicitement que tu n'utilises pas 'argv'
    
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *picture = NULL;
    SDL_Texture *texture = NULL;
    SDL_Rect rect_bg = {0,0,WINDOW_WIDTH,WINDOW_WIDTH};
    SDL_Rect rect_button = {100,500,200,200};//BUTTON_LOCATION_X,BUTTON_LOCATION_Y,BUTTON_SIZE_H,BUTTON_SIZE_W};
    
    create_window(&window,&renderer);
    //image_load(renderer,&texture,&picture,rect_bg);
    button_create(renderer,&rect_button);
    renderer_refresh(renderer);
    SDL_Delay(5000);
    destroy_window(window,renderer);
    return 0;
}

int roll_die();
int number_of_player_asker();
int area_creator(int area[]);
int player_move(int *player, int area[],int num_die, int number_of_player, int *turn);
int *turn_of_who(int *player,int *player2,int *player3,int *player4,int *turn,int turn_compteur,int number_of_player);

int main (int argc, char *argv[]){
    (void)argc; // Indique explicitement que tu n'utilises pas 'argc'
    (void)argv; // Indique explicitement que tu n'utilises pas 'argv'
    
    int player = 0, player2 = 0, player3 = 0, player4 = 0;
    int win = 0, die_num = 0;
    int turn = -1;
    int *who;
    int turn_compteur = 0;
    int area[100] = {0};
    int number_of_player = number_of_player_asker();
    
    srand((unsigned int)time(NULL));
    //srand(time(NULL)); // Initialiser le générateur de nombres aléatoires avec l'heure actuelle comme graine
    area_creator(area);
    create_window();
    while (win != 99){
        
        
        turn_compteur ++;
        who = turn_of_who(&player, &player2, &player3, &player4, &turn, turn_compteur, number_of_player);
        die_num = roll_die();
        win = player_move(who,area,die_num, number_of_player, &turn);
    }
    
    printf("\nLa partie a dure %d tours",turn_compteur);
    return 0;
}

int roll_die(){
    //Simule un lancer de de (1 à 6)
    int num = (rand() % 6) + 1;
    printf("\nLe de est tombe sur %d\n",num);
    return num;
}

int number_of_player_asker(){
    //Demande à l'utilisateur combien de joueur il y a
    int number_of_player = 1;
    do {
        printf("\nCombien de joueurs vous etes ?\n1\n2\n3\n4\t");
        scanf("%d",&number_of_player);
        
        if (number_of_player < 1 || number_of_player > 4)
            printf("Nombre invalide !");
        
    }while(number_of_player < 1 || number_of_player > 4);
    
    printf("Vous etes %d joueurs",number_of_player);
    return number_of_player;
}

int area_creator(int area[]){
    //Cree le terrin (les serpents et les echelles) 
    //debut = 0 et fin = 99
    
    // Ladders
    area[2] = 36;  //38
    area[4] = 10;  //14
    area[9] = 22;  //31
    area[21] = 21; //42
    area[28] = 53; //81
    area[51] = 16; //67
    area[74] = 17; //91
    area[77] = 10; //87
    area[80] = 15; //95
    area[85] = 5;  //90
    
    //Snakes
    area[17] = -10; //7
    area[35] = -15; //20
    area[54] = -20; //34
    area[62] = -43; //19
    area[64] = -4;  //60
    area[87] = -50; //37
    area[93] = -20; //73
    area[94] = -19; //75
    area[96] = -20; //76
    area[98] = -5;  //93
    
    return 0;
}

int player_move(int *player, int area[],int num_die,int number_of_player, int *turn){
    //On ajoute à chaque affichage +1 pour que le debut soit 1 et la fin 100
    
    int origin = *player; //on sauvegarde la position de debut
    *player += num_die;  //le joueur avance
    
    //On verifi si le joueur à gagné
    if (*player > 99){
        *player = 99;
        if(number_of_player == 1 && *turn == 1){
            printf("\nL'IA monte de la case %d a la case %d\n",origin+1,*player+1);
            printf("Oh zut ! L'IA a gagne ! Dommage pour vous");
        }
        else{
            printf("\nVous montez de la case %d a la case %d\n",origin+1,*player+1);
            printf("Bravo ! Vous gagez la pertie !!");
        }
        return 99; //Confirmation de fin de partie
    }
    
    if (number_of_player == 1 && *turn == 1){
            printf("\nL'IA monte de la case %d a la case %d\n",origin+1,*player+1);
        }
        else{
            printf("\nVous montez de la case %d a la case %d\n",origin+1,*player+1);
        }
    
    //On regard si le joueur est tomber sur une echelle ou un serpent
    int index = *player;
    *player += area[*player];
    if (area[index] < 0){
        if (number_of_player == 1 && *turn == 1)
            printf("\nOh zut, un serpent a fait tomber l'IA !\nL'IA tombe a la case %d\n",*player+1);
        else
            printf("\nOh zut, un serpent vous a fait tomber !\nVous etes tombe a la case %d\n",*player+1);
    }
    else if (area[index] > 0){
        if (number_of_player == 1 && *turn == 1)
            printf("\nOh quelle chance ! L'IA a trouve une echelle !\nL'IA monte a la case %d\n",*player+1);
            
        else
            printf("\nOh quelle chance ! Vous avez trouve une echelle !\nVous montez a la case %d\n",*player+1);
    }
    
    return 0;
}

int *turn_of_who(int *player,int *player2,int *player3,int *player4,int *turn,int turn_compteur,int number_of_player){
    // Calcul a qui est le tour
    // Si le joueur est seul il joue contre l'ordi
    if (number_of_player == 1)
        *turn = turn_compteur % 2;
    else
        *turn = turn_compteur % number_of_player;
    
    if (*turn == 0){
        printf("\nC'est le tour du Joueur 1\n");
        return player;
    }
    else if (*turn == 1){
        if (number_of_player == 1)
            printf("\nC'est le tour de l'IA\n");
        else
            printf("\nC'est le tour du joueur 2\n");
        return player2;
    }
    else if (*turn == 2){
        printf("\nC'est le tour du joueur 3\n");
        return player3;
    }
    else if (*turn == 3){
        printf("\nC'est le tour du joueur 4\n");
        return player4;
    }
    
    return 0;
}
*/