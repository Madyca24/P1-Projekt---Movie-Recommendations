#include <stdio.h>  

int main(void)   
{
    float n1, n2, n3;

    printf("Give me three:");
    scanf("%f %f %f", &n1, &n2, &n3); 
    printf("Theresult: %f\n", (n1 + n2 + n3) / 3.0);
    return 0;
}