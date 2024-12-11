#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#define MOVIE_ARRAY_SIZE 50
#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

typedef struct {
    char name[40];
    char category_1[10];
    char category_2[10];
    char movie_language[8];
    int age_range;
    int group_size;
    double rating;
    char link[50];
    double score;
} movie;

movie movies[MOVIE_ARRAY_SIZE];

void laesning_af_fil(FILE *f1, int length, movie movies[]);
int survey(movie movies[], int length, char *genre1, char *genre2, char *genre3, char *sprog, int *age, int *group);
int comparescores(const void* a, const void* b);
void recommendation(movie movies[], char *genre1, char *genre2, char *genre3, char *sprog, int age, int group, double rating, int length);
void battle_function (movie movies[]);

int main(void) {
    char genre1[10];
    char genre2[10];
    char genre3[10];
    char sprog[8];
    int age;
    int group;
    double rating;

    FILE *f1 = fopen("Movie_dataset.txt", "r");
    if (f1 == NULL) {
        printf("The file couldn't open!\n");
        exit(1);
    }

    laesning_af_fil(f1, MOVIE_ARRAY_SIZE, movies);
    fclose(f1);
    survey(movies, MOVIE_ARRAY_SIZE, genre1, genre2, genre3, sprog, &age, &group);
    recommendation(movies, genre1, genre2, genre3, sprog, age, group, rating, MOVIE_ARRAY_SIZE);
    battle_function(movies);

    return 0;
}
void laesning_af_fil(FILE *f1, int length, movie movies[]) {
    movie movie;
    for (int i = 0; i < length; i++) { 
        int result = fscanf(f1, "%[^,],%[^,],%[^,],%[^,],%d,%d,%lf,%[^,],%lf,", 
                            movie.name, movie.category_1, movie.category_2, 
                            movie.movie_language, &movie.age_range, 
                            &movie.group_size, &movie.rating, movie.link, &movie.score);
        
        if (result != 9) {
            printf("Something went wrong while trying to read the dataset %d result %d\n", i, result);
            exit(EXIT_FAILURE); 
        }
        movies[i] = movie;
    }
}

int survey(movie movies[], int length, char *genre1, char *genre2, char *genre3, char *sprog, int *age, int *group) {
    // Introduktion til programmet
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*                   Welcome!                   *\n");
    printf("*                                              *\n");
    printf("*   This program helps you find a good movie   *\n");
    printf("*   based on your current preferences.         *\n");
    printf("*                                              *\n");
    printf("*   You will be asked to choose                *\n");
    printf("*   - Genre (Action, Comedy, Drama, etc)       *\n");
    printf("*   - Language (English, Danish)               *\n");
    printf("*   - Your age                                 *\n");
    printf("*   - Group size                               *\n");
    printf("*                                              *\n");
    printf("************************************************\n\n");

    printf("Let's begin!\n");

    // Validering af genre
    int valid_genre1 = 0,
        valid_genre2 = 0,
        valid_genre3 = 0;
    while (!valid_genre1) {
        printf("Write your three favorite genres here (Action, Comedy, Crime, Drama, Thriller, Horror, Sci-fi, Romance, Fantasy, Animated, Family, Horror, Mystery):\n");
        scanf("%s", genre1);
         for (int i = 0; genre1[i]; i++) {
        genre1[i] = tolower(genre1[i]);
         }

        if (strcmp(genre1, "action") == 0 ||
            strcmp(genre1, "comedy") == 0 ||
            strcmp(genre1, "crime") == 0 ||
            strcmp(genre1, "drama") == 0 ||
            strcmp(genre1, "thriller") == 0 ||
            strcmp(genre1, "sci-fi") == 0 ||
            strcmp(genre1, "romance") == 0 ||
            strcmp(genre1, "fantasy") == 0 ||
            strcmp(genre1, "animated") == 0 ||
            strcmp(genre1, "adventure") == 0||
            strcmp(genre1, "family") == 0 ||
            strcmp(genre1, "horror") == 0 ||
            strcmp(genre1, "mystery") == 0 ) {
            valid_genre1 = 1;
            
        } else {
            printf("The input wasn't a valid genre, please try again:\n");
        }
    }

    while (!valid_genre2) {
        scanf("%s", genre2);
         for (int i = 0; genre2[i]; i++) {
        genre2[i] = tolower(genre2[i]);
         }

        if (strcmp(genre2, "action") == 0 ||
            strcmp(genre2, "comedy") == 0 ||
            strcmp(genre2, "crime") == 0 ||
            strcmp(genre2, "drama") == 0 ||
            strcmp(genre2, "thriller") == 0 ||
            strcmp(genre2, "sci-fi") == 0 ||
            strcmp(genre2, "romance") == 0 ||
            strcmp(genre2, "animated") == 0 ||
            strcmp(genre2, "adventure") == 0||
            strcmp(genre2, "fantasy") == 0 ||
            strcmp(genre2, "family") == 0 ||
            strcmp(genre2, "horror") == 0 ||
            strcmp(genre2, "mystery") == 0 ) {
            valid_genre2 = 1;
            
        } else {
            printf("The input wasn't a valid genre, please try again:\n");
        }
    }

    while (!valid_genre3) {
        scanf("%s", genre3);
         for (int i = 0; genre3[i]; i++) {
         genre3[i] = tolower(genre3[i]);
         }
        if (strcmp(genre3, "action") == 0 ||
            strcmp(genre3, "comedy") == 0 ||
            strcmp(genre3, "crime") == 0 ||
            strcmp(genre3, "drama") == 0 ||
            strcmp(genre3, "thriller") == 0 ||
            strcmp(genre3, "sci-fi") == 0 ||
            strcmp(genre3, "romance") == 0 ||
            strcmp(genre3, "animated") == 0 ||
            strcmp(genre3, "adventure") == 0||
            strcmp(genre3, "fantasy") == 0 ||
            strcmp(genre3, "family") == 0 ||
            strcmp(genre3, "horror") == 0 ||
            strcmp(genre3, "mystery") == 0 ) {
            valid_genre3 = 1;
            system(CLEAR);
        } else {
            printf("The input wasn't a valid genre, please try again:\n");
        }
    }

    // Validering af sprog
    int valid_sprog = 0;
    while (!valid_sprog) {
        printf("Input your prefered language (English, Danish): ");
        scanf("%s", sprog);
         for (int i = 0; sprog[i]; i++) {
        sprog[i] = tolower(sprog[i]);
        }

        if (strcmp(sprog, "english") == 0 ||
            strcmp(sprog, "danish") == 0) {
            valid_sprog = 1;
            system(CLEAR);
        } else {
            printf("The input wasn't a valid language, please try again:\n");
        }
    }

    // Validering af age
    int valid_age = 0;
    while (!valid_age) {
        printf("Input your age: ");
        scanf("%d", age);

        if (*age > 0 && *age < 120) { // age skal være realistisk
            valid_age = 1;
            system(CLEAR);
        } else {
            printf("Invalid age input, age input must be between 1-120.\n");
        }
    }

    // Validering af antal group
    int valid_group = 0;
    while (!valid_group) {
        printf("How many people are watching? (1 = alone, 2 = partner, 3 = family): ");
        scanf("%d", group);

        if (*group >= 1 && *group <= 3) { // Skal være mellem 1 og 3
            valid_group = 1;
            system(CLEAR);
        } else {
            printf("Invalid group size. Input 1, 2 or 3.\n");
        }
    }

    system(CLEAR);

    return 0;
}


