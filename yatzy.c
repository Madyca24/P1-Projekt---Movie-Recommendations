// Skrevet af Mads Dybdal Cajar, mcajar24@student.aau.dk, gruppe 9, CPH-SW1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void input_antal_terninger(int *antalterninger);
void terningekast(int antal, int *kastarray);
void printtest(int antalterninger);
void pointtaeller(int antalterninger, int *kastpoint);
void scoreboard(int *kastpoint);

int main(void){
    int antalterninger = 0;
    int score[16];
    srand(time(NULL));

    input_antal_terninger(&antalterninger);

    pointtaeller(antalterninger, score);

    scoreboard(score);

    return 0;
}

void input_antal_terninger(int *antalterninger){
    printf("Saa skal der spilles Yatzy! Hvor mange terninger oensker du at bruge (mindst 5)? ");
    scanf(" %d", antalterninger);

}

void terningekast(int antal, int *kastarray){
    for (int i = 0; i < antal; i++){
        kastarray[i] = (rand() % 6) + 1;
    }
}

void pointtaeller(int antalterninger, int *kastpoint){
    int t[antalterninger];
    int sum = 0;

    for (int i = 0; i < 16; i++){
        kastpoint[i] = 0;
    }

    // 1 - 6 
    for (int i = 1; i < 7; i++){
        terningekast(antalterninger, t);
        kastpoint[i-1] = 0;
        int point = 0;

        for (int j = 0; j < antalterninger; j++){
             if (t[j] == i && point < i * 5)
                 point += i;      
        }

        kastpoint[i-1] += point;
             
        printf("%d-ere     ", i);
        for (int k = 0; k < antalterninger; k++){
            printf("%d ", t[k]);
        }
        printf(" -  %d\n", kastpoint[i-1]);
    }


    // bonus
    if ((kastpoint[0] + kastpoint[1] + kastpoint[2] + kastpoint[3] + kastpoint[4] + kastpoint[5]) >= 63)
        kastpoint[6] += 50;


    // et par
    terningekast(antalterninger, t);

    for (int i = 6; i > 0; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }
        
        if (count >= 2) {
            kastpoint[7] = i * 2;
            break;
        }
    }
    printf("et par    ");
    for (int k = 0; k < antalterninger; k++){
        printf("%d ", t[k]);
    }
    printf(" -  %d\n", kastpoint[7]);


    // to par
    int fundetpar1 = 0;
    int fundetpar2 = 0;

    terningekast(antalterninger, t);

    for (int i = 6; i > 0; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }
        
        if (count >= 2 && !fundetpar1){
            kastpoint[8] = i * 2;
            fundetpar1 = 1;
            count = 0;
        }

        if (count >= 2 && !fundetpar2){
            kastpoint[8] += i * 2;
            fundetpar2 = 1;
            break;
        }
    }
    printf("To par    ");
        for (int k = 0; k < antalterninger; k++){
            printf("%d ", t[k]);
        }
        printf(" -  %d\n", kastpoint[8]);


    // tre ens
    terningekast(antalterninger, t);

    for (int i = 6; i > 0; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }
        
        if (count >= 3) {
            kastpoint[9] = i * 3;
            break;
        }
    }
    printf("tre ens   ");
    for (int k = 0; k < antalterninger; k++){
        printf("%d ", t[k]);
    }
    printf(" -  %d\n", kastpoint[9]);


    // fire ens
    terningekast(antalterninger, t);

    for (int i = 6; i > 0; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }
        
        if (count >= 4) {
            kastpoint[10] = i * 4;
            break;
        }
    }
    printf("fire ens  ");
    for (int k = 0; k < antalterninger; k++){
        printf("%d ", t[k]);
    }
    printf(" -  %d\n", kastpoint[10]);


    // Lille straight
    terningekast(antalterninger, t);

    for (int i = 5; i > 0; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }

        if (count == 0)
            break;
        
        else if (i == 1){
            kastpoint[11] += 15;
        }
    }
    printf("Lille     ");
    for (int k = 0; k < antalterninger; k++){
        printf("%d ", t[k]);
    }
    printf(" -  %d\n", kastpoint[11]);


    // Stor straight
    terningekast(antalterninger, t);

    for (int i = 6; i > 1; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }

        if (count == 0)
            break;
        
        else if (i == 2){
            kastpoint[12] += 20;
        }
    }
    printf("Stor      ");
    for (int k = 0; k < antalterninger; k++){
        printf("%d ", t[k]);
    }
    printf(" -  %d\n", kastpoint[12]);


    // Fuld hus
    int fundettreens = 0;
    fundetpar1 = 0;
    sum = 0;

    terningekast(antalterninger, t);

    for (int i = 6; i > 0; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }
        
        if (count >= 3) {
            sum += i * 3;
            fundettreens = i;
            break;
        }
    }

    if (fundettreens != 0){
        for (int i = 6; i > 0; i--){
            int count = 0;

            for (int j = 0; j < antalterninger; j++){
                if (t[j] == i && i != fundettreens)
                    count++;
            }
            
            if (count >= 2) {
                sum += i * 2;
                kastpoint[13] = sum;
                break;
            }
        }
    }
    printf("Fuld Hus  ");
        for (int k = 0; k < antalterninger; k++){
            printf("%d ", t[k]);
        }
        printf(" -  %d\n", kastpoint[13]);


    // Chance
    int chancecount = 0;
    sum = 0;

    terningekast(antalterninger, t);

    for (int i = 6; i > 0; i--){
        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i){
                chancecount++;
                sum += i;

                if (chancecount == 5){
                    kastpoint[14] = sum;
                    break;
                }
            }
        }
    }
    printf("Chance    ");
        for (int k = 0; k < antalterninger; k++){
            printf("%d ", t[k]);
        }
        printf(" -  %d\n", kastpoint[14]);


    // YATZY
    terningekast(antalterninger, t);

    for (int i = 6; i > 0; i--){
        int count = 0;

        for (int j = 0; j < antalterninger; j++){
            if (t[j] == i)
                count++;
        }
        
        if (count >= 5) {
            kastpoint[15] += 50;
            break;
        }
    }
    printf("YATZY     ");
    for (int k = 0; k < antalterninger; k++){
        printf("%d ", t[k]);
    }
    printf(" -  %d\n", kastpoint[15]);
}

void scoreboard(int *kastpoint){
    int TOTAL = 0;
    const char *rundenavne[] = {
    "1-ere",
    "2-ere",
    "3-ere",
    "4-ere",
    "5-ere",
    "6-ere",
    "BONUS",
    "Et par",
    "To par",
    "Tre ens",
    "Fire ens",
    "Lille",
    "Stor",
    "Fuld hus",
    "Chance",
    "YATZY"
};
    printf("\nScore board:");

    for (int i = 0; i < 16; i++){
        printf("\n%-10s", rundenavne[i]);
        printf(":  %d", kastpoint[i]);
        
        TOTAL += kastpoint[i]; 

        if (i == 6 || i == 15)
            printf("\n");
    }
    
    printf("\nTOTAL     :  %d\n", TOTAL);
}
