#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARR_LENGTH 3

struct bilkort {
  char navn[30];
  int top_fart;
  int hk;
  int acceleration;
  int ccm;
};

typedef struct bilkort bilkort;

void udskriv_kort(bilkort bil);

bilkort indlaes_bilkort(void);

void gem_kort_i_fil(FILE *fil, bilkort bil);

void gem_flere_kort_i_fil(FILE *fil, bilkort biler[], int length);

bilkort laes_kort_fra_fil(FILE *file);

void laes_flere_kort_fra_fil(FILE *file, bilkort biler[], int length);

int main(void){
  bilkort b1 = {"Aston Martin", 215, 160, 9, 4520};
  bilkort b2 = {"Mercedes", 215, 160, 9, 4520};
  bilkort b3 = {"Lotus", 200, 110, 8, 1973};
  bilkort ba[ARR_LENGTH] = {b1, b2, b3};

  FILE *f1 = fopen("biler.txt", "w");
  if (f1 == NULL){
    printf("Filen kunne ikke aabnes!\n");
    exit(EXIT_FAILURE);
  }

  gem_flere_kort_i_fil(f1, ba, ARR_LENGTH);

  fclose(f1);

  FILE *f2 = fopen("biler.txt", "r");
  if (f2 == NULL){
    printf("Filen kunne ikke aabnes!\n");
    exit(EXIT_FAILURE);
  }

  bilkort biler[ARR_LENGTH];

  laes_flere_kort_fra_fil(f2,biler,ARR_LENGTH);

  fclose(f2);

  for(int i = 0; i < ARR_LENGTH; i++){
    udskriv_kort(biler[i]);
  }

  return 0;
}

void laes_flere_kort_fra_fil(FILE *file, bilkort biler[], int length){
  for(int i = 0; i < length; i++){
    bilkort bil;
    int result = fscanf(file, " %[^0-9] %d %d %d %d", bil.navn, &bil.top_fart, &bil.hk, &bil.acceleration, &bil.ccm);
    if(result != 5){
      printf("Der gik noget galt i indlaesningen af bil nummer %d", i);
      exit(EXIT_FAILURE);
    }
    biler[i] = bil;
  }
}

bilkort laes_kort_fra_fil(FILE *file){
  bilkort bil;

  fscanf(file, "%[^0-9] %d %d %d %d", bil.navn, &bil.top_fart, &bil.hk, &bil.acceleration, &bil.ccm);

  return bil;
}

void gem_flere_kort_i_fil(FILE *fil, bilkort biler[], int length){
  for(int i = 0; i < length; i++){
    gem_kort_i_fil(fil, biler[i]);
  }
}

void gem_kort_i_fil(FILE *fil, bilkort bil){
  fprintf(fil, "%s %d %d %d %d\n", bil.navn, bil.top_fart, 
                                 bil.hk, bil.acceleration, bil.ccm);
}

void udskriv_kort(bilkort bil){
  //Hiv vaerdierne ud
  char *n = bil.navn;
  int f = bil.top_fart;
  int hest = bil.hk;
  int a = bil.acceleration;
  int ccm = bil.ccm;

  //Print
  printf("\n Navn: %s", n);
  printf("\n Top fart: %d", f);
  printf("\n HK: %d", hest);
  printf("\n Acceleration: %d", a);
  printf("\n CCM: %d\n", ccm);

}

bilkort indlaes_bilkort(void){
  char navnet[30];
  int f;
  int hk;
  int acc;
  int ccm;

  //Indlæs fra tastatur.
  printf("Tast et navn: \n");
  scanf("%s", navnet);
  printf("Tast topfart:\n");
  scanf("%d", &f);
  printf("Tast hestekrafter:\n");
  scanf("%d", &hk);
  printf("Tast acceleration:\n");
  scanf("%d", &acc);
  printf("Tast ccm:\n");
  scanf("%d", &ccm);

  //Opret bilkort og læg værdierne ind.
  bilkort nyt_kort;
  strcpy(nyt_kort.navn, navnet);
  nyt_kort.top_fart = f;
  nyt_kort.hk = hk;
  nyt_kort.acceleration = acc;
  nyt_kort.ccm = ccm;

  return nyt_kort;

}
