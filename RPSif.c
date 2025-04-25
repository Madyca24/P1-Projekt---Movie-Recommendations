#include <stdio.h>

int main(void){
    char p1hand, p2hand;

    printf("spiller 1 indtast din haand (r/p/s)\n");
    scanf(" %c", &p1hand);

    printf("spiller 2 indtast din haand (r/p/s)\n");
    scanf(" %c", &p2hand);

    int p1_w = (p1hand == 's' && p2hand == 'p') ||
               (p1hand == 'p' && p2hand == 'r') ||
               (p1hand == 'r' && p2hand == 's'),

        p2_w = (p2hand == 's' && p1hand == 'p') ||
               (p2hand == 'p' && p1hand == 'r') ||
               (p2hand == 'r' && p1hand == 's'),

        uafgjort = (p1hand == p2hand);     

    if(p1_w){
        printf("spiller 1 vandt.\n");
    }
    else if(p2_w){
        printf("spiller 2 vandt.\n");
    }
   else{
    printf("spillet er uafgjort.\n");
   }
    return 0;
}