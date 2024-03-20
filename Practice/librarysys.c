#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    char title[MAX];
    char author[MAX];
    char genre[MAX];
    int isavail;
} BOOK;

typedef struct {
    BOOK book[MAX];
    int count;
} BOOKLIST, *BOOKLISTptr;

void add(BOOKLIST*);
void display(BOOKLIST*);
void borrow(BOOKLIST*);
void returnBook(BOOKLIST*);

void menu(){
    printf("\nLibrary Management System");
    printf("\n1. Add a book");
    printf("\n2. Display all books");
    printf("\n3. Borrow a book");
    printf("\n4. Return a book");
    printf("\n5. Exit");
}

void main(){
    BOOKLIST *books = (BOOKLIST*)malloc(sizeof(BOOKLIST));
    books->count = 0;
    int choice = 0;
    
    while (choice != 5)
    {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                add(books);
                break;
            case 2:
                display(books);
                break;
            case 3:
                borrow(books);
                break;
            case 4:
                returnBook(books);
                break;
            default:
                break;
        }

    }
    
}

void add(BOOKLIST *books){

    fflush(stdin);
    printf("Enter book title: ");
    scanf("%[^\n]s", books->book[books->count].title);
    fflush(stdin);
    printf("Enter book author: ");
    scanf("%[^\n]s", books->book[books->count].author);
    fflush(stdin);
    printf("Enter book genre: ");
    scanf("%[^\n]s", books->book[books->count].genre);
    books->book[books->count].isavail = 1;

    books->count++;
    printf("Book added successfuly.\n");
}

void display(BOOKLIST *books){
    
    if(books->count != 0){  
        int i;
        for(i = 0; i < books->count; i++){
            printf("%d. Title: %s, ",i + 1 , books->book[i].title);
            printf("Author: %s, ", books->book[i].author);
            printf("Genre: %s, ", books->book[i].genre);
            printf("Available: %s\n", (books->book[i].isavail) ? "Yes" : "No");
        }
    }
    else {
        printf("Library is Empty.\n");
    }

}

void borrow(BOOKLIST *books){
    display(books);
    if(books->count != 0){
        int toBorrow;
        printf("Enter the no. that you want to borrow: ");
        scanf("%d", &toBorrow);
        if(books->book[toBorrow - 1].isavail == 1){
            books->book[toBorrow - 1].isavail = 0;
            printf("You have successfully borrowed the book.\n");
        }
        else {
            printf("Book is not available.\n");
        }
    }
}

void returnBook(BOOKLIST *books){
    if(books->count != 0){
        display(books);
        int toBorrow;
        printf("Enter the no. that you want to return: ");
        scanf("%d", &toBorrow);
        if(books->book[toBorrow - 1].isavail == 0){
            books->book[toBorrow - 1].isavail = 0;
            printf("You have successfully returned the book.\n");
        }
        else {
            printf("Book is already returned.\n");
        }
    }
    else{
        printf("Library is Empty.\n");
    }
}