#include <stdio.h>
#include <math.h>

void run_calculator(void);
void scan_data(char *operator, double *operand);
void do_next_op(double *akkumulator, char operator, double operand);

// Skrevet af Mads Dybdal Cajar - 28/10/2024

int main(void){
    
    // printer forklaring til brugeren
    printf(" Welcome to Mads' calculator!\n\nYou can do basic calculations using + - * / ^ and an operand.\n\nAdditionally, you can use these opperators for different purposes:\n # to calcuate the square root of the current result.\n %% to change the result from positive to negative or the reverse.\n ! to divide 1 by the current result.\n q to end the calculations.\n\n");
    // kører regnemaskinen
    run_calculator();

    return 0;
}


void run_calculator(void){

    double akkumulator = 0.0, operand;
    char operator;

    // while loopet checker for q (slutter program)
    while(operator != 'q'){
        // modtager brugerens input
        scan_data(&operator, &operand);   

        // beregner den nye akkumulator
        do_next_op(&akkumulator, operator, operand);

        printf("\nCurrent result: %lf\n", akkumulator);
    }
}


void scan_data(char *operator, double *operand){

    printf("\nEnter operator: ");
        scanf(" %c", operator);

        // saetter operand til 0 hvis det er en unær operator
        if(*operator == '#' || *operator == '%' || *operator == '!' || *operator == 'q')
            *operand = 0.0;

        else{
            printf("Enter operand: ");
            scanf(" %lf", operand);
        }
}

void do_next_op(double *akkumulator, char operator, double operand){

    switch(operator){
        case '+':
            *akkumulator += operand; 
            break;
        case '-':
            *akkumulator -= operand; 
            break;
        case '*':
            *akkumulator *= operand; 
            break;
        case '/':
            if (operand != 0)
                *akkumulator /= operand;
            else
                printf("Dividing by zero is not allowed.\n");
            break;
        case '^':
            *akkumulator = pow(*akkumulator, operand); 
            break;
        case '#':
            *akkumulator = sqrt(*akkumulator); 
            break;
        case '%':
            *akkumulator *= -1; 
            break;
        case '!':
        if (*akkumulator != 0)
            *akkumulator = 1 / *akkumulator;
        else
            printf("Dividing by zero is not allowed.\n");
        break;
        case 'q':
            break;
        default: printf("invalid operator, please try again.\n");
            break;
    }
}