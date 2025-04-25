#include <stdio.h>
#include <ctype.h>
#include <math.h>

// skulle have brugt islower i stedet for at checke mod en streng af små bogstaver


void taelbogstaver(char bogstaver[]);

int main(void){
    char inputstreng[] = "QWqweaAQWdLAdksseflkdQWDdfAWDlkjds";

    taelbogstaver(inputstreng);

    return 0;
}

void taelbogstaver(char bogstaver[]){
    int i = 0, n = 0, antalsmaabogstaver = 0;
    char smaa[] = "abcdefghijklmnopqrstuvxyz";

    while(bogstaver[i] != '\0'){    
        n = 0;
        while(smaa[n] != '\0'){
            if (bogstaver[i] == smaa[n]){
                antalsmaabogstaver++;
            }
            n++;
        } 
        i++;    
    }
    printf("antal smaa bogstaver: %d\n", antalsmaabogstaver);
}