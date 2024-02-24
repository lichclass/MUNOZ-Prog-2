#include <stdio.h>
#include <string.h>
#include "exerciseFunc.h"
#define SIZE 50



/*
======================================================================
FUNCTION    : Studtype getData();
DESCRIPTION : Takes the input for all the student information
ARGUMENTS   : void
RETURNS     : void
======================================================================
*/
Studtype getData(){

    Studtype student;

    /* Input for Last Name */
    fflush(stdin);
    printf("Enter Last Name: ");
    scanf("%[^\n]s", student.name.LName);

    /* Input for First Name */
    fflush(stdin);
    printf("Enter First Name: ");
    scanf("%[^\n]s", student.name.FName);

    /* Input for Middle Initial */
    fflush(stdin);
    printf("Enter Middle Initial: ");
    scanf("%c", &student.name.MI);

    /* Input for ID */
    fflush(stdin);
    printf("Enter ID: ");
    scanf("%u", &student.ID);

    /* Input for Course */
    fflush(stdin);
    printf("Enter Course: ");
    scanf("%s", student.Course);

    /* Input for Year Level */
    fflush(stdin);
    printf("Enter Year Level: ");
    scanf("%d", &student.YrLevel);

    return student;
}



/*
======================================================================
FUNCTION    : void displayStudent(Studtype stud);
DESCRIPTION : Displays student information
ARGUMENTS   : Studtype stud
RETURNS     : void
======================================================================
*/
void displayStudent(Studtype stud){
    
    /* Displays the Information of the student */
    printf("\n-----Displaying Student Information-----");
    printf("\nName\t\t: %s, %s %c.", stud.name.LName, stud.name.FName, stud.name.MI);
    printf("\nStudent ID\t: %u", stud.ID);
    printf("\nCourse\t\t: %s", stud.Course);
    printf("\nYear Level\t: %d", stud.YrLevel);

}



/*
======================================================================
FUNCTION    : void displayList(Studlist *record);
DESCRIPTION : Displays the list of recorded student information
ARGUMENTS   : Studlist *record
RETURNS     : void
======================================================================
*/
void displayList(Studlist *record){

    int i;
    char name[SIZE];
    /* Heading for the student list */
    printf("%-45s%-15s%-15s%-10s", "-Name-", "-ID-", "-Couse-", "-Year Level-");
    for(i = 0; i < record->count; i++){
        /* Combines all names into a single string variable */
        sprintf(name, "%s, %s %c.", record->Stud[i].name.LName, record->Stud[i].name.FName, record->Stud[i].name.MI);
        printf("\n%-45s", name);
        printf("%-15u", record->Stud[i].ID);
        printf("%-15s", record->Stud[i].Course);
        printf("%-10d", record->Stud[i].YrLevel);
    }
    printf("\n");

}



/*
======================================================================
FUNCTION    : void initializeList(Studlist *record);
DESCRIPTION : makes the list empty
ARGUMENTS   : Studlist *record
RETURNS     : void
======================================================================
*/
void initializeList(Studlist *record){

    /* Empties the list while maintaining the old data */
    record->count = 0;
}



/*
======================================================================
FUNCTION    : void populateList(Studlist *record, int n);
DESCRIPTION : put N elements in an initially empty list
ARGUMENTS   : Studlist *record, int n
RETURNS     : void
======================================================================
*/
void populateList(Studlist *record, int n){

    /* Populates the list */
    record->count += n;
}


/*
======================================================================
FUNCTION    : int findElem(Studlist *record, unsigned int findID);
DESCRIPTION : finds the given ID in a list
ARGUMENTS   : Studlist *record, int n
RETURNS     : index - if FOUND, -1 - if NOT FOUND
======================================================================
*/
int findElem(Studlist *record, unsigned int findID){
    int i;
    /* Breaks the loop if the ID is found */
    for(i = 0; i < record->count && findID != record->Stud[i].ID; i++){}
    return (i < record->count) ? i : -1;
}



/*
======================================================================
FUNCTION    : void addStudent(Studlist *record, Studtype student);
DESCRIPTION : adds a student record at the end of the list, if there 
              is still space.
ARGUMENTS   : Studlist *record, Studtype student
RETURNS     : void
======================================================================
*/
void addStudent(Studlist *record, Studtype student){
    if(record->count == SIZE){
        printf("No space available!");
    }
    else {
        /* Inserts the student at the end then increments the list */
        record->Stud[record->count++] = student;
    }
}

/* CHALLENGE: FUNCTION DEFINITIONS */

/*
======================================================================
FUNCTION    : void insertFirst_VerOne(Studlist *record, Studtype student);
DESCRIPTION : inserts a student record at the index 0 of the given list
ARGUMENTS   : Studlist *record, Studtype student
RETURNS     : void
======================================================================
*/
void insertFirst_VerOne(Studlist *record, Studtype student){
    if(record->count == SIZE){
        printf("No space available!");
    }
    else {
        int i;
        for(i = record->count - 1; i >= 0; i--){
            record->Stud[i + 1] = record->Stud[i];
        }
        record->Stud[0] = student;
        record->count++;
    }
}



/*
======================================================================
FUNCTION    : void insertFirst_VerTwo(Studlist *record, Studtype student);
DESCRIPTION : inserts a student record at the index 0 of the given list, using memcpy
ARGUMENTS   : Studlist *record, Studtype student
RETURNS     : void
======================================================================
*/
void insertFirst_VerTwo(Studlist *record, Studtype student){
    if(record->count == SIZE){
        printf("No space available!");
    }
    else {
        int i;
        for(i = record->count - 1; i >= 0; i--){
            memcpy(&record->Stud[i + 1], &record->Stud[i], sizeof(Studtype));
        }
        memcpy(&record->Stud[0], &student, sizeof(Studtype));
        record->count++;
    }
}



/*
======================================================================
FUNCTION    : void deleteStudent(Studlist *record, unsigned int delID);
DESCRIPTION : wil find and remove a student record bearing the given
              ID from the list.
ARGUMENTS   : Studlist *record, unsigned int delID
RETURNS     : void
======================================================================
*/
void deleteStudent(Studlist *record, unsigned int delID){
    int ndx = findElem(record, delID);
    if(ndx != -1){
        int i;
        for(i = ndx; i < record->count - 1; i++){
            record->Stud[i] = record->Stud[i + 1];
        }
        record->count--;
    }
    else {
        printf("\nStudent not found");
    }
}



/*
======================================================================
FUNCTION    : void SortList(Studlist *record);
DESCRIPTION : sorts the given list in ascending order according to 
              ID student information
ARGUMENTS   : Studlist *record
RETURNS     : void
======================================================================
*/
void sortList(Studlist *record){
    
    int i, j;
    Studtype key;
    for(i = 1; i < record->count; i++){
        key = record->Stud[i];
        
        for(j = i - 1; j >= 0 && record->Stud[j].ID > key.ID; j--){
            record->Stud[j + 1] = record->Stud[j];
        }
        record->Stud[j + 1] = key;
    }

}



/*
======================================================================
FUNCTION    : void insertSorted(Studlist *record, Studtype student);
DESCRIPTION : insert a new student record in its proper position in a 
              given SORTED list
ARGUMENTS   : Studlist *record, Studtype student
RETURNS     : void
======================================================================
*/
void insertSorted(Studlist *record, Studtype student){

    addStudent(record, student);
    sortList(record);

}
