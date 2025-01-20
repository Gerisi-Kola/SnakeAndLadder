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


int calcul_new_pos(int i, int players_pos[], SDL_Rect player_rects[], int roll_num){
    // On s'assure de ne pas dépasser 100 (la fin du jeu)
    if(roll_num > 0){
        if(roll_num + players_pos[i] > MAX_CASE){
            roll_num = MAX_CASE - players_pos[i];
        }
        // On calcul la position finale en se déplacent case par case
        for (int j = 0; j <roll_num; j ++){
            if(players_pos[i]%10 != 0){
                if ((players_pos[i]/10)%2 == 0){
                player_rects[i].x += WINDOW_WIDTH/10;
                }
                else{
                    player_rects[i].x -= WINDOW_WIDTH/10;
                }
            }
            else{
                player_rects[i].y -= WINDOW_WIDTH/10;
            }
            players_pos[i] += 1;
        }
    }
    
    else if(roll_num < 0){
        printf("\nSnake = %d",roll_num);
        // On calcul la position finale en se déplacent case par case
        for (int j = roll_num; j < 0; j ++){
            printf("\nPosition --");
            if(players_pos[i]%10 != 0){
                if ((players_pos[i]/10)%2 == 0){
                player_rects[i].x -= WINDOW_WIDTH/10;
                }
                else{
                    player_rects[i].x += WINDOW_WIDTH/10;
                }
            }
            else{
                player_rects[i].y += WINDOW_WIDTH/10;
            }
            players_pos[i] -= 1;
        }
        printf("\nposition = %d",players_pos[i]);
    }
    return 0;
}