#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_die();
int number_of_player_asker();
int area_creator(int area[]);
int player_move(int *player, int area[],int num_die);

int main (){
    // Initialiser le générateur de nombres aléatoires avec l'heure actuelle comme graine
    srand(time(NULL));
    
    //int number_of_player = number_of_player_asker();
    
    int area[100] = {0};
    area_creator(area);
    
    int player = 89;
    
    int die_num = 17;// roll_die();
    player_move(&player,area,die_num);
    return 0;
}


int roll_die(){
    int num = (rand() % 6) + 1;
    printf("\nDie is %d\n",num);
    return num;
}

int number_of_player_asker(){
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
    
    /*
    for (int i=0;i<100;i++)
        printf("\n%d",area[i]);
    */
    
    return 0;
}

int player_move(int *player, int area[],int num_die){
    //On ajoute à chaque affichage +1 pour que le debut soit 1 et la fin 100
    
    int origin = *player; //on sauvegarde la position de debut
    *player += num_die;  //le joueur avance
    
    //On verifi si le joueur à gagné
    if (*player > 99){
        *player = 99;
        printf("\nVous montez de la case %d a la case %d\n",origin+1,*player+1);
        printf("Bravo ! Vous gagez la pertie !!");
        return 99; //Confirmation de fin de partie
    }
    
    printf("\nVous montez de la case %d a la case %d\n",origin+1,*player+1);
    //On regard si le joueur est tomber sur une echelle ou un serpent
    int index = *player;
    *player += area[*player];
    if (area[index] < 0){
    printf("\nOh zut, un serpent vous a fait tomber !\nVous etes tombe a la case %d\n",*player+1);
    }
    else if (area[index] > 0){
    printf("\nOh quelle chance ! Vous avez trouve une echelle !\nVous montez a la case %d\n",*player+1);
    }
    
    return 0;
}