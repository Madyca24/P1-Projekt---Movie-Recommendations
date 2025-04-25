#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>

void roll_multiple_dice(int n);

int main(void){
    int n;
    srand(time(NULL)); 

    printf("indtast antal kast: ");
    scanf(" %d", &n);

    roll_multiple_dice(n);

    return 0;  
}

void roll_multiple_dice(int n){
    int i = 1, arr[n];

    for(i = 1; i <= n; i++){
        arr[i] = (rand() % 6) + 1 ;
        printf("roll %d: %d\n", i, arr[i]);
    }

    free(arr);
}