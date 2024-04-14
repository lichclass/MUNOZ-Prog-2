#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

typedef struct{
    char lname[MAX];
    char fname[MAX];
}nameType;

typedef enum{
   CS, IS, IT, ICT, Math
}courseType;

typedef struct{
   char ID[8];
   nameType name;
   courseType course;
   float GPA;
}studType;

typedef struct{
  studType studs[100];
  int studCount;
}studList;

typedef struct{
  studList lists[3]; //CS, IS, IT
                     //use the enum equivalents
}studRecordV1;

typedef struct{
    studList *lists; // will dynamically allocate 3 elements - CS,IS,IT
}studRecordV2;

studRecordV2 separatePls(studList myList){
    
    int i;
    studRecordV2 separated;
    separated.lists = (studList*) malloc(3 * sizeof(studList));
    separated.lists[CS].studCount = 0;
    separated.lists[IS].studCount = 0;
    separated.lists[IT].studCount = 0;
    
    for(i = 0; i < myList.studCount; i++){

        if(myList.studs[i].course == CS){
            separated.lists[CS].studs[separated.lists[CS].studCount++] = myList.studs[i];
        }

        if(myList.studs[i].course == IS){
            separated.lists[IS].studs[separated.lists[IS].studCount++] = myList.studs[i];
        }

        if(myList.studs[i].course == IT){
            separated.lists[IT].studs[separated.lists[IT].studCount++] = myList.studs[i];
        }

    }

    return separated;

}

studList initializeStudRec(){ 
    
    studList L = {
                    {
                        {"11111111", {"doe", "john"}, CS, 1.0},
                        {"22222222", {"eod", "nhoj"}, CS, 2.0},
                        {"33333333", {"nuts", "deez"}, CS, 3.0},
                        {"44444444", {"jane", "mary"}, IS, 4.0},
                        {"66666666", {"enaj", "yram"}, IS, 5.0},
                        {"77777777", {"itlog", "akongScore"}, IS, 1.0},
                        {"34343434", {"nuts2", "deez2"}, CS, 3.0},
                        {"77777777", {"jaroa", "jarc"}, IT, 2.0},
                        {"88888888", {"jarago", "jarly"}, IT, 3.0},
                        {"99999999", {"eeper", "beeper"}, IT, 4.0}
                    }, .studCount = 10
                };

    return L;
}

void main(){

    int i;

    studList myList = initializeStudRec();

    studRecordV2 separated = separatePls(myList);

    printf("\nMGA CS:\n");
    for(i = 0; i < separated.lists[CS].studCount; i++){
        printf("%s %s\n", separated.lists[CS].studs[i].name.fname, separated.lists[CS].studs[i].name.lname);
    }

    // printf("\nMGA IS:\n");
    // for(i = 0; i < separated.lists[IS].studCount; i++){
    //     printf("%s %s\n", separated.lists[IS].studs[i].name.fname, separated.lists[IS].studs[i].name.lname);
    // }

    // printf("\nMGA IT:\n");
    // for(i = 0; i < separated.lists[IT].studCount; i++){
    //     printf("%s %s\n", separated.lists[IT].studs[i].name.fname, separated.lists[IT].studs[i].name.lname);
    // }


}