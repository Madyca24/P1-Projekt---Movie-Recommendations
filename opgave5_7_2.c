#include <stdio.h>
#include <math.h>
int population_projection(double startbefolkning, double vaekstprocent, double oevregraense);


int main(void){
double stbefolk, vaekst, graense;

printf("indtast start-befolkningstallet, vaekstprocent pr aar og den eovre graense af befolkningstallet:\n");
scanf(" %lf %lf %lf", &stbefolk, &vaekst, &graense);

printf("Det tager %d aar for befolkningstallet at naa den eovre graense.\n", population_projection(stbefolk, vaekst, graense));

return 0;
}

int population_projection(double startbefolkning, double vaekstprocent, double oevregraense){
    int aar = 0;

    for (aar = 0; startbefolkning < oevregraense; aar++){
        startbefolkning *= (1+vaekstprocent/100);
    }

    return aar;
}