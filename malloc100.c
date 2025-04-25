#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <time.h>

int main(void){

    int n = 100, arr[n], i = 0;
    srand(time(NULL));

    for(i = 0; i < n; i++){
        arr[i] += rand();
        printf("%d ", &arr[i]);
    }
    
    return 0;
}


