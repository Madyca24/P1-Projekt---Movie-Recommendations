#include <stdio.h>
#include <math.h>
double regnomkreds(double radius);
double regnareal(double radius);
double PI = 3.1415926;

int main(void){
    double r;
    char input;

    printf("Tast o for omkreds eller a for areal:\n");
    scanf(" %c", &input);

    printf("tast radius:\n");
    scanf(" %lf", &r);

    if (input = "o" || "O"){
        printf("Omkreds = %f\n", regnomkreds(r));

    }
    else if (input = "a" || "A"){
        printf("Areal = %f\n", regnareal(r));
    }
    return 0;
}

double regnomkreds(double radius){
    double omkreds = 2 * PI * radius;
    return omkreds;
}

double regnareal(double radius){
    double areal = PI * radius * radius;
    return areal;
}

