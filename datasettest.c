#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOVIE_ARRAY_SIZE 50
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