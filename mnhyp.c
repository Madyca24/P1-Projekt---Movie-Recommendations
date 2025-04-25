#include <stdio.h>
#include <math.h>

int main(void) {

    int m, n;

    printf("indtast punkt 1:\n");
    scanf(" %d %d", &m, &n);

    double side1, side2, hypotenuse;

    side1 = m*m - n*n;
    side2 = 2*m*n;
    hypotenuse = m*m + n*n;

    printf("side 1: %lf\nside 2: %lf\nhypotenuse: %lf\n", side1, side2, hypotenuse);

    return 0; 
}