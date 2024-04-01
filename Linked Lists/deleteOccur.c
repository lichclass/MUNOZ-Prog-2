#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char elem;
    struct node *link;
} *LIST;

void createNode(LIST *L, char elem){
    
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->elem = elem;

    temp->link = *L;
    *L = temp;
}

void delOccur(LIST *A, char X){

    LIST *trav, temp;

    trav = A;
    while(*trav != NULL){

        if(X == (*trav)->elem){
            temp = *trav;
            *trav = temp->link;
            free(temp);
        } else {
            trav = &(*trav)->link;
        }

    }
}

void freeList(LIST *L){

    LIST temp;
    
    while(*L != NULL){

        temp = *L;
        *L = temp->link;
        free(temp);

    }

}

int main(){
    LIST L = NULL;
    
    createNode(&L, 'A');
    createNode(&L, 'B');
    createNode(&L, 'A');
    createNode(&L, 'A');
    createNode(&L, 'B');
    createNode(&L, 'B');
    createNode(&L, 'B');

    freeList(&L);

    LIST trav;
    for(trav = L; trav != NULL; trav = trav->link){
        printf("%c ", trav->elem);
    }

    return 0;
}