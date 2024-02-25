#ifndef EXERCISEFUNC_H
#define EXERCISEFUNC_H

#define SIZE 50

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
} Nametype;

typedef struct {
    Nametype name;
    unsigned int ID;
    char Course[8];
    int YrLevel;
} Studtype;

typedef struct {
    Studtype Stud[SIZE];
    int count;
} Studlist;

/* Function prototypes */
Studtype getData();
void displayStudent(Studtype stud);
void displayList(Studlist *record);
void initializeList(Studlist *record);
void populateList(Studlist *record, int n);
int findElem(Studlist *record, unsigned int findID);
void addStudent(Studlist *record, Studtype student);
void insertFirst_VerOne(Studlist *record, Studtype student);
void insertFirst_VerTwo(Studlist *record, Studtype student);
void deleteStudent(Studlist *record, unsigned int delID);
void sortList(Studlist *record);
void insertSorted(Studlist *record, Studtype student);

#endif