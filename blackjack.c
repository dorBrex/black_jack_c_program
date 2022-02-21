#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define HOLY_SCORE 42

bool keepPlaying(){
    int keepPLaying = 1;
    printf("Would you like to continue playing?\nyes:1 no:0\n");
    scanf("%d", &keepPLaying);
    if (keepPLaying == 1){
        return true;
    }
    else{
        return false;
    }
}

void printPlayerScore(int score){
    printf("Your last score is %d\n",score);
}

int addRandomScore(){
    return (rand()%10) +1;
}

void main(){
    int p1Score = 0, p2Score = 0, p1Playing = 1, p2Playing = 1, p1TurnsPlayed = 0, p2TurnsPlayed = 0, turn = 0;
    srand(time(NULL));

    while (p1Playing == 1 || p2Playing == 1){
        if (p1Playing == 1 && turn % 2 == 0){
            printf("\nPlayer 1\n");
            printPlayerScore(p1Score);
            if (keepPlaying() == true){
                p1Score += addRandomScore();
                ++p1TurnsPlayed;
            }
            else{
               p1Playing=0; 
            }
        }
        if(p2Playing == 1 && turn % 2 == 1){
            printf("\nPlayer 2\n");
            printPlayerScore(p2Score);
            if (keepPlaying() == true){
                p2Score += addRandomScore();
                ++p2TurnsPlayed;
                
            }
            else{
               p2Playing=0; 
            }
        }
        ++turn;
    }

    int p1distance = abs(HOLY_SCORE - p1Score);
    int p2distance = abs(HOLY_SCORE - p2Score);
    if (p1distance == p2distance){
        printf("It's a tie!\n");
        if (p1TurnsPlayed == p2TurnsPlayed) {
            printf("It's a tie by the number of turns");
        }
        else if (p1TurnsPlayed > p2TurnsPlayed){
            printf("Player 2 won by the number of turns");
        }
        else{
            printf("Player 1 won by the number of turns");
        }

    }
    else if(p1distance > p2distance){
        printf("Player 2 is closer to %d with %d steps\n",HOLY_SCORE, p2distance);
    }
    else{
        printf("player 1 is closer to %d with %d steps\n",HOLY_SCORE, p1distance);
    }
    printf("\nEND OF GAME\n");

}



