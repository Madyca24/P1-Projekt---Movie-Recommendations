#include <stdio.h>
#define MAX_ARRAY_LENGTH 
int main(void){

    //Tager alle filmene med det valgte sprog og lægger det i et nyt array
    language_seperator();
    

    //tager alle filmene fra det array med det 
    //valgte sprog og lægger alle film man er gammel nok til at se i et nyt array
    //Hvis man er over 18 kan den kopire arrayet direkte over
    age_restriction_seperator();


    //Hvis de en af de resterende film indeholder en kategori du har valgt bliver der føjet et point
    //Kategori 1 kan give 2 point og kategori 2 kan give 1 point. derudover kan man få et point hvis 
    //filmen passer til den gruppestørrelse du er
    recomendation_point_system();

    
    
    
    
    return 0;
}


void language_seperator(){
    int j = 0;
    for (int i= 0; i < MAX_ARRAY_LENGTH; i++){
        if(movies[i].name == valgte_sprog){
            sorteret_sprog_array[j] = movies[i];
            j++;
        }
    }
}

 void age_restriction_seperator(){
    int j = 0;
    if (valgte_alder < 18){
        for (int i= 0; i < MAX_ARRAY_LENGTH; i++){
        
            if(sorteret_sprog_array[i].age_restriction =< valgte_alder){
                sorteret_sprog_og_alder_array[j] = sorteret_sprog_array[i];
                j++;
            }
        }
    }else if (valgte_alder >= 18){
        for (int i = 0; i < MAX_ARRAY_LENGTH; i++)
        sorteret_sprog_og_alder_array[i] = sorteret_sprog_array[i];
    }
 }


 //alternertivt kunne man bare når vi udlevere point give scoren ganger med 0
 // ved de film som ikke har det rette sprog. Det samme sker hvis man ikke er gammel nok

 //int sprogalder = 1
 //if(user.sprog != film.sprog || user.alder < film.minalder){
 //   sprogalder = 0

 // til sidst ganges den færdigescore med sprogalder, så hvis filmen ikke overholder begge bliver den sat til 0