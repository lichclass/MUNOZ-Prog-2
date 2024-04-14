#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char LName[16];
    char FName[24];
    char MI;
} NAMETYPE;

typedef struct {
    NAMETYPE name;
    int ID;
    char Course[8];
    int year; 
} STUDTYPE, *STUDTYPEPTR;

typedef struct {
    STUDTYPEPTR list;
    int cnt;
    int max;
} STUDLIST, *STUDLISTPTR;

typedef enum {
    CS, IT, IS
} COURSE;

void separatePls(STUDLISTPTR myList);

void displayList(STUDLISTPTR list){
    int i;
    char str[50];
    for(i = 0; i < list->cnt; i++){
        sprintf(str, "%s,", list->list[i].name.LName);
        printf("%-10s", str);
        printf("%-12s %-5c", list->list[i].name.FName, list->list[i].name.MI);
        printf("%-12d", list->list[i].ID);
        printf("%-5s", list->list[i].Course);
        printf("%-2d\n", list->list[i].year);
    }
}

void populateList(STUDLISTPTR *myList){
    
    STUDTYPE studArr[] = { 
                            {{"Collins","James",'K'}, 11111111, "BSCS", 1},
                            {{"Abrams","John",'L'}, 22222222, "BSIT", 1},
                            {{"De Shaun","Jamal",'M'}, 33333333, "BSCS", 1},
                         };

    int numOfElem = sizeof(studArr) / sizeof(studArr[0]);

    memcpy((*myList)->list, studArr, numOfElem * sizeof(STUDTYPE));

    (*myList)->cnt = numOfElem;

}

int main(){

    STUDLISTPTR L = (STUDLISTPTR) malloc(sizeof(STUDLIST));
    L->max = 5;
    L->list = (STUDTYPEPTR) malloc(L->max * sizeof(STUDTYPE));
    
    populateList(&L);
    displayList(L);

    return 0;

}

void separatePls(STUDLISTPTR myList, String course[]){

    

}