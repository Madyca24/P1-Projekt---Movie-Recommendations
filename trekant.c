#include <stdio.h>
#include <math.h>

int main(void){
  //Brugeren angiver linjestykke
  double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
  printf("Indtast punkt1:\n");
  scanf(" %lf %lf", &p1_x, &p1_y);

  printf("Punkt 1 (%lf,%lf)\n", p1_x, p1_y);

  printf("Indtast punkt2:\n");
  scanf(" %lf %lf", &p2_x, &p2_y);

  printf("Punkt 2 (%lf,%lf)\n", p2_x, p2_y);

  printf("Indtast punkt3:\n");
  scanf(" %lf %lf", &p3_x, &p3_y);

  printf("Punkt 3 (%lf,%lf)\n", p3_x, p3_y);
  
  //Programmet udregner længden
  double delta_x, delta_y, laengde1;
  delta_x = p1_x - p2_x;
  delta_y = p1_y - p2_y;
 
  laengde1 = sqrt(delta_x*delta_x + delta_y*delta_y);

  double laengde2;
  delta_x = p1_x - p3_x;
  delta_y = p1_y - p3_y;
 
  laengde2 = sqrt(delta_x*delta_x + delta_y*delta_y);

  double laengde3;
  delta_x = p2_x - p3_x;
  delta_y = p2_y - p3_y;

  laengde3 = sqrt(delta_x*delta_x + delta_y*delta_y);

  double samletlaengde;
  samletlaengde = laengde1 + laengde2 + laengde3;

  printf("Den samlede Laengde er %lf\n",samletlaengde);

  return 0;
}
