#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
    char fName[20];
    char lName[20];
} name;

typedef struct {
    char subjectName[20];
    int grade;
} subjectGrade;

typedef struct {
    int idNum;
    name studentName;
    char course[10];
    subjectGrade studentGrade[3];
} studentInfo;

typedef struct {
    studentInfo *studentList;
    int count;
} classRecord;

typedef struct {
    classRecord classList;
    classRecord passersList;
} teacherRecord;

void populate(teacherRecord *record){

    record->classList.studentList = (studentInfo*) malloc(MAX * sizeof(studentInfo));
    record->passersList.studentList = (studentInfo*) malloc(MAX * sizeof(studentInfo));

    studentInfo students[] = {
        {11111111, {"Collins", "Abraham"}, "BSCS", {{"Prog", 65}, {"DSII", 75}, {"Networking", 70}}},
        {22222222, {"John", "Doe"}, "BSIT", {{"Web Development", 80}, {"Database Management", 85}, {"System Analysis", 78}}},
        {33333333, {"Jane", "Smith"}, "BSCS", {{"Algorithm", 90}, {"Software Engineering", 88}, {"Operating Systems", 82}}},
        {44444444, {"Alice", "Johnson"}, "BBA", {{"Accounting", 75}, {"Marketing", 82}, {"Business Ethics", 80}}},
        {55555555, {"Michael", "Williams"}, "BSEE", {{"Circuit Analysis", 88}, {"Digital Electronics", 90}, {"Electromagnetics", 85}}}
    };

    int count = sizeof(students) / sizeof(students[0]);

    memcpy(record->classList.studentList, students, count * sizeof(studentInfo));
    record->classList.count = count;
    record->passersList.count = 0;
}

void congrats_passers(teacherRecord *record){

    // Storing
    int i, ave;
    for(i = 0; i < record->classList.count; i++){
        ave = (record->classList.studentList[i].studentGrade[0].grade + record->classList.studentList[i].studentGrade[1].grade + record->classList.studentList[i].studentGrade[2].grade) / 3;
        if(ave >= 80){
            record->passersList.studentList[record->passersList.count++] = record->classList.studentList[i];
        }
    }

    // Sorting
    int j, trav_ave;
    for(i = 1; i < record->passersList.count - 1; i++){
        studentInfo key = record->passersList.studentList[i];
        int key_ave = (key.studentGrade[0].grade + key.studentGrade[1].grade + key.studentGrade[2].grade) / 3;
        for(j = i - 1; j >= 0; j--){
            trav_ave = (record->passersList.studentList[j].studentGrade[0].grade + record->passersList.studentList[j].studentGrade[1].grade + record->passersList.studentList[j].studentGrade[2].grade) / 3;
            if(trav_ave < key_ave) break;
            record->passersList.studentList[j + 1] = record->passersList.studentList[j];
        }
        record->passersList.studentList[j + 1] = key;
    }

}

void printWholeRecord(teacherRecord *tRecord) {
    printf("Class List:\n");
    for (int i = 0; i < tRecord->classList.count; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID Number: %d\n", tRecord->classList.studentList[i].idNum);
        printf("Name: %s %s\n", tRecord->classList.studentList[i].studentName.fName, tRecord->classList.studentList[i].studentName.lName);
        printf("Course: %s\n", tRecord->classList.studentList[i].course);
        printf("Grades:\n");
        for (int j = 0; j < 3; j++) {
            printf("Subject %d: %s, Grade: %d\n", j + 1, tRecord->classList.studentList[i].studentGrade[j].subjectName, tRecord->classList.studentList[i].studentGrade[j].grade);
        }
        printf("\n");
    }
}

int main(){
    teacherRecord myClass;
    populate(&myClass);
    congrats_passers(&myClass);
    //printf("test");
    printWholeRecord(myClass);
}