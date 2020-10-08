#include <stdio.h>
#include <string.h>

const int MAX_PEOPLE = 10;

typedef struct 
{
    char* name;
    char* number;
}
person;


int main(void) 
{
    printf("I am here");    
    person people[MAX_PEOPLE];
    people[0].name = "Ahmed";
    people[0].number = "+1-617-495-1000";

    people[1].name = "Meshref";
    people[1].number = "+1-949-468-2750";
    for (int i = 0; i < 2; i++) {
        if (strcasecmp(people[i].name, "Meshref") == 0) {
            printf("Found: %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

