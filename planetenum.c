#include <stdio.h>
#include <math.h>

enum planet {merkur, venus, jorden, mars, jupiter, saturn, uranus, neptun};
typedef enum planet planeter;

planeter char_to_p(char c);
void print_planet(planeter p); 

int main(void){
char planetvalg;
planeter planet;

printf("indtast planet:\n");
scanf(" %c", &planetvalg);

planet = char_to_p(planetvalg);


}