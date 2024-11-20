#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOVIE_ARRAY_SIZE 50
/* skal indeholde
genre
sprog
antal personer (en eller party)
bruger alder
mood gimmick
find en måde at få den til at sammenkoble*/

int main() {
    char genre[10];
    char sprog[10];
    int alder;
    int personer;
    char mood[10];

    // Introduktion til programmet
    printf("**********************************************\n");
    printf("*                                            *\n");
    printf("*   Velkommen til MoodFlix! :)               *\n");
    printf("*                                            *\n");
    printf("*   Dette program hjælper dig med at finde   *\n");
    printf("*   en god film baseret på dine præferencer. *\n");
    printf("*                                            *\n");
    printf("*   Du vil blive bedt om at vælge:           *\n");
    printf("*   - Genre (Action, Comedy, Drama, etc)     *\n");
    printf("*   - Sprog (Engelsk, Dansk)                 *\n");
    printf("*   - Din alder                              *\n");
    printf("*   - Antal personer, der ser med            *\n");
    printf("*   - Dit humør (glad, trist, sur, træt)     *\n");
    printf("*                                            *\n");
    printf("**********************************************\n\n");

    printf("Lad os komme i gang!\n");

    // Validering af genre
    int valid_genre = 0;
    while (!valid_genre) {
        printf("Indtast din foretrukne genre (Action, Comedy, Crime, Drama, Thriller, Horror, Sci-fi, Romance, Fantasy, Animated): ");
        scanf("%s", genre);

        // bogstav størelse 
        if (strcmp(genre, "Action") == 0 || strcmp(genre, "action") == 0 ||
            strcmp(genre, "Comedy") == 0 || strcmp(genre, "comedy") == 0 ||
            strcmp(genre, "Crime") == 0 || strcmp(genre, "crime") == 0 ||
            strcmp(genre, "Drama") == 0 || strcmp(genre, "drama") == 0 ||
            strcmp(genre, "Thriller") == 0 || strcmp(genre, "thriller") == 0 ||
            strcmp(genre, "Sci-fi") == 0 || strcmp(genre, "sci-fi") == 0 ||
            strcmp(genre, "Romance") == 0 || strcmp(genre, "romance") == 0 ||
            strcmp(genre, "Fantasy") == 0 || strcmp(genre, "fantasy") == 0 ||
            strcmp(genre, "Animated") == 0 || strcmp(genre, "animated") == 0) {
            valid_genre = 1;
        } else {
            printf("Denne genre er ikke tilgængeligt. Vælg venligst en af de følgende muligheder:\n");
        }
    }

    // sprog valid
    int valid_sprog = 0;
    while (!valid_sprog) {
        printf("Indtast dit foretrukne sprog (Engelsk, Dansk): ");
        scanf("%s", sprog);

        // store og små bogstarv
        if (strcmp(sprog, "Engelsk") == 0 || strcmp(sprog, "engelsk") == 0 ||
            strcmp(sprog, "Dansk") == 0 || strcmp(sprog, "dansk") == 0) {
            valid_sprog = 1;
        } else {
            printf("Dette sprog er ikke tilgængeligt. Vælg venligst en af de følgende muligheder:\n");
        }
    }

    // alder valid
    int valid_alder = 0;
    while (!valid_alder) {
        printf("Please write down your age: ");
        scanf("%d", &alder);

        if (alder > 0 && alder < 120) { // Alder skal være realistisk
            valid_alder = 1;
        } else {
            printf("Invalid age. please input an age between 1 and 120 :).\n");
        }
    }

    // Validering af antal personer :)
    int valid_personer = 0;
    while (!valid_personer) {
        printf("Hvor mange personer ser med (1 = alene, 2 = partner, 3 = familie): ");
        scanf("%d", &personer);

        if (personer >= 1 && personer <= 3) { // Skal være mellem 1 og 3
            valid_personer = 1;
        } else {
            printf("Ugyldigt antal personer. Indtast 1, 2 eller 3.\n");
        }
    }

    // Validering af humør
    int valid_mood = 0;
    while (!valid_mood) {
        printf("Hvordan er dit humør (Happy, Sad, Angry, Tired): ");
        scanf("%s", mood);

        // Tjek for både store og små bogstaver
        if (strcmp(mood, "Happy") == 0 || strcmp(mood, "happy") == 0 ||
            strcmp(mood, "Sad") == 0 || strcmp(mood, "sad") == 0 ||
            strcmp(mood, "Angry") == 0 || strcmp(mood, "angry") == 0 ||
            strcmp(mood, "Tired") == 0 || strcmp(mood, "tired") == 0) {
            valid_mood = 1;
        } else {
            printf(" Sorry :(, Invalid mood option, try one of the following:.\n");
        }
    }

    // Udskriv brugerens valg som bekræftelse
    printf("\nTak for dine valg! Her er, hvad du har valgt:\n");
    printf("Genre: %s\n", genre);
    printf("Sprog: %s\n", sprog);
    printf("Alder: %d\n", alder);
    printf("Antal personer: %d\n", personer);
    printf("Humør: %s\n", mood);

    // Vores film  anbefallinger her:
    
    
    
    
    //Afsluttende farvel fra systemet til brugeren
    printf("\nTak for at bruge MoodFlix! God fornøjelse med filmen!\n");
typedef struct{
char name[40];
char category_1[10];
char category_2 [10];
char language [8];
int  age_range;
int  group_size;
}movie;
movie movies[MOVIE_ARRAY_SIZE];

void laesning_af_fil(FILE *f1, int length, movie movies[]);
void print_array(movie movies[],int length);
int main(void) {
    
    FILE *f1 = fopen("Movie_dataset.txt", "r");
    if (f1 == NULL){
    printf("Filen kunne ikke aabnes!\n");
    exit(1);
    }
    laesning_af_fil(f1, MOVIE_ARRAY_SIZE, movies);
    fclose(f1);
    print_array(movies,MOVIE_ARRAY_SIZE);
    return 0;
} 


void laesning_af_fil(FILE *f1, int length, movie movies[]){
    movie movie;
    for(int i = 0; i < length; i++){ 
       int result = fscanf(f1,"%[^,],%[^,],%[^,],%[^,],%d,%d,",
                             movie.name, movie.category_1, movie.category_2,
                            movie.language, &movie.age_range, &movie.group_size);
       
        if (result != 6){
            printf("der gik galt noget i indlaesning af film %d result %d\n", i, result);
            exit(EXIT_FAILURE); 
        }
        movies[i] = movie;
    }
}

void print_array(movie movies[],int length){
    for(int i =0; i < length; i++){
        printf("%s, %s, %s, %s, %d, %d\n", 
               movies[i].name, movies[i].category_1, 
               movies[i].category_2, movies[i].language, 
               movies[i].age_range, movies[i].group_size);
    }
}