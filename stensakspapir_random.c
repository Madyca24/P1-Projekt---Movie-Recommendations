#include <stdio.h>
#include <stdlib.h>
#include <time.h>


enum hand {rock, paper, scissor};
typedef enum hand hand;

hand char_to_hand(char c);
void print_hand(hand h);
hand random_hand(void);

int main(void){
  char spiller1_input;
  hand spiller1, spiller2;

  srand(time(NULL));
 
  //Tag imod input fra spillerne
  printf("Spiller 1 indtast din haand (r/p/s): \n");
  scanf(" %c", &spiller1_input);

  //Konverter charsne til hands
  spiller1 = char_to_hand(spiller1_input);
  spiller2 = random_hand();

  //Udskriv hænderne
  printf("Spiller 1's haand: ");
  print_hand(spiller1);
  printf("\nSpiller 2's haand: ");
  print_hand(spiller2);
  printf("\n");


  //Regn ud om spiller 1 har vundet
  int spiller1_vandt = (spiller1 == scissor && spiller2 == paper) ||
                       (spiller1 == paper && spiller2 == rock) ||
                       (spiller1 == rock && spiller2 == scissor);

  int uafgjort = (spiller1 == spiller2);

  //Skriv på skærmen hvem der vandt eller om det blev uafgjort
  if(spiller1_vandt){
    printf("Spiller 1 vandt.\n");
  } else if(uafgjort){
    printf("Det blev uafgjort.\n");
  } else {
    printf("Spiller 2 vandt.\n");
  }

  return 0;
}

hand random_hand(void){
  //Lav et tilfældigt tal.
  int t = rand() % 3;
  printf("Her er et tilfaeldigt tal: %d\n", t);

  //Konverter tallet til en hånd.
  hand h = (hand) t;

  return h;
}

void print_hand(hand h){
  switch (h) {
    case rock:
      printf("sten");
      break;
    case paper:
      printf("papir");
      break;
    case scissor:
      printf("saks");
      break;
    default:
      printf("Der gik noget galt!\n");
      exit(EXIT_FAILURE);      
  }
}

hand char_to_hand(char c){
  hand h;
  switch (c) {
    case 'r':
      h = rock;
      break;
    case 'p':
      h = paper;
      break;
    case 's':
      h = scissor;
      break;
    default:
      printf("Du har tastet galt!\n");
      exit(EXIT_FAILURE);
  }
  return h;
}


