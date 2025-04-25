#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 20

struct bilkort {
    char navn[NAME_LENGTH + 1];
    int fart, hestekrafter, nul_tilhundrede, ccm;
};

typedef struct bilkort bilkort;


bilkort hurtigste_bil(bilkort b1, bilkort b2);
void print_kort(bilkort bil);


int main(void){
    bilkort b1 = {"Lotus", 200, 110, 8, 1973};
    bilkort b2 = {"Mercedes", 215, 160, 9, 1973};

    print_kort(b1);
    print_kort(b2);

    bilkort h = hurtigste_bil(b1,b2);

    print_kort(h);

    return 0;
}

bilkort hurtigste_bil(bilkort b1, bilkort b2){
    if(b1.fart > b2.fart){
        return b1;
    } else {
        return b2;
    }
}

void print_kort(bilkort bil){
    char navnet[NAME_LENGTH + 1];
    strcpy(navnet, bil.navn);
    int farten = bil.fart;
    int hestekrafterne = bil.hestekrafter;
    int nul_til_100 = bil.nul_tilhundrede;
    int cubikcm = bil.ccm;

    printf("%s:\n", navnet);
    printf("km/t: %d\n", farten);
    printf("HK: %d\n", hestekrafterne);
    printf("0-100 km/t: %d\n", nul_til_100);
    printf("ccm: %d\n\n", cubikcm);
}

