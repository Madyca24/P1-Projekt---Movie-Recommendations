// Skrevet af Mads Dybdal Cajar, mcajar24@student.aau.dk, gruppe 9, CPH-SW1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ANTAL_KAMPE 90
#define ANTAL_HOLD 12

// laver de to structs
typedef struct {
    char ugedag[4];
    int dag;
    int maaned;
    double tidspunkt;
    char hold1[4];
    char hold2[4];
    int hold1_maal;
    int hold2_maal;
    int tilskuere;
} kamp;

typedef struct {
    char holdnavn[4];
    int point;
    int maalscoret;
    int maalmodhold;
    int maalforskel;
} hold;

kamp kampe[ANTAL_KAMPE];
hold allehold[ANTAL_HOLD];

void laesning_af_fil(FILE *f1, int antalkampe, kamp kampe[]);
void giv_point_og_maal(kamp kampe[], hold allehold[], int antalkampe, int antalhold);
int comp(const void *a, const void *b);
void pointtavle(hold allehold[], int antalhold);

int main(void){
    // åbner filen
    FILE *f1 = fopen("kampe-2024-2025.txt", "r");
    if (f1 == NULL) {
        printf("Filen kunne ikke aabnes!\n");
        exit(1);
    }
    // scanner filen, sætter kampe ind i et array af structs og lukker filen
    // ændre variabelnavn fra f1 til inputfil
    laesning_af_fil(f1, ANTAL_KAMPE, kampe);
    fclose(f1);
    
    // laver array af hold og sætter dem ind i array af structs
    // note: can gøres med et loop:
    // const char *team_names[ANTAL_HOLD] = {"AGF", "FCM", "FCN", "AaB", "SIF", "SJF", 
    //                                       "RFC", "VFF", "BIF", "LBK", "FCK", "VB"};
    // for (int i = 0; i < ANTAL_HOLD; i++) {
    //     strcpy(allehold[i].holdnavn, team_names[i]);
    //     allehold[i].point = 0;
    //     allehold[i].maalscoret = 0;
    //     allehold[i].maalmodhold = 0;
    //     allehold[i].maalforskel = 0;
    // }

    hold AGF = {"AGF", 0, 0, 0, 0};     allehold[0] = AGF;
    hold FCM = {"FCM", 0, 0, 0, 0};     allehold[1] = FCM;
    hold FCN = {"FCN", 0, 0, 0, 0};     allehold[2] = FCN;
    hold AaB = {"AaB", 0, 0, 0, 0};     allehold[3] = AaB;
    hold SIF = {"SIF", 0, 0, 0, 0};     allehold[4] = SIF;
    hold SJF = {"SJF", 0, 0, 0, 0};     allehold[5] = SJF;
    hold RFC = {"RFC", 0, 0, 0, 0};     allehold[6] = RFC;
    hold VFF = {"VFF", 0, 0, 0, 0};     allehold[7] = VFF;
    hold BIF = {"BIF", 0, 0, 0, 0};     allehold[8] = BIF;
    hold LBK = {"LBK", 0, 0, 0, 0};     allehold[9] = LBK;
    hold FCK = {"FCK", 0, 0, 0, 0};     allehold[10] = FCK;
    hold VB = {"VB", 0, 0, 0, 0};       allehold[11] = VB;


    giv_point_og_maal(kampe, allehold, ANTAL_KAMPE, ANTAL_HOLD);
    pointtavle(allehold, ANTAL_HOLD);

    return 0;
}
// læser filen ind i et array af structs
void laesning_af_fil(FILE *f1, int antalkampe, kamp kampe[]) {
    kamp kamp;
    for (int i = 0; i < antalkampe; i++) { 
        int result = fscanf(f1, "%3s %d/%d %lf %3s - %3s %d - %d %d", 
                            kamp.ugedag, &kamp.dag, &kamp.maaned, &kamp.tidspunkt, kamp.hold1, 
                            kamp.hold2, &kamp.hold1_maal, &kamp.hold2_maal, &kamp.tilskuere);
        
        if (result != 9) {
            printf("der gik galt noget i indlaesning af kampe %d result %d\n", i, result);
            exit(EXIT_FAILURE); 
        }
        kampe[i] = kamp;
    }
}
// fordeler point, mål af hold, mål mod hold og målforskel
void giv_point_og_maal(kamp kampe[], hold allehold[], int antalkampe, int antalhold){
    for (int i = 0; i < antalkampe; i++){
        for (int n = 0; n < antalhold; n++){
            if (strcmp(allehold[n].holdnavn, kampe[i].hold1) == 0){
                allehold[n].maalscoret += kampe[i].hold1_maal;
                allehold[n].maalmodhold += kampe[i].hold2_maal;
                allehold[n].maalforskel += (kampe[i].hold1_maal - kampe[i].hold2_maal);
            
                if (kampe[i].hold1_maal > kampe[i].hold2_maal)
                    allehold[n].point += 3;
                if (kampe[i].hold1_maal == kampe[i].hold2_maal)
                    allehold[n].point += 1;
            }

            if (strcmp(allehold[n].holdnavn, kampe[i].hold2) == 0){
                allehold[n].maalscoret += kampe[i].hold2_maal;
                allehold[n].maalmodhold += kampe[i].hold1_maal;
                allehold[n].maalforskel += (kampe[i].hold2_maal - kampe[i].hold2_maal);
            
                if (kampe[i].hold2_maal > kampe[i].hold1_maal)
                    allehold[n].point += 3;
                if (kampe[i].hold1_maal == kampe[i].hold2_maal)
                    allehold[n].point += 1;
            }
        }
    }
    // sortering, se comp funktion
    qsort(allehold, antalhold, sizeof(hold), comp);
}

// sorterer først for points, så maalforskel
int comp(const void *a, const void *b) {
    const hold *holdA = (const hold *)a;
    const hold *holdB = (const hold *)b;

    if (holdA->point != holdB->point){
        return holdB->point - holdA->point;
    } 
    
    else {
        return holdB->maalforskel - holdA->maalforskel;
    }
}

// printer pointtavle
void pointtavle(hold allehold[], int antalhold){
    printf("\n| Holdnavn | Point | Maal-af-hold | Maal-mod-hold\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < antalhold; i++){
         printf("  %s        %d      %d             %d\n", 
                allehold[i].holdnavn, allehold[i].point,
                allehold[i].maalscoret, allehold[i].maalmodhold);
    
    }
}

