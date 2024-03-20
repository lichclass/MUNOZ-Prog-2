#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef char String[50];

typedef struct {
    String str1;
    String str2;
} TwoString;

void sameWords(TwoString myStr){

    int i, j, word_count1, word_count2;

    /* Storage for each word in a given sentence */
    String tempString1[SIZE];
    String tempString2[SIZE];


    /* Setting the pointer of strtok to "str1" */
    char *token1 = strtok(myStr.str1, " ");
    for(i = 0; token1 != NULL; i++){
        strcpy(tempString1[i], token1);
        token1 = strtok(NULL, " ");
    }
    word_count1 = i;

    /* Resetting the pointer of strtok to "str2" */
    char *token2 = strtok(myStr.str2, " ");
    for(i = 0; token2 != NULL; i++){
        strcpy(tempString2[i], token2);
        token2 = strtok(NULL, " ");
    }
    word_count2 = i;

    /* Displaying the similar words */
    for(i = 0; i < word_count1; i++){
        
        for(j = 0; j < word_count2 && strcmp(tempString1[i], tempString2[j]) != 0; j++){}
        if(j < word_count2){
            printf("%s ", tempString1[i]);
        }
    }

}

int main(){

    TwoString string = {"hello there", "there hello"};

    printf("\nFirst Sentence: %s", string.str1);
    printf("\nSecond Sentence: %s", string.str2);

    printf("\nSame Words: ");
    sameWords(string);

    return 0;
}