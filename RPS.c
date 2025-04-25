#include <stdio.h>

int main(void){
    char p1hand, p2hand;

    printf("spiller 1 indtast din haand (r/p/s)\n");
    scanf(" %c", &p1hand);

    printf("spiller 2 indtast din haand (r/p/s)\n");
    scanf(" %c", &p2hand);

    int p1_w = (p1hand == 's' && p2hand == 'p') ||
               (p1hand == 'p' && p2hand == 'r') ||
               (p1hand == 'r' && p2hand == 's');
    printf("spiller 1 har vundet (1 er ja, 0 er nej): %d", p1_w);
    printf("\nspillet er uafgjort (1 er ja, 0 er nej): %d\n", p1hand == p2hand);
    return 0;
}