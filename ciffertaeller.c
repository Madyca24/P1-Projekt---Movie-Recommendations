#include <stdio.h>
#include <math.h>

int main(void){
    int n, c, x;

    printf("Indtast et heltal over 0 og et ciffer mellem 0 og 9:\n");
    scanf(" %d %d", &n, &c);

    while (n < 1 || c < 0 || c > 9){
        printf("input er ugyldigt, tast nye tal:");
        scanf(" %d %d", &n, &c);
        }
    x = (2*n) % (2*c);
    printf("%d", x);

    return 0;
}