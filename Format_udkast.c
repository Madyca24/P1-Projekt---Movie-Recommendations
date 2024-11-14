#include <stdio.h>
#define MAX_ARRAY_LENGTH 2
#define MAX_CHAR_LENGTH 50 

typedef enum {
    ACTION,
    COMEDY,
    DRAMA,
    HORROR,
    THRILLER,
    SCI_FI,
    ROMANCE,
    FANTASY,
    ANIMATED
} Genre;
/*
typedef enum {
    ACTION   = 1 << 0,  // 0001
    COMEDY   = 1 << 1,  // 0010
    DRAMA    = 1 << 2,  // 0100
    HORROR   = 1 << 3,  // 1000
    THRILLER = 1 << 4   // 10000
} Genre;

film {"Inception", ACTION|THRILLER|SCI_FI,3, {Scared}, 2010, English, 8.8}
*/
typedef enum {
    Sad,
    Happy,
    Angry,
    Tired,
    Scared
} Mood;

typedef enum {
    English,
    Danish,
} Sprog;
// måske tilføje en int til antallet af genres/moods i et specefik film fx numGenres? 
typedef struct {
    char titel[MAX_CHAR_LENGTH];      
    Genre genres[MAX_ARRAY_LENGTH];  
    int numGenres     
    int mood;              
    int udgivelsesTid;
    int sprog;   
    float rating;        
} Film;

int main(){
    Film alleFilm[] = {
        {"Inception", {ACTION, THRILLER, SCI_FI},3,Scared, 2010, English, 8.8},
        {"Forrest Gump", {DRAMA, COMEDY},2 , Happy, 1994, English, 8.8},
        {"The Shining", {HORROR, THRILLER},2, Angry, 1980, English, 8.4},
        {"Toy Story", {COMEDY, ANIMATED},2, Happy, 1995, English, 8.3},
        {"The Matrix", {ACTION, THRILLER, SCI_FI},3, Tired, 1999, English, 8.7},
        {"Titanic", {ROMANCE, DRAMA},2, Sad, 1997, English, 7.8},
        {"Harry Potter", {FANTASY, ACTION},2, Happy, 2001, English, 7.6},
        {"Frozen", {ANIMATED, FANTASY},2, Happy, 2013, Danish, 7.5}
    };