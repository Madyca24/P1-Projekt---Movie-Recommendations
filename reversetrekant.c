#include <stdio.h>

int main(void){
  int n, j, i, s;  
  //Indlaes brugerinput
  printf("Indtast hoejde: \n");
  scanf(" %d", &n);

  //Tegn rektanglet

  //Gentag foelgende n gange:
    //Tegn en linje der er m bred
  for(i = 0; i < n; i++){
    printf("%d", i);
    for (s=n;s>i;s--){
    printf(" ");
    }
    for(j = 0; j < i; j++){
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
