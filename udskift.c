#include <stdio.h>
#include <math.h>

void udskift(char s[], char c1, char c2);

int main(void){
    char streng[] = "foodback", c1, c2;

    printf("ordvalg: %s\n", streng);

    printf("indtast bogstav der skal udskiftes: ");
    scanf(" %c", &c1);
    printf("indtast bogstav der skal indsaettes: ");
    scanf(" %c", &c2);
    
    udskift(streng, c1, c2);

    printf("slut ord: %s\n", streng);

    return 0;
}

void udskift(char s[], char c1, char c2){
     int i = 0;
     while(s[i] != '\0'){
        if (s[i] == c1){
            s[i] = c2;
        }
        i++;
     }

}