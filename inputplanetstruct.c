#include <stdio.h>
#include <string.h>
#include <math.h>

#define NAME_LENGTH 20
#define PI 3.1415926536

struct planet{
    char navn[NAME_LENGTH + 1];
    double radius, masse;

};

typedef struct planet planet;

void print_planetinfo(planet planeten);
planet indtast_planet(void);

int main(void){
    planet p1 = indtast_planet();
   
    print_planetinfo(p1);

    return 0;
}

planet indtast_planet(void){
    char navnet[NAME_LENGTH + 1];
    double radius;
    double masse;

    printf("Indtast navn: ");
    scanf(" %s", navnet);
    printf("Indtast radius i km: ");
    scanf(" %lf", &radius);
    printf("Indtaste masse i kg: ");
    scanf(" %lf", &masse);

    planet p;
    strcpy(p.navn, navnet);
    p.radius = radius;
    p.masse = masse;

    return p;
}

void print_planetinfo(planet plnt){
    char navnet[NAME_LENGTH + 1];
    strcpy(navnet, plnt.navn);
    double radius = plnt.radius;
    double masse = plnt.masse;
    double volumen = (1.3333333) * PI * pow(radius, 3);
    double massefylde = masse / volumen;

    printf("\n%s:\n", navnet);
    printf("radius: %lf km\n", radius);
    printf("masse: %lf kg\n", masse);
    printf("volumen: %lf km3\n", volumen);
    printf("massefylde: %lf kg/km3\n", massefylde);
}
