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


int calcul_new_pos(int actual_player, int players_pos[], SDL_Rect player_rects[], int roll_num){
    int pos = players_pos[actual_player] + roll_num;
    if (pos >= MAX_CASE-1){
        pos = MAX_CASE-1;
    }
    players_pos[actual_player] = pos;
    
    int unite = pos%10;
    int dizaine = pos/10;
    
    //printf("\nunite = %d et pos = %d",unite, players_pos[i]);
    //printf("\nRoll_Num %d",roll_num);
    
    //printf("\n roll = %d",roll_num);
    int pos_y = POS_Y - (pos/10 * 60); //550 - (pos/10 * 50);
    
    
    int pos_x;
    
    if(dizaine %2 == 0){
        pos_x = ((unite-1) * 60) + 60 + POS_X *(actual_player+1);
        //printf("\nif if if if if");
    }
    else{
        pos_x = POS_X_MAX - (((unite) * 60) + 40 + POS_X *(actual_player+1));
        //printf("\nelse else");
    }
    
    
    player_rects[actual_player].x = pos_x;
    player_rects[actual_player].y = pos_y;
    
    //printf("\npos_y = %d",pos_y);
    //printf("\npos_x = %d",pos_x);
    
    return 0;
}