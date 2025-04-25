#include <stdio.h>

int main(void){
    int guess, answer = 5;

    do{
        printf("guess a number between 1 - 20\n");
        scanf(" %d", &guess);
        printf("you guessed wrong!\n\n");
    }
    while (guess != answer);

    printf("you guessed right!");

    return 0;
}   