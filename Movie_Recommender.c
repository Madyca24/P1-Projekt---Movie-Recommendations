#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#ifdef _WIN32
    #define CLEAR "cls"
    #define OPEN_CMD "start"
#elif __APPLE__
    #define OPEN_CMD "open"
    #define CLEAR "clear"
#else
    #define CLEAR "clear"
    #define OPEN_CMD "xdg-open"
#endif

#define MOVIE_ARRAY_SIZE 50
#define MAX_MOVIE_NAME_LENGTH 40
#define MAX_CATEGORY_LENGTH 10
#define MAX_LANGUAGE_LENGTH 8
#define MAX_LINK_LENGTH 100
#define BATTLE_ARRAY_ROUNDS 5
// structs setup

typedef struct {
    char name[MAX_MOVIE_NAME_LENGTH];
    char category_1[MAX_CATEGORY_LENGTH];
    char category_2[MAX_CATEGORY_LENGTH];
    char movie_language[MAX_LANGUAGE_LENGTH];
    int age_range;
    int group_size;
    double rating;
    char link[MAX_LINK_LENGTH];
    double score;
} movie;

typedef struct {
    char genre1[MAX_CATEGORY_LENGTH];
    char genre2[MAX_CATEGORY_LENGTH];
    char genre3[MAX_CATEGORY_LENGTH];
    char language[MAX_LANGUAGE_LENGTH];
    int age;
    int groupsize;
} userprofile;

void read_file(FILE *f1, int length, movie movies[]);
int survey(movie movies[], userprofile *user, int length);
void get_valid_genre(char *genre_variable);
int comparescores(const void* a, const void* b);
void recommendation(movie movies[], userprofile user, int length);
void battle_function (movie movies[]);
void open_trailer(const char* url);