void recommendation(movie movies[], char *genre1, char *genre2, char *genre3, char *sprog, int age, int group, double rating, int length) {
    for (int i = 0; i < length; i++) {
        int genre1match = 0,
            genre2match = 0,
            persontalmatch = 0;
        double rating = movies[i].rating;

        if (strcmp(movies[i].movie_language, sprog) == 0 || age > movies[i].age_range){
            if (strcmp(movies[i].category_1, genre1) == 0 || strcmp(movies[i].category_1, genre2) == 0 || strcmp(movies[i].category_1, genre3) == 0)
            genre1match = 10;

            if (strcmp(movies[i].category_2, genre1) == 0 || strcmp(movies[i].category_2, genre2) == 0 || strcmp(movies[i].category_2, genre3) == 0)
            genre2match = 5;

            if (movies[i].group_size == group)
            persontalmatch = 5;
        }
         
        movies[i].score = genre1match + genre2match + persontalmatch + (rating / 2);
    }

    qsort(movies, length, sizeof(movie), comparescores);

}

int comparescores(const void *a, const void *b) {
    if (((movie*)b)->score == ((movie*)a)->score)
        return 0;
    else if(((movie*)b)->score > ((movie*)a)->score)
        return 1;
    else
        return -1;
  
}

 // return ((movie*)a)->score - ((movie*)b)->score;

void battle_function (movie movies[]){
    int ready_check, kept_movie;
    movie battle_array[2];
    strcpy(battle_array[0].name, movies[0].name); 
    strcpy(battle_array[1].name, movies[1].name); 

    printf("Welcome to our battlepicker!\n\n");
    printf("We will present you two movies, with a link to their trailers, and you then the one want to keep.\n");
    printf("Just write 1 or 2 to pick the movie.");
    printf("You will then have to choose between your first selection and a new option. This process repeats a couple of times. \n\n");
    printf("If you understand the rules, type 1.\n\n");

    while (ready_check != 1){ 
        scanf(" %d",&ready_check);
        if (ready_check != 1){
            printf("Invalid input, did you read the rules? \n");
            printf("Please try again.\n\n");
        }
    }
    printf("Let's begin!\n\n");

   
    int j = 2;
    for (int i = 0; i < 5; i++){
        kept_movie=0;
        system(CLEAR);
        printf("Movie nr 1: %s\n Trailer: %s \n\n",battle_array[0].name, battle_array[0].link);
        printf("Movie nr 2: %s\n Trailer: %s \n\n",battle_array[1].name, battle_array[1].link);
        printf("Which movie do you prefer? (type 1 / 2)\n");
        while (kept_movie != 1 && kept_movie != 2 ){
            scanf(" %d", &kept_movie);
            

            if(kept_movie == 1){
               printf("Nice choice!\n");
               strcpy(battle_array[1].name, movies[j].name);
            }else if (kept_movie == 2){
               printf("Nice choice!\n");
               strcpy(battle_array[0].name, movies[j].name);
            }else printf("Invalid input. Please try again.\n");
        
        }
        j++;
    }
    system(CLEAR);
    printf("Your chosen movie is: %s\n\n", battle_array[kept_movie-1].name);

    

}