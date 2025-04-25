#include <stdio.h>

int main(void){
  char spiller1_haand, spiller2_haand;
 
  //Tag imod input fra spillerne
  printf("Spiller 1 indtast din haand (r/p/s): \n");
  scanf(" %c", &spiller1_haand);

  printf("Spiller 2 indtast din haand (r/p/s): \n");
  scanf(" %c", &spiller2_haand);

 int gyldigt = (spiller1_haand == 'r' || spiller1_haand == 'p' || spiller1_haand == 's' && spiller2_haand == 'r' || spiller2_haand == 'p' || spiller2_haand == 's');
               
  if(gyldigt){
  //Regn ud om spiller 1 har vundet
  int spiller1_vandt = (spiller1_haand == 's' && spiller2_haand == 'p') ||
                       (spiller1_haand == 'p' && spiller2_haand == 'r') ||
                       (spiller1_haand == 'r' && spiller2_haand == 's');

  int uafgjort = (spiller1_haand == spiller2_haand);

  //Skriv på skærmen hvem der vandt eller om det blev uafgjort
  if (spiller1_vandt){
    printf("Spiller 1 vandt.\n");
  } else if (uafgjort){
    printf("Det blev uafgjort.\n");
  } else {
    printf("Spiller 2 vandt.\n");
  }
 
  //Hvis spiller 1 vandt
     // så skriver vi det ud
  //Hvis spiller 2 vandt
     // så skriver vi det ud
  //Hvis det blev uafgjort
     // så skriver vi det ud

  return 0;
  }
  else {
    printf("input er ugyldigt.\n");
    return 0;
  }
}
