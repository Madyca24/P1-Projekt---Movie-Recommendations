#include <stdio.h>
#include <stdlib.h>

int main(){
     double a, b;

     printf("Write an (a) value: ");
     scanf("%lf", &a);

     printf("Write an (b) value: ");
     scanf("%lf", &b);

     if (a < b)
     {
          printf("a: %lf is less then b: %dlf", a, b);
     }
     else if(a == b)
     {
          printf("a: %lf is equal to b: %lf", a,b);
     }else
     {
          printf("a: %lf is bigger then b: %lf", a,b);
     }
     
     

     return 0;
}