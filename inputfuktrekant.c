#include <stdio.h>
#include <math.h>

void get_input(double *p1_x, double *p1_y, double *p2_x, double *p2_y, double *p3_x, double *p3_y);
double samlet_sidelaengde(double p1_x, double p1_y, 
                          double p2_x, double p2_y, 
                          double p3_x, double p3_y);
void print_resultatet(double resultat);
double regn_side(double pA_x, double pA_y, double pB_x, double pB_y);

int main(void)
{
  double p1_x, p1_y; /* Point 1's coordinates */
  double p2_x, p2_y; /* Point 2's coordinates */
  double p3_x, p3_y; /* Point 3's coordinates */
  double sum;
  
  get_input(&p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y);

  //Regn samlet sidelaengde
  sum = samlet_sidelaengde(p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);

  //Udskriv resultatet
  print_resultatet(sum);

  return 0;
}

void get_input(double *p1_x, double *p1_y, double *p2_x, double *p2_y, double *p3_x, double *p3_y){
    printf("Tast punkt 1:\n");
    scanf(" %lf %lf", p1_x, p1_y);
  
    printf("Tast punkt 2:\n");
    scanf(" %lf %lf", p2_x, p2_y);

    printf("Tast punkt 3:\n");
    scanf(" %lf %lf", p3_x, p3_y);

}

void print_resultatet(double resultat){
  printf("Her er den samlede sidelaengde, kaere bruger: %lf\n", resultat);
}

double samlet_sidelaengde(double p1_x, double p1_y, 
                          double p2_x, double p2_y, 
                          double p3_x, double p3_y){

  double side12 = regn_side(p1_x, p1_y, p2_x, p2_y);
  double side23 = regn_side(p2_x, p2_y, p3_x, p3_y);
  double side13 = regn_side(p1_x, p1_y, p3_x, p3_y);

  double sum = side12 + side23 + side13;
  return sum;

}

double regn_side(double pA_x, double pA_y, double pB_x, double pB_y){
  double delta_x = pA_x - pB_x; 
  double delta_y = pA_y - pB_y;

  return sqrt(delta_x*delta_x + delta_y*delta_y);
}
