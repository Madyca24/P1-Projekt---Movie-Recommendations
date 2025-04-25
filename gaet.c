#include <stdio.h>

#define RIGTIGT_TAL 7

int main(void){
  int gaet, antal_gaet = 0;

  do{
    printf("Tast et tal mellem 1 og 20:\n");
    scanf("%d", &gaet);
    while (gaet < 1 || gaet > 20){
        printf("gaettet var ikke mellem 1 og 20.\n");
        printf("Tast et tal mellem 1 og 20:\n");
        scanf("%d", &gaet);
    }
    

    antal_gaet++;

    if (gaet == RIGTIGT_TAL){
      printf("Du har gaettet rigtigt.\n");
    } else {
      printf("Du har gaettet forkert.\n");
    }
  } while (gaet != RIGTIGT_TAL);

  printf("Du gaettede %d gange.\n", antal_gaet);

  return 0;
}
