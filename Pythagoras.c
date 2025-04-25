#include <stdio.h>
#include <math.h>

int main(void)
{
    float A, B, squareRoot;
    printf("This program calculates the length of C in a triangle.\n\n");
    printf("Input the Lengths of A and B: ");
    scanf("%1f %2f", &A, &B);

    squareRoot = sqrtf(A * A + B * B);

    printf("\n  The length of C = %3f", squareRoot);
    printf("\n");

    return 0;
}