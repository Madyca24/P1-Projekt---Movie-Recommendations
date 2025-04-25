#include <stdio.h>
#include <math.h>
int sum_iter(int n);
int sum_formula(int n);

int main(void){
    int n;
    printf("Beregning af summen af heltal fra 1 til n. Indtast n:\n");
    scanf("%d", &n);
    
    printf("summen af heltal fra 1 til n: %d\n", sum_iter(n));

    printf("sumformula resultat: %d\n", sum_formula(n));

    return 0;
}

int sum_iter(int n){
    int sum = 0, loops = 1;
    while (loops <= n){
      sum = sum + loops;
      loops++;
    }
    return sum; 
}

int sum_formula(int n){
  int sum = (n + 1)*n/2;
  return sum;
}