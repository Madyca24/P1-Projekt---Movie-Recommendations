#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strrev(char *s);

int main(void){
  char strengen[] = "Church";

  printf("%s\n", strengen);
  strrev(strengen);
  printf("%s\n", strengen);
  // printf("%s\n", strengen2);
  
 

  return 0;
}
// Dette er hvis der er to variabler


// char *flertal(char s[]) {
//     char *s2 = (char*) malloc(sizeof(char)*(strlen(s)+5));
//     if (s2 == NULL) {
//         printf("Ikk nok lager");
//         exit(EXIT_FAILURE);
//   }
//   int i = 0;
//   while(s[i]!= '\0'){
//    s2[i]=s[i];
//     i++;
//   }
//     int j = 0;
//     i--;
//     while (s[j]!= '\0'){
//         s2[j]=s[i];
//         j++;
//         i--;
//     }
//     s2[j]='\0';
// }


void strrev(char *s) {
    int i = 0;
    int j = strlen(s)-1;
    char temp;
    while (i < j){
      char temp = s[i];
        s[i]= s[j];
        s[j] = temp;
        j--;
        i++;
   }

}
    