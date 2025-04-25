#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <time.h>

typedef enum forret {Guacamole, Tarteletter, Lakserulle, Graeskarsuppe} forret;
typedef enum hovedret {Gyldenkaal, Hakkeboef, Gullash, Forloren_hare} hovedret;
typedef enum dessert {Is, Gulerodskage, Chokolademousse, Citronfromage} dessert;

void print_maaltid(void);
forret make_random_forret(void);
hovedret make_random_hovedret(void);
dessert make_random_dessert(void);
void print_forret(forret f);
void print_hovedret(hovedret h);
void print_dessert(dessert d);

int main(void){
    int i = 0;
    srand(time(NULL));
    
    for (i = 0; i < 25; i++){
        print_maaltid();
    }

    return 0;
}

void print_maaltid(void){
    forret f = make_random_forret();
    hovedret h = make_random_hovedret();
    dessert d = make_random_dessert();
    print_forret(f);
    print_hovedret(h);
    print_dessert(d);

}

forret make_random_forret(void){
    int ret = rand() % 4;
    return (forret)ret;
}    

hovedret make_random_hovedret(void){
    int ret = rand() % 4;
    return (hovedret)ret;
}    

dessert make_random_dessert(void){
    int ret = rand() % 4;
    return (dessert)ret;
}    

void print_forret(forret f){
    switch(f){
        case Guacamole: printf("Forret: Guacamole  "); break;
        case Tarteletter: printf("Forret: Tarteletter   "); break;
        case Lakserulle: printf("Forret: Lakserulle   "); break;
        case Graeskarsuppe: printf("Forret: Graeskar   "); break;
        default: printf("ingen forret"), exit(-1);
    }
    
}

void print_hovedret(hovedret h){ 
    switch(h){
        case Gyldenkaal: printf("Hovedret: Gyldenkaal   "); break;
        case Hakkeboef: printf("Hovedret: Hakkeboef   "); break;
        case Gullash: printf("Hovedret: Gullash   "); break;
        case Forloren_hare: printf("Hovedret: Forloren Hare   "); break;
        default: printf("ingen hovedret"), exit(-1);
        
    }

}

void print_dessert(dessert d){ 
    switch(d){
        case Is: printf("Dessert: Is og pandekager\n"); break;
        case Gulerodskage: printf("Dessert: Gulerodskage\n"); break;
        case Chokolademousse: printf("Dessert: Chokolademousse\n"); break;
        case Citronfromage: printf("Dessert: Citronfromage\n"); break;
        default: printf("ingen dessert"), exit(-1);
        
    }
}