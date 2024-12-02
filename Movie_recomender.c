#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOVIE_ARRAY_SIZE 50

typedef struct {
    char name[40];
    char category_1[10];
    char category_2[10];
    char language[8];
    int age_range;
    int group_size;
    int score;
} movie;

movie movies[MOVIE_ARRAY_SIZE];

void laesning_af_fil(FILE *f1, int length, movie movies[]);
int survey(movie movies[], int length, char *genre, char *sprog, int *alder, int *personer);
int comparescores(const void* a, const void* b);
void recommendation(movie movies[], char *genre, char *sprog, int alder, int personer, int length);
void battle_function (movie movies[]);

int main(void) {
    char genre[10];
    char sprog[10];
    int alder;
    int personer;

    FILE *f1 = fopen("Movie_dataset_madsctest.txt", "r");
    if (f1 == NULL) {
        printf("Filen kunne ikke aabnes!\n");
        exit(1);
    }

    laesning_af_fil(f1, MOVIE_ARRAY_SIZE, movies);
    fclose(f1);
    survey(movies, MOVIE_ARRAY_SIZE, genre, sprog, &alder, &personer);
    recommendation(movies, genre, sprog, alder, personer, MOVIE_ARRAY_SIZE);
    battle_function(movies);

    return 0;
}
void laesning_af_fil(FILE *f1, int length, movie movies[]) {
    movie movie;
    for (int i = 0; i < length; i++) { 
        int result = fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%d,%d,%d,", 
                            movie.name, movie.category_1, movie.category_2, 
                            movie.language, &movie.age_range, 
                            &movie.group_size, &movie.score);
        
        if (result != 7) {
            printf("der gik galt noget i indlaesning af film %d result %d\n", i, result);
            exit(EXIT_FAILURE); 
        }
        movies[i] = movie;
    }
}

int survey(movie movies[], int length, char *genre, char *sprog, int *alder, int *personer) {
    // Introduktion til programmet
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*   Velkommen til MoodFlix! :)                 *\n");
    printf("*                                              *\n");
    printf("*   Dette program hjaelper dig med at finde    *\n");
    printf("*   en god film baseret paa dine praeferencer. *\n");
    printf("*                                              *\n");
    printf("*   Du vil blive bedt om at vaelge:            *\n");
    printf("*   - Genre (Action, Comedy, Drama, etc)       *\n");
    printf("*   - Sprog (Engelsk, Dansk)                   *\n");
    printf("*   - Din alder                                *\n");
    printf("*   - Antal personer, der ser med              *\n");
    printf("*                                              *\n");
    printf("************************************************\n\n");

    printf("Lad os komme i gang!\n");

    // Validering af genre
    int valid_genre = 0;
    while (!valid_genre) {
        printf("Indtast din foretrukne genre (Action, Comedy, Crime, Drama, Thriller, Horror, Sci-fi, Romance, Fantasy, Animated, Family, Horror, Mystery ):\n");
        scanf("%s", genre);

        if (strcmp(genre, "Action") == 0 || strcmp(genre, "action") == 0 ||
            strcmp(genre, "Comedy") == 0 || strcmp(genre, "comedy") == 0 ||
            strcmp(genre, "Crime") == 0 || strcmp(genre, "crime") == 0 ||
            strcmp(genre, "Drama") == 0 || strcmp(genre, "drama") == 0 ||
            strcmp(genre, "Thriller") == 0 || strcmp(genre, "thriller") == 0 ||
            strcmp(genre, "Sci-fi") == 0 || strcmp(genre, "sci-fi") == 0 ||
            strcmp(genre, "Romance") == 0 || strcmp(genre, "romance") == 0 ||
            strcmp(genre, "Fantasy") == 0 || strcmp(genre, "fantasy") == 0 ||
            strcmp(genre, "Animated") == 0 || strcmp(genre, "animated") == 0 ||
            strcmp(genre, "Adventure") == 0 || strcmp(genre, "adventure") == 0||
            strcmp(genre, "Family") == 0 || strcmp(genre, "family") == 0 ||
            strcmp(genre, "Horror") == 0 || strcmp(genre, "horror") == 0 ||
            strcmp(genre, "Mystery") == 0 || strcmp(genre, "mystery") == 0 ) {
            valid_genre = 1;
        } else {
            printf("Denne genre er ikke tilgængelig. Vælg venligst en af de følgende muligheder:\n");
        }
    }

    // Validering af sprog
    int valid_sprog = 0;
    while (!valid_sprog) {
        printf("Indtast dit foretrukne sprog (Engelsk, Dansk): ");
        scanf("%s", sprog);

        if (strcmp(sprog, "Engelsk") == 0 || strcmp(sprog, "engelsk") == 0 ||
            strcmp(sprog, "Dansk") == 0 || strcmp(sprog, "dansk") == 0) {
            valid_sprog = 1;
        } else {
            printf("Dette sprog er ikke tilgængeligt. Vælg venligst en af de følgende muligheder:\n");
        }
    }

    // Validering af alder
    int valid_alder = 0;
    while (!valid_alder) {
        printf("Indtast din alder: ");
        scanf("%d", alder);

        if (*alder > 0 && *alder < 120) { // Alder skal være realistisk
            valid_alder = 1;
        } else {
            printf("Ugyldig alder. Indtast venligst en alder mellem 1 og 120.\n");
        }
    }

    // Validering af antal personer
    int valid_personer = 0;
    while (!valid_personer) {
        printf("Hvor mange personer ser med (1 = alene, 2 = partner, 3 = familie): ");
        scanf("%d", personer);

        if (*personer >= 1 && *personer <= 3) { // Skal være mellem 1 og 3
            valid_personer = 1;
        } else {
            printf("Ugyldigt antal personer. Indtast 1, 2 eller 3.\n");
        }
    }

    // Udskriv brugerens valg som bekræftelse
    printf("\nTak for dine valg! Her er, hvad du har valgt:\n");
    printf("Genre: %s\n", genre);
    printf("Sprog: %s\n", sprog);
    printf("Alder: %d\n", *alder);
    printf("Antal personer: %d\n", *personer);

    return 0;
}


void recommendation(movie movies[], char *genre, char *sprog, int alder, int personer, int length) {
    for (int i = 0; i < length; i++) {
        int sprogalder = 1,
            genre1match = 0,
            genre2match = 0,
            persontalmatch = 0;

        if (strcmp(movies[i].category_1, genre) == 0)
            genre1match = 10;

        if (strcmp(movies[i].category_2, genre) == 0)
            genre2match = 5;

        if (movies[i].group_size == personer)
            persontalmatch = 5;

        if (strcmp(movies[i].language, sprog) != 0 || alder < movies[i].age_range)
            sprogalder = 0;

        movies[i].score = (genre1match + genre2match + persontalmatch) * sprogalder;
    }

    qsort(movies, length, sizeof(movie), comparescores);

    printf("\nVores filmanbefalinger:\n");
    for (int i = length - 1; i >= length - 5 && i >= 0; i--) {
        printf("%s - Score: %d\n", movies[i].name, movies[i].score);
    }

    printf("\nTak for at bruge MoodFlix! God fornøjelse med filmen!\n");
}

int comparescores(const void *a, const void *b) {
    return ((movie*)a)->score - ((movie*)b)->score;
}


void battle_function (movie movies[]){
    int klar_tjaekker, hvilken_film_beholdes;
    movie battle_array[3];
    printf("Velkommen til vores battlepicker\n\n");
    printf("reglerne er at vi praesentere 2 film herefter skal du se traileren og vaelge hvilken af filmene du vil beholde\n");
    printf("Du skal bare taste 1 eller 2 afhaengig af hvilken film du vil beholde. Dernaest vil vi saette din valgte film ");
    printf("op mod en anden film hvor du saa skal valege igen. Efter et par runder findes der en vinder\n\n");
    printf("hvis du har forstaet reglerne tast 1\n\n");

    while (klar_tjaekker != 1){ 
        scanf(" %d",&klar_tjaekker);
        if (klar_tjaekker != 1){
            printf("Hov jeg tror du har faaet tastet noget forkert. Fik du laest reglerne korrekt\n");
            printf("Proev venligst igen\n\n");
        }
    }
    printf("Lad os starte\n\n");

    strcpy(battle_array[0].name, movies[0].name); 
    strcpy(battle_array[1].name, movies[1].name); 
    // J er sat til 2 for at vælge den 3 film i movie arrayet, Når battlen er udført tælles j op med 1
    // så den vælger den 4 film i arrayet osv.
        int j = 2;
    for (int i = 0; i < 5; i++){
        hvilken_film_beholdes=0;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("Film nr 1: %s\n Traileren: \n\n",battle_array[0].name);
        printf("Film nr 2: %s\n Traileren: \n\n",battle_array[1].name);
        printf("Hvilken vil du helst se?\n");
        while (hvilken_film_beholdes != 1 && hvilken_film_beholdes != 2 ){
            scanf(" %d", &hvilken_film_beholdes);

            if(hvilken_film_beholdes == 1){
               printf("Godt valg!\n");
               strcpy(battle_array[1].name, movies[j].name);
            }else if (hvilken_film_beholdes == 2){
               printf("Godt valg!\n");
               strcpy(battle_array[0].name, movies[j].name);
            }else printf("Du gav et forkert imput proev igen\n");
        
        }
        j++;
    }

    printf("Din valgte film er %s\n\n", battle_array[hvilken_film_beholdes-1].name);

    

}