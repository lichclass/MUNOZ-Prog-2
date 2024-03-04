#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char chr;
    struct node *link;
} node, *LIST;

void insertNew(LIST *L, char New){
    LIST temp;
    temp = (LIST) malloc (sizeof(node));
    temp->chr = New;
    temp->link = *L;
    *L = temp;
}

int main() {
    LIST L;
    L = (LIST) malloc (sizeof(node));
    L->chr = 'B';   
    L->link = (LIST) malloc (sizeof(node));
    L->link->chr = 'C';
    L->link->link = NULL;
    
    printf("Before Insertion: ");
    for(LIST t = L; t != NULL; t = t->link){
        printf("%c ", t->chr);
    }
    
    insertNew(&L, 'A');
    
    printf("\nAfter Insertion: ");
    for(LIST t = L; t != NULL; t = t->link){
        printf("%c ", t->chr);
    }
    return 0;
}