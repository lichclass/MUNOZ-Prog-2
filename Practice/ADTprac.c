#include <stdio.h>
#define MAX 50

typedef struct {
    char *LName;
    char *FName;
    char MI;
} Name;

typedef struct {
    Name person[MAX];
    int count;
} Namelist;

// Insertion
void insert(Namelist *l, Name new){
    if(l->count < MAX){
        l->person[l->count++] = new;
    }
}

// Deletion
void delete(Namelist *l, Name delName){
    int i, tobreak = 0;
    for(i = 0; i < l->count && tobreak == 0; i++){
        
        // Member Existence Checking
        if(strcmp(delName.LName, l->person[i].LName) == 0 &&
           strcmp(delName.FName, l->person[i].FName) == 0 &&
           delName.MI == l->person[i].MI){

            int j;
            for(j = i; j < l->count - 1; j++){
                l->person[j] = l->person[j + 1];
            }
            
            l->count--;
            tobreak = 1;
           }

    }
    if(i == l->count){
        printf("Person not Found!");
    }
}

// Traversal
void display(Namelist *l){
    int i;
    for(i = 0; i < l->count; i++){
        printf("Person %d: %s, %s %c\n", i + 1, l->person[i].LName, l->person[i].FName, l->person[i].MI);
    }
}

int main(){
    Namelist people = {
        {
         {"Munoz", "Nash", 'G'},
         {"Smith", "John", 'D'},
         {"Doe", "Jane", 'S'},
         {"Garcia", "Maria", 'L'},
         {"Brown", "David", 'R'},
         {"Taylor", "Emily", 'M'},
         {"Johnson", "Michael", 'K'},
         {"Williams", "Jessica", 'N'},
         {"Jones", "Christopher", 'P'},
         {"Davis", "Ashley", 'Q'}
        },
        10
    };

    Name newPers = {"Kim", "Chaewon", 'G'};

    printf("\nBEFORE INSERTION\n");
    display(&people);

    // Inserting Kim Chaewon
    insert(&people, newPers);

    printf("\nAFTER INSERTION\n");
    display(&people);

    printf("\nDELETION\n");
    Name todelete = {"Garcia", "Maria", 'L'};
    delete(&people, todelete);
    display(&people);
    
    return 0;
}