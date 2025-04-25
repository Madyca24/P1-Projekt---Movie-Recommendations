#include <stdio.h>
#include <math.h>

int main(void){
    double r, x, y, l;

    printf("indtast radius og punktet(r x,y):\n");
    scanf(" %lf %lf,%lf", &r, &x, &y);

    l = sqrt(x*x + y*y);
    if(l < r){
    printf("punktet er indenfor cirklen\n");
    }
    else if(l > r){
    printf("punktet er udenfor cirklen\n");
    }
    else if (l == r){
    printf("punktet er på cirklen");
    }
    return 0;
}
