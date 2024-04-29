#include <stdio.h>
#include <stdlib.h>

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

SET copyList(SET list){
    SET copy, trav;

    copy = NULL;
    for(trav = list; trav != NULL; trav = trav->next){
        insertLast(&copy, trav->elem);
    }

    return copy;
}

void displayList(SET list){
    SET trav;

    printf("{ ");
    for(trav = list; trav != NULL; trav = trav->next){ printf("%d ", trav->elem); }
    printf("}\n");
}

int main(){
    SET A = NULL;

    // Init SET A
    insertLast(&A, 1);
    insertLast(&A, 3);
    insertLast(&A, 4);
    insertLast(&A, 7);
    insertLast(&A, 8);

    SET C = copyList(A);

    printf("Set A: "); displayList(A);
    printf("Set C: "); displayList(C);

    return 0;
}