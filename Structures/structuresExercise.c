/*
======================================================================
FILE        : structuresExercise.c
AUTHOR      : Munoz, Nash Adam G.
DESCRIPTION : Structures assignment for CIS 1201 - Programming 2
COPYRIGHT   : February 23, 2024
REVISION HISTORY
Date:           By:         Description:
======================================================================
*/

#include <stdio.h>
#include "exerciseFunc.h"

/* Main function */
int main(){

    Nametype myName = {"Munoz", "Nash Adam", 'G'};
    Studtype myInfo = {myName, 21700005, "BSCS", 1};
    Studtype myInfo2 = {{"Adams", "Amy", 'G'}, 21800005, "BSCS", 1};
    Studlist list;

    list.count = 1;
    list.Stud[0] = myInfo;

    insertFirst_VerOne(&list, myInfo2);
    displayList(&list);

    return 0;
}


