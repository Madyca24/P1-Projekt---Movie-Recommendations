#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct{
 unsigned int taeller;
 unsigned int naevner;
}broek;

unsigned int gcd(unsigned int taeller, unsigned int naevner);
void print_broek(broek b1);
broek forkort_broek(broek b1);
broek gange_to_broeker(broek b1);
broek gange_broek_med_heltal(broek b1);
broek inizialisering (void);

int main(void){
    broek b1 = inizialisering();
    printf("Dette er den valgte broek:\n");
    print_broek(b1);

    broek forkortet = forkort_broek(b1);
    printf("Dette er broeken forkortet saa meget som muligt:\n");
    print_broek(forkortet);

    broek ganget_broekere = gange_to_broeker(b1);
    printf("Dette er de to broekere ganget sammen:\n");
    print_broek(ganget_broekere);

    printf("Dette er et heltal ganget med broekken:\n");
    broek heltal_gang = gange_broek_med_heltal(b1);
    print_broek(heltal_gang);

    return 0;
}
broek inizialisering (void){
    unsigned int taeller, naevner;

    printf("Giv mig taelleren: ");
    scanf(" %d",&taeller);
    printf("Giv mig naevneren: ");
    scanf(" %d", &naevner);

    broek b1 = {taeller, naevner};

    return b1;
}
void print_broek(broek b1){
    printf(" %u\n", b1.taeller);
    printf(" --\n");
    printf(" %u\n\n", b1.naevner);
}
    
unsigned int gcd(unsigned int taeller, unsigned int naevner){
     unsigned int remainder;

     while (naevner > 0){
       remainder = taeller % naevner;
       taeller = naevner;
       naevner = remainder;
     }
     return taeller;
}

broek forkort_broek(broek b1){
    broek b2;{
    b2.taeller =b1.taeller / gcd(b1.taeller, b1.naevner);
    b2.naevner =b1.naevner / gcd(b1.taeller, b1.naevner);
    }
     return b2;
}

broek gange_to_broeker(broek b1){
    unsigned int taeller, naevner;

    printf("Giv mig taelleren til den anden broek:\n ");
    scanf(" %d", &taeller);
    printf("Giv mig naevneren til den anden broek:\n ");
    scanf(" %d", &naevner);

    taeller = (b1.taeller * taeller);
    naevner = (b1.naevner * naevner);
    
    broek b2;{
        b2.taeller = taeller / gcd(taeller,naevner);
        b2.naevner = naevner / gcd(taeller,naevner);
    }
    return b2;
}

broek gange_broek_med_heltal(broek b1){
    int heltal, taeller, naevner;

    printf("Indtast et heltal\n");
    scanf(" %d", &heltal);

    taeller = b1.taeller * heltal;
    naevner = b1.naevner;

    broek b2;{
        b2.taeller = taeller / gcd(taeller, naevner);
        b2.naevner = naevner / gcd(taeller,naevner);   
    }
    
    return b2;
}