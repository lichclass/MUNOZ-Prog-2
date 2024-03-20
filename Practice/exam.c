#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Required for memory allocation functions
#include <string.h>

#define MAX_STUDENTS 5
#define STRING_LENGTH 20

typedef char String[STRING_LENGTH];

typedef struct {
    String fname, mname, lname;
} Name;

typedef struct {
    int month, day, year;
} Date;

typedef struct {
    String id;
    Name stud_name;
    int age;
    bool gender;
    Date date_birth;
} StudInfo;

typedef struct {
    StudInfo *class; // Change class to a pointer
    int ctr;
    int max;
} ClassList, *ClassListPtr;

void display(ClassList list) {
    for (int i = 0; i < list.ctr; i++) {
        printf("%-20s %-20s %-20s", list.class[i].stud_name.fname, list.class[i].stud_name.mname, list.class[i].stud_name.lname);
        printf("%-20s %-10d %-10s \t(%d, %d, %d)\n", list.class[i].id, list.class[i].age, (list.class[i].gender) ? "Male" : "Female", list.class[i].date_birth.day, list.class[i].date_birth.month, list.class[i].date_birth.year);
    }
}

int main() {
    ClassList testCS;
    ClassList xVar;

    // Dynamically allocate memory for testCS.class
    testCS.class = malloc(MAX_STUDENTS * sizeof(StudInfo)); 

    if (testCS.class == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Return error code
    }

    // Populate testCS.class with student data
    testCS.class[0] = (StudInfo){"21700005", {"Nash", "Adam", "Munoz"}, 20, true, {1, 10, 2004}};
    testCS.class[1] = (StudInfo){"21800005", {"Anna", "De", "Lima"}, 20, false, {2, 10, 2004}};
    testCS.class[2] = (StudInfo){"21900005", {"Calm", "Dean", "Jones"}, 21, true, {3, 10, 2003}};
    testCS.class[3] = (StudInfo){"22000005", {"Lilly", "Smith", "Jackson"}, 19, false, {4, 10, 2002}};
    testCS.ctr = 4; // Adjusted to the number of students populated
    testCS.max = MAX_STUDENTS;

    display(testCS);

    // Dynamically allocate memory for xVar.class
    xVar.class = malloc((testCS.ctr / 2) * sizeof(StudInfo)); 

    if (xVar.class == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(testCS.class); // Free memory allocated for testCS.class
        return 1; // Return error code
    }

    // Copy data from testCS.class to xVar.class
    memcpy(xVar.class, testCS.class + (testCS.ctr / 2), (testCS.ctr / 2) * sizeof(StudInfo));
    xVar.ctr = testCS.ctr / 2;
    xVar.max = MAX_STUDENTS;

    printf("\n");
    display(xVar);
    
    // Free dynamically allocated memory for testCS.class and xVar.class
    free(testCS.class);
    free(xVar.class);

    return 0;
}