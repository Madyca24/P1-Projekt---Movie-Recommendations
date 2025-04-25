#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *flertal(char s[]);

int main(void){
    char strengen[30];

    printf("Hvilken string vil du indtaste\n");
    scanf("%29s",strengen);
    char *strengen2 = flertal(strengen);
    printf("%s\n", strengen2);
    
    free(strengen2);

    return 0;
}

char *flertal(char s[]){
    int i = 0;
    char *s2 = (char*)

    malloc(sizeof(char)*(strlen(s)+5));

    if (s2 == NULL) {
        printf("Ikk nok lager");
        exit(EXIT_FAILURE);
    }
    while(s[i]!= '\0'){
        s2[i]=s[i];
        i++;
    }
    if(s[i-1] == 'y'){
        s2[i-1] = 'i';
        s2[i] ='e';
        s2[i+1]='s';
        s2[i+2]='\0';
    } 
    else if(s[i-1] == 's' || s[i-1] == 'h'){
        s2[i] = 'e';
        s2[i+1] ='s';
        s2[i+2]='\0';
    } 
    else{
        s2[i] ='s';
        s2[i+1]='\0';
    }
  
    return s2;
}


