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

    Studtype myData1[] = {
        {{"Munoz", "Nash Adam", 'G'}, 21700005, "BSCS", 1},
        {{"Adams", "Amy", 'M'}, 21800005, "BSCS", 1},
        {{"Sins", "Johnny", 'D'}, 8900005, "BSCS", 1}
    };

    Studtype newStud = {{"Neutron", "Jimmy", 'G'}, 8520023, "BSIT", 1};
    
    Studlist list1 = {
        {myData1[0], myData1[1], myData1[2]}, 
        3
    };
    

    /* Insert Functions to use after this comment */

    return 0;
}


