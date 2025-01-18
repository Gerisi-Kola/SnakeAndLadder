#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
//#include <SDL_image.h>
#include "../header/constant.h"

int roll_die_number(const int *previous_result){
    // Initialiser le générateur de nombres aléatoires avec l'heure actuelle
    // printf("\n%d previous\n",*previous_result);
    srand(time(NULL));
    // Générer un nombre aléatoire entre 0 et 5 compris (valeur maximale retournée par rand())
    int num = rand();
    
    //int turn = turn *69/5;
    
    // Seed minecraft de pack.png !!
    //signed long long int seed = SEED;
    
    long long int a = (*previous_result * SEED);
    //long long int num = 0;
    num = ((int)(num + a)) %6;
    num ++ ;
    
    //printf("   %d  %d",num,*previous_result);
    
    //printf("\nnum = %d\nprevious_result = %d\nseed = %d\n previous*seed = %lld\n a = %lld\n",num,*previous_result,SEED,*previous_result*SEED,a);
    if (num < 0 || num > 6){
        //printf("\nnum = %d\nprevious_result = %d\nseed = %d\n previous*seed = %lld\n a = %lld\n",num,*previous_result,SEED,*previous_result*SEED,a);
        printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHHHHHHHHHHH!!!!!!!!!!!!!!!!!\n\n");
        return roll_die_number(previous_result+1);
        //return *previous_result;
    }
    else if(num == *previous_result){
        printf("\n%d Repetition !!! %d",*previous_result,num);
        if (num < 6)
        num ++;
        else
        num --;
        
        printf("\nNouveau num %d",num);
        /*
        a = rand();
        if (((a*SEED)-num) % 2 == 0){
            printf("repetition");
            return (roll_die_number(previous_result)*3) %6;
            ///return *previous_result;
        }
        else{
            printf("\npass\n");
        }
        */
    }
    
    // num + 1 permet d'avoir des valeur qui vont de 1 à 6 au lieu d’être de 0 à 5
    return num;
}


int calcul_new_pos(int i, int players_pos[], SDL_Rect player_rects[], int roll_num){
    //(void)roll_num ;
    printf("\n%d",roll_num);
    for (int j = 0; j <roll_num; j ++){
        if(players_pos[i]%10 != 0){
            if ((players_pos[i]/10)%2 == 0){ //if (players_pos[i] < 10 || 29 < players_pos[i] < 30 || 49 < players_pos[i] < 60 || 79 players_pos[i])
            player_rects[i].x += WINDOW_WIDTH/10;
            }
            else{
                player_rects[i].x -= WINDOW_WIDTH/10;
            }
        }
        else{
            player_rects[i].y += WINDOW_WIDTH/10;
        }
        
        players_pos[i] += 1;
    }
    return 0;
}

/*
int main(){
    int num;
    int array[6] = {0};
    for (int i = 0; i < 100; i++){
        num = roll_die_number(i);
        array[num-1] += 1;
        printf("\n%d",num);
    }
    printf("\n\n\n");
    for (int i = 0; i<6;i++){
        printf("\n%d = %d",i+1,array[i]);
    }
}
*/