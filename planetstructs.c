#include <stdio.h>
#include <string.h>
#include <math.h>

#define NAME_LENGTH 20

struct planet{
    char navn[NAME_LENGTH + 1];
    double volumen, masse;

};

typedef struct planet planet;

void print_planetinfo(planet planeten);

int main(void){
    planet p1 = {"Jorden", 1.08 * pow(10, 12), 5.97223 * pow(10, 24)};
    planet p2 = {"Mars", 1.63 * pow(10,11), 6.4185 * pow(10, 23)};

    print_planetinfo(p1);
    print_planetinfo(p2);

    return 0;
}

void print_planetinfo(planet plnt){
    char navnet[NAME_LENGTH + 1];
    strcpy(navnet, plnt.navn);
    double volumen = plnt.volumen;
    double masse = plnt.masse;
    double massefylde = masse / volumen;

    printf("\n%s:\n", navnet);
    printf("volumen: %lf km3\n", volumen);
    printf("masse: %lf kg\n", masse);
    printf("massefylde: %lf km3/kg\n", massefylde);
}
