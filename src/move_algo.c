#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include "constant.h"

int roll_die_number(int *previous_result){
    // Initialiser le générateur de nombres aléatoires avec l'heure actuelle
    srand(time(NULL));
    // Générer un nombre aléatoire entre 0 et 5 compris (valeur maximale retournée par rand())
    int num = rand();
    
    num = ((int)(num + *previous_result * SEED)) %6;
    // num ++ permet d'avoir des valeur qui vont de 1 à 6 au lieu d’être de 0 à 5
    num ++ ;
    
    if (num < 0 || num > 6){
        printf("Attention !! Le resultat n'est pas compris entre 0 et 6 : result = %d\n\n",num);
        return roll_die_number(previous_result+1);
    }
    else if(num == *previous_result){
        printf("\n%d Repetition !!! %d",*previous_result,num);
        if (num < 6)
        num ++;
        else
        num --;
        
        printf("\nNouveau num %d",num);
    }
    
    return num;
}


int calcul_new_pos(int actual_player, int players_pos[], SDL_Rect player_rects[], int roll_num, int *win){
    int pos = players_pos[actual_player] + roll_num;
    if (pos >= MAX_CASE){
        pos = MAX_CASE;
        *win = actual_player + 1;
    }
    players_pos[actual_player] = pos;
    
    int unite = pos%10;
    int dizaine = pos/10;
    
    int pos_y = POS_Y - (pos/10 * 60);
    
    
    int pos_x;
    
    if(dizaine %2 == 0){
        pos_x = ((unite-1) * 60) + 60 + POS_X *(actual_player+1);
    }
    else{
        pos_x = POS_X_MAX - (((unite) * 60) + 40 + POS_X *(actual_player+1));
    }
    
    
    player_rects[actual_player].x = pos_x;
    player_rects[actual_player].y = pos_y;
    
    
    return 0;
}