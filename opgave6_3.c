#include <stdio.h>
#include <math.h>

void udbetaling(int input, int *hundred, int *fifty, int *twenty, int *ten);

int main(void){

    int input, hundred, fifty, twenty, ten;

    printf("indtast antal dollars:\n");
    scanf(" %d", &input);

    if(input % 10 == 0) {
        udbetaling(input, &hundred, &fifty, &twenty, &ten);

        printf("100-sedler: %d\n", hundred);
        printf("50-sedler: %d\n", fifty);
        printf("20-sedler: %d\n", twenty);
        printf("10-sedler: %d\n", ten);
    }
    else{
        printf("ugyldigt input");
    } 

    return 0;
}

void udbetaling(int input, int *hundred, int *fifty, int *twenty, int *ten){
    int rest = 0;

    *hundred = input / 100;

    rest = input % 100;

    *fifty = rest / 50;

    rest = rest % 50;

    *twenty = rest / 20;

    rest = rest % 20;

    *ten = rest / 10;


    



}