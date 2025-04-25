#include <stdio.h>
#include <math.h>

void hours_minutes_seconds(int Input, int *Hour, int *Minute, int *Second);

int main(void) {

    int Input, Minute, Hour, Second;

    printf("Enter the number of seconds:\n ");
    scanf("%d", &Input);
    
    hours_minutes_seconds(Input, &Hour, & Minute, &Second);

    printf("Hours: %d\n", Hour);
    printf("Minutes: %d\n", Minute);
    printf("Seconds: %d\n", Second);
    return 0;
}

void hours_minutes_seconds(int Input, int *Hour, int *Minute, int *Second){
    
    int rest = 0;

    *Hour = Input / 3600;

    rest = Input % 3600;

    *Minute = rest % 3600 / 60;

    *Second = rest % 60;

}