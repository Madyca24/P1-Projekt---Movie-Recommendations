#include <stdio.h>
#include <math.h>

double samlet_sidelaengde(double p1_x, double p1_y, 
                          double p2_x, double p2_y, 
                          double p3_x, double p3_y,
                          double p4_x, double p4_y);
void print_resultatet(double resultat);
double regn_side(double pA_x, double pA_y, double pB_x, double pB_y);

int main(void)
{
  double p1_x, p1_y; /* Point 1's coordinates */
  double p2_x, p2_y; /* Point 2's coordinates */
  double p3_x, p3_y; /* Point 3's coordinates */
  double p4_x, p4_y; /* Point 4's coordinates */
  double sum;

  printf("Tast punkt 1:\n");
  scanf(" %lf %lf", &p1_x, &p1_y);
  
  printf("Tast punkt 2:\n");
  scanf(" %lf %lf", &p2_x, &p2_y);

  printf("Tast punkt 3:\n");
  scanf(" %lf %lf", &p3_x, &p3_y);

  printf("Tast punkt 4:\n");
  scanf(" %lf %lf", &p4_x, &p4_y);

  //Regn samlet sidelaengde
  sum = samlet_sidelaengde(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y);

  //Udskriv resultatet
  print_resultatet(sum);

  return 0;
}

void print_resultatet(double resultat){
  printf("Her er den samlede sidelaengde, kaere bruger: %lf\n", resultat);
}

double samlet_sidelaengde(double p1_x, double p1_y, 
                          double p2_x, double p2_y, 
                          double p3_x, double p3_y,
                          double p4_x, double p4_y){

  double side12 = regn_side(p1_x, p1_y, p2_x, p2_y);
  double side23 = regn_side(p2_x, p2_y, p3_x, p3_y);
  double side34 = regn_side(p3_x, p3_y, p4_x, p4_y);
  double side14 = regn_side(p1_x, p1_y, p4_x, p4_y);

  double sum = side12 + side23 + side34 + side14;
  return sum;

}

double regn_side(double pA_x, double pA_y, double pB_x, double pB_y){
  double delta_x = pA_x - pB_x; 
  double delta_y = pA_y - pB_y;

  return sqrt(delta_x*delta_x + delta_y*delta_y);
}