int main(void) {
    movie movies[MOVIE_ARRAY_SIZE];
    userprofile user = {"","","","",0,0 };

    FILE *f1 = fopen("Movie_dataset.txt", "r");
    if (f1 == NULL) {
        printf("The file couldn't open!\n");
        exit(1);
    }

    read_file(f1, MOVIE_ARRAY_SIZE, movies);
    fclose(f1);
    survey(movies, &user, MOVIE_ARRAY_SIZE);
    recommendation(movies, user, MOVIE_ARRAY_SIZE);
    battle_function(movies);

    return 0;
}
void read_file(FILE *f1, int length, movie movies[]) {
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

int survey(movie movies[], userprofile *user, int length) {
    // Introduction to the program
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

    // Validates genre
    printf("Write your three favorite genres here (Action, Comedy, Crime, Drama, Thriller, Horror, Sci-fi, Romance, Fantasy, Animated, Family, Horror, Mystery):\n");
    get_valid_genre(user->genre1);
    get_valid_genre(user->genre2);
    get_valid_genre(user->genre3);
    system(CLEAR);

    // Validates language
    int valid_language = 0;
    while (!valid_language) {
        printf("Input your prefered language (English, Danish): ");
        scanf("%s", user->language);
         for (int i = 0; user->language[i]; i++) {
        user->language[i] = tolower(user->language[i]);
        }

        if (strcmp(user->language, "english") == 0 ||
            strcmp(user->language, "danish") == 0) {
            valid_language = 1;
            system(CLEAR);
        } else {
            printf("The input wasn't a valid language. Please try again:\n");
        }
    }

    // Validates age
    int valid_age = 0;
    while (!valid_age) {
        printf("Input your age: ");
        if (scanf("%d", &user->age) == 1) {
            if (user->age > 0 && user->age < 120) { // Age must be realistic
                valid_age = 1;
                system(CLEAR);
            } else {
                printf("Invalid age input. Age must be between 1-120.\n");
            }
        } else {
            while ((getchar()) != '\n'); // Clear buffer
        }
    }

    // Validates groupsize
    int valid_group = 0;
    while (!valid_group) {
        printf("How many people are watching? (1 = alone, 2 = partner, 3 = family): ");
        if (scanf("%d", &user->groupsize) == 1) {
            if (user->groupsize >= 1 && user->groupsize <= 3) { 
                valid_group = 1;
                system(CLEAR);
            } else {
                printf("Invalid groupsize. Input must be 1, 2 or 3.\n");
            }
        } else {
            while ((getchar()) != '\n'); // Clear buffer
        }
    }
        system(CLEAR);

        return 0;
}

void get_valid_genre(char *genre_variable) {
    char input[MAX_CATEGORY_LENGTH];
    int valid = 0;
    const char *valid_genres[] = {
        "action", "comedy", "crime", "drama", "thriller",
        "sci-fi", "romance", "fantasy", "animated", "adventure",
        "family", "horror", "mystery"
    };
    int num_valid_genres = sizeof(valid_genres) / sizeof(valid_genres[0]);

    while (!valid) {
        scanf("%s", input);
        for (int i = 0; input[i]; i++) {
            input[i] = tolower(input[i]);
        }
        for (int i = 0; i < num_valid_genres; i++) {
            if (strcmp(input, valid_genres[i]) == 0) {
                valid = 1;
                break;
            }
        }
        if (!valid) {
            printf("The input wasn't a valid genre. Please try again:\n");
        }
    }
    strcpy(genre_variable, input);
}


void recommendation(movie movies[], userprofile user, int length) {
    for (int i = 0; i < length; i++) {
        int genre1match = 0,
            genre2match = 0,
            persontalmatch = 0;
        double rating = movies[i].rating;

        if (strcmp(movies[i].movie_language, user.language) == 0 || user.age > movies[i].age_range){
            if (strcmp(movies[i].category_1, user.genre1) == 0 || strcmp(movies[i].category_1, user.genre2) == 0 || strcmp(movies[i].category_1, user.genre3) == 0)
            genre1match = 10;

            if (strcmp(movies[i].category_2, user.genre1) == 0 || strcmp(movies[i].category_2, user.genre2) == 0 || strcmp(movies[i].category_2, user.genre3) == 0)
            genre2match = 5;

            if (movies[i].group_size == user.groupsize)
            persontalmatch = 5;
        }
         
        movies[i].score = genre1match + genre2match + persontalmatch + (rating / 2);
    }

    qsort(movies, length, sizeof(movie), comparescores);

}

int comparescores(const void *a, const void *b) {
    movie *movie_a = (movie*)a;
    movie *movie_b = (movie*)b;
    if (movie_b->score == movie_a->score)
        return 0;
    else if(movie_b->score > movie_a->score)
        return 1;
    else
        return -1;
  
}

void battle_function (movie movies[]){
    int ready_check, kept_movie;
    movie battle_array[2];
    strcpy(battle_array[0].name, movies[0].name); 
    strcpy(battle_array[1].name, movies[1].name); 
     strcpy(battle_array[0].link, movies[0].link); 
    strcpy(battle_array[1].link, movies[1].link); 

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
    for (int i = 0; i < BATTLE_ARRAY_ROUNDS; i++){
        kept_movie=0;
        system(CLEAR);
        printf("Movie nr 1: %s\n Trailer: %s \n\n",battle_array[0].name, battle_array[0].link);
        printf("Movie nr 2: %s\n Trailer: %s \n\n",battle_array[1].name, battle_array[1].link);

        printf("Would you like to watch trailers? (0 to skip, 1 for movie 1, 2 for movie 2, 3 for both): ");
        int trailer_choice;
        scanf("%d", &trailer_choice);
        
        if(trailer_choice == 1) open_trailer(battle_array[0].link);
        if(trailer_choice == 2) open_trailer(battle_array[1].link);
        if(trailer_choice == 3) {
            open_trailer(battle_array[0].link);
            open_trailer(battle_array[1].link);
        }

        printf("Which movie do you prefer? (type 1 / 2)\n");
        while (kept_movie != 1 && kept_movie != 2 ){
            scanf(" %d", &kept_movie);
            

            if(kept_movie == 1){
               printf("Nice choice!\n");
               strcpy(battle_array[1].name, movies[j++].name);
               strcpy(battle_array[1].link, movies[j-1].link); 
            }else if (kept_movie == 2){
               printf("Nice choice!\n");
               strcpy(battle_array[0].name, movies[j++].name);
               strcpy(battle_array[0].link, movies[j-1].link);  
            }else printf("Invalid input. Please try again.\n");
        }
    }
    system(CLEAR);
    printf("Your chosen movie is: %s\n\n", battle_array[kept_movie-1].name);

}

void open_trailer(const char* url) {
    char command[80];
    sprintf(command, "%s %s", OPEN_CMD, url);
    system(command);
}
