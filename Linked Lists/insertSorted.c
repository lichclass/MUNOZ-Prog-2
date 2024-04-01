#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *link;
} *LIST;

void insertNum(LIST *list, int num){

    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->num = num;

    temp->link = *list;
    *list = temp;
}

void insertSorted(LIST *list, int num){
    LIST temp = (LIST)malloc(sizeof(struct node));
    temp->num = num;
    temp->link = NULL;

    LIST trav;
    for(trav = *list; trav != NULL && trav->link->num < num; trav = trav->link){}

    temp->link = trav->link;
    trav->link = temp;
}

int main(){
    LIST L = (LIST)malloc(sizeof(struct node));
    L->num = 7;
    L->link = NULL;
    
    insertNum(&L, 5);
    insertNum(&L, 2);

    insertSorted(&L, 3);

    LIST temp;
    for(temp = L; temp != NULL; temp = temp->link){
        printf("%d ", temp->num);
    }

    return 0;
}