#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST 50
#define MAX_NAME 40
#define MAX_PHONE 12
#define MAX_EMAIL 25

typedef struct{
    char name[MAX_NAME];
    char phone_num[MAX_PHONE];
    char email[MAX_EMAIL];
} CONTACT;

typedef struct {
    CONTACT contacts[MAX_LIST];
    int count;
} CONTACT_LIST;

void addContact(CONTACT_LIST *cont_list){
    
    printf("Contact %d\n", cont_list->count + 1);
   
    printf("Name: ");
    scanf(" %s", cont_list->contacts[cont_list->count].name);

    printf("Phone: ");
    scanf(" %s", cont_list->contacts[cont_list->count].phone_num);

    printf("Email: ");
    scanf(" %s", cont_list->contacts[cont_list->count].email);

    cont_list->count++;
}

void searchContact(CONTACT_LIST *cont_list){
    
    char toSearch[MAX_NAME];
    
    printf("Enter the name to search: ");
    scanf("%s", toSearch);
    
    int i;
    for(i = 0; i < cont_list->count && strcmp(cont_list->contacts[i].name, toSearch) != 0; i++){}

    if(i < cont_list->count){
        printf("Contact found:\n");
        printf("Name: %s\n", cont_list->contacts[i].name);
        printf("Phone: %s\n", cont_list->contacts[i].phone_num);
        printf("Email: %s\n", cont_list->contacts[i].email);
    } else {
        printf("Contact not found.\n");
    }
}

int main(){
    CONTACT_LIST myContact = { 0 };
    char choice;

    printf("Enter the contact details:\n");
    do{
        addContact(&myContact);
        printf("Do you want to add another contact? (y/n): ");
        scanf(" %c", &choice);

    }while(choice != 'n');
    
    searchContact(&myContact);

    return 0;
}