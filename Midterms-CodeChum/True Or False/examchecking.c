/*
=================================================
NAME: CODE FOR SCHOOL EXAM
NOTE: Without the header files etc.
DATE: APRIL 11, 2024
=================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "display.h"
#define MAX 10


void populate(classRecord *,int);
void checkExams(char[],classRecord*);


int main(){
    char answerKey[]="TTTFFTTFTF";
    classRecord examRecords;
    int classCount;
    examRecords.count=0;

    printf("How many students in the class? ");
    //Input for class count
    scanf("%d", &classCount);

    //Write code to only allow a class of more than 0
    if(classCount <= 0){
        printf("Class count has to be greater than 0");
        return 0;
    }

    //Write code to initialize array of students.
    examRecords.record = (studentResults*) malloc(classCount * sizeof(studentResults));

    populate(&examRecords, classCount);
    checkExams(answerKey, &examRecords);

    display(examRecords);

}

void checkExams(char answerKey[],classRecord *examRecord){

    //Write Code to check exams here and record the students score
    for(int i=0; i<(examRecord->count); i++){
        examRecord->record[i].studentScore = 0; 
        for(int j=0; j<MAX; j++){
            if(examRecord->record[i].studentAnswer[j] == answerKey[j]){
                examRecord->record[i].studentScore++;
            }
        }
    }
}

void populate(classRecord *examRecord,int classCount){
    int i = 0;
	int x = 0;
	char fName[50];
	char lName[50];
	char MI;
	char studentAnswer[MAX];

	for(i = 0; i < classCount; i++){
        printf("===STUDENT %d===\n\n", i + 1);

        //Write code for student inputs.
        printf("Input First Name: ");           scanf(" %s", fName);
        printf("Input Last Name: ");            scanf(" %s", lName);
        printf("Input Middle Initial: ");       scanf(" %c", &MI);
        printf("Input Students Answer [10]: "); scanf(" %s", studentAnswer);

        //Write code to properly store the inputted values.
        examRecord->record[i] = addStudent(fName, lName, MI, studentAnswer);
        examRecord->count++;
    }
}