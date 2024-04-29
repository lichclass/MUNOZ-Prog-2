#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct cell{
    int elem;
    struct cell *next;
} *SET;

void insertLast(SET *list, int elem){
    SET *trav;

    for(trav = list; *trav != NULL; trav = &(*trav)->next){}

    *trav = (SET)malloc(sizeof(struct cell));
    if(*trav != NULL){
        (*trav)->elem = elem;
        (*trav)->next = NULL;
    }
}

bool isExist(SET list, int elem){
    SET trav;
    for(trav = list; trav != NULL && trav->elem != elem; trav = trav->next){}
    return (trav != NULL) ? true : false;
}

SET intersection(SET A, SET B){
    SET inter, bPtr;

    inter = NULL;
    for(bPtr = B; bPtr != NULL; bPtr = bPtr->next){
        bool flag1 = isExist(A, bPtr->elem);
        bool flag2 = isExist(inter, bPtr->elem);
        if(!flag1 && !flag2){
            insertLast(&inter, bPtr->elem);
        }
    }
    return inter;
}

void displayList(SET list){
    SET trav;

    printf("{ ");
    for(trav = list; trav != NULL; trav = trav->next){ printf("%d ", trav->elem); }
    printf("}\n");
}

int main(){
    SET A = NULL;
    SET B = NULL;

    // For A;
    insertLast(&A, 2);
    insertLast(&A, 4);
    insertLast(&A, 5);
    insertLast(&A, 6);
    insertLast(&A, 8);
    insertLast(&A, 9);

    // For B;
    insertLast(&B, 3);
    insertLast(&B, 8);
    insertLast(&B, 7);
    insertLast(&B, 3);
    insertLast(&B, 1);

    SET C = intersection(A, B);

    printf("SET A: "); displayList(A);
    printf("SET B: "); displayList(B);
    printf("Insersection: "); displayList(C);

    return 0;
}