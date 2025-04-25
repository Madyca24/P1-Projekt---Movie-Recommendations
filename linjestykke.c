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
  double delta_1x, delta_1y, laengde1;
  delta_1x = p1_x - p2_x;
  delta_1y = p1_y - p2_y;

  printf("delta x: %lf\n", delta_1x);
  printf("delta y: %lf\n", delta_1y);
 
  laengde1 = sqrt(delta_1x*delta_1x + delta_1y*delta_1y);

    double delta_2x, delta_2y, laengde2;
  delta_2x = p1_x - p3_x;
  delta_2y = p1_y - p3_y;

  printf("delta x: %lf\n", delta_2x);
  printf("delta y: %lf\n", delta_2y);
 
  laengde2 = sqrt(delta_2x*delta_2x + delta_2y*delta_2y);

    double delta_3x, delta_3y, laengde3;
  delta_3x = p2_x - p3_x;
  delta_3y = p2_y - p3_y;

  printf("delta x: %lf\n", delta_3x);
  printf("delta y: %lf\n", delta_3y);
 
  laengde3 = sqrt(delta_3x*delta_3x + delta_3y*delta_3y);

  //Programmet udskriver længden
  printf("Laengden er %lf\n",laengde1);
  printf("Laengden er %lf\n",laengde2);
  printf("Laengden er %lf\n",laengde3);

  double samletlaengde;
  samletlaengde = laengde1 + laengde2 + laengde3;

  printf("Den samlede Laengde er %lf\n",samletlaengde);

  return 0;
}
