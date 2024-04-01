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
} STUDTYPE;

typedef struct {
    STUDTYPE list[MAX];
    int cnt;
} STUDLIST;

STUDLIST list = { 0 };

STUDLIST populateList();
void displayList(STUDLIST);
void insertAtPos(STUDLIST*, int, STUDTYPE);
STUDTYPE deleteElem(STUDLIST*, int);
int deleteAllOccur(STUDLIST*, char[]);
void swap(STUDTYPE*, STUDTYPE*);
void selectionSort(STUDLIST*);

STUDLIST populateList(){
    
    STUDTYPE studArr[] = { 
                            {{"Collins","James",'K'}, 11111111, "BSCS", 1},
                            {{"Abrams","John",'L'}, 22222222, "BSIT", 1},
                            {{"De Shaun","Jamal",'M'}, 33333333, "BSCS", 1},
                         };
                         
    int numElem = sizeof(studArr) / sizeof(STUDTYPE);

    STUDLIST list = {{studArr[0], studArr[1], studArr[2]}, numElem};

    return list;

}

int main(){

    STUDLIST popList = populateList();
    STUDLIST delList;
    STUDTYPE lebron = {{"James","LeBron",'R'}, 44444444, "BSIT", 1};
    insertAtPos(&popList, 3, lebron);
    selectionSort(&popList);
    //deleteAllOccur(&popList, "BSIT");
    // delList.list[0] = deleteElem(&popList, 44444444);
    // delList.cnt = 1;
    displayList(popList);
    // printf("Deleted List\n");
    // displayList(delList);

    return 0;
}

void displayList(STUDLIST list){
    int i;
    char str[50];
    for(i = 0; i < list.cnt; i++){
        sprintf(str, "%s,", list.list[i].name.LName);
        printf("%-10s", str);
        printf("%-12s %-5c", list.list[i].name.FName, list.list[i].name.MI);
        printf("%-12d", list.list[i].ID);
        printf("%-5s", list.list[i].Course);
        printf("%-2d\n", list.list[i].year);
    }
}

void insertAtPos(STUDLIST *myList, int pos, STUDTYPE newStud){

    if(myList->cnt < MAX){

        if(pos <= myList->cnt){
            memcpy(myList->list + (pos + 1), myList->list + pos, (myList->cnt - pos) * sizeof(STUDTYPE));
            myList->list[pos] = newStud;
            myList->cnt++;
        } else {
            printf("\nPosition is out of bounds\n");
        }

    } else {
        printf("\nInsufficient Storage!\n");
    }

}

STUDTYPE deleteElem(STUDLIST *myList, int delID){
    
    int i;
    STUDTYPE dummy = {{"XXXX", "XXXX", 'X'}, 0, "XXXX", 0};
    for(i = 0; i < myList->cnt && myList->list[i].ID != delID; i++){}
    if(i < myList->cnt){
        dummy = myList->list[i];
        memcpy(myList->list + i, myList->list + (i + 1), (myList->cnt - (i + 1)) * sizeof(STUDTYPE));
        myList->cnt--;
    } else {
        printf("\nID number not found\n");
    }

}

int deleteAllOccur(STUDLIST *myList, char delCourse[]){
    int del = 0, i = myList->cnt - 1;
    while(i >= 0){
        if(strcmp(myList->list[i].Course, delCourse) == 0){
              
            memcpy(&myList->list[i], &myList->list[i + 1], (myList->cnt - i - 1) * sizeof(STUDTYPE));
            myList->cnt--;
            del++;

        }
        i--;
    }
}

void selectionSort(STUDLIST *myList){

    int i, j;
    for(i = 0; i < myList->cnt - 1; i++){
        int key = i;
        for(j = i + 1; j < myList->cnt; j++){
            if(myList->list[j].name.LName[0] < myList->list[key].name.LName[0]){
                key = j;
            }
        }
        if(key != i){
            swap(&myList->list[i], &myList->list[key]);
        }
    }
    
}

void swap(STUDTYPE *x, STUDTYPE *y){
    STUDTYPE temp = *x;
    *x = *y;
    *y = temp;
}