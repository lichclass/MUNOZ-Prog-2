/*
=================================================
NAME: CODE FOR GOVERNMENT INEQUALITY
NOTE: Without the header files etc. | Made my own 
      display func kay their display func is goofy.
DATE: APRIL 11, 2024
=================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#define MAX 20
#define bracket1Rate 0.10
#define bracket2Rate 0.15
#define bracket3Rate 0.20

employeeRecord populate(int);
employeeInfo newEmployee(int, int, int, name);
name addName(char[], char[], char);
void taxBracketSeparation(companyRecord *);
void displayList(companyRecord myRec);


int main(){
    companyRecord companyLists;
    int i = 0;
    int employeeInitialCount = 0;


    printf("Input how many employees: "); scanf("%d", &employeeInitialCount);

    companyLists.employeeList = populate(employeeInitialCount);

    taxBracketSeparation(&companyLists);

	displayList(companyLists);

}


void taxBracketSeparation(companyRecord *companyList){
    /* This function will separate all employees from the employeeList and add them into their appropriate Tax Bracket based on their Gross Pay. After which calculate their Take Home pay based on their tax bracket rate. The function will take in a companyRecord pointer and will not return anything. */

    	//WRITE CODE TO SEPARATE EMPLOYEE LIST INTO PROPER TAX BRACKETS AND THEN
        //CALCULATE THEIR TAKE HOME PAY
        companyList->bracket3.count = 0;
        companyList->bracket3.employees = (employeeInfo*) malloc (sizeof(employeeInfo) * 20);
        companyList->bracket2.count = 0;
        companyList->bracket2.employees = (employeeInfo*) malloc (sizeof(employeeInfo) * 20);
        companyList->bracket1.count = 0;
        companyList->bracket1.employees = (employeeInfo*) malloc (sizeof(employeeInfo) * 20);
        float employeeGross;
        int i;
        for(i = 0; i < companyList->employeeList.count; i++){
            printf("Test");
            employeeGross = companyList->employeeList.employees[i].grossSalary;
            if(employeeGross >= 26000){
                companyList->bracket3.employees[companyList->bracket3.count] = companyList->employeeList.employees[i];
                companyList->bracket3.employees[companyList->bracket3.count].takeHomeSalary = employeeGross - (employeeGross * bracket3Rate);
                companyList->bracket3.count++;
            }
            else if(employeeGross >= 15000){
                companyList->bracket2.employees[companyList->bracket2.count] = companyList->employeeList.employees[i];
                companyList->bracket2.employees[companyList->bracket2.count].takeHomeSalary = employeeGross - (employeeGross * bracket2Rate);
                companyList->bracket2.count++;
            }
            else{
                companyList->bracket1.employees[companyList->bracket1.count] = companyList->employeeList.employees[i];
                companyList->bracket1.employees[companyList->bracket1.count].takeHomeSalary = employeeGross - (employeeGross * bracket1Rate);
                companyList->bracket1.count++;
            }
        }   
}


employeeRecord populate(int count){

    /* This function will take in a count of how many employees to add, and return an employeeRecord */

    employeeRecord list;

    //Statement to allocate memory for an Array of Employees.
    list.employees=(employeeInfo*)malloc(sizeof(employeeInfo)*count);
    list.count = 0;
    int i=0;
    int idNum;
    int rate;
    int hrsWorked;
    char fName[20];
    char lName[20];
    char MI;

    for(i=0;i<count;i++){
        printf("\n\n===EMPLOYEE %d===\n\n",i+1);

        //Write Code to Ask users for Input
        printf("Input First Name: "); 
        scanf(" %s", fName); 
        printf("Input Last Name: "); 
        scanf(" %s", lName); 
        printf("Input Middle Initial: "); 
        scanf(" %c", &MI); 
        printf("Input Id Number: "); 
        scanf(" %d", &idNum); 
        printf("Input Rate: "); 
        scanf(" %d", &rate);
        printf("Input Hours Worked: ");
        scanf(" %d", &hrsWorked); 

        name newName = addName(fName, lName, MI); 
        
        list.employees[i] = newEmployee(idNum, rate, hrsWorked, newName);
        list.count++;

        if(i==count-1){
            printf("\n===============\n\n");
        }
    }

    return list;

}
employeeInfo newEmployee(int idNum, int rate, int hrsWorked, name employeeName){
    employeeInfo newEmp;

    newEmp.empName = employeeName;
    newEmp.idNum = idNum;
    newEmp.rate = rate;
    newEmp.hrsWorked = hrsWorked;

    //Write Code to Calculate grossSalary;
    newEmp.grossSalary = rate * hrsWorked;

    return newEmp;

}
name addName(char fName[], char lName[], char MI){

    /* This function takes in 2 Strings and a Character, it will then populate a new name structure variable based on the parameters passed towards this function and aim to return it back to the calling function */

    name employeeName;

    strcpy(employeeName.fName, fName);
    strcpy(employeeName.lName, lName);
    employeeName.MI = MI;

    return employeeName;

}

void displayList(companyRecord myRec){

    int i;

    if(myRec.bracket1.count > 0){
        printf("\n\n===BRACKET 1===\n");
        for(i = 0; i < myRec.bracket1.count; i++){
            printf("%d - ", myRec.bracket1.employees[i].idNum);
            printf("%s,", myRec.bracket1.employees[i].empName.lName);
            printf("%s ", myRec.bracket1.employees[i].empName.fName);
            printf("%c ---", myRec.bracket1.employees[i].empName.MI);
            printf("Php %.2f\n", myRec.bracket1.employees[i].takeHomeSalary);
        }
    }

    if(myRec.bracket2.count > 0){
        printf("\n\n===BRACKET 2===\n");
        for(i = 0; i < myRec.bracket2.count; i++){
            printf("%d - ", myRec.bracket2.employees[i].idNum);
            printf("%s,", myRec.bracket2.employees[i].empName.lName);
            printf("%s ", myRec.bracket2.employees[i].empName.fName);
            printf("%c ---", myRec.bracket2.employees[i].empName.MI);
            printf("Php %.2f\n", myRec.bracket2.employees[i].takeHomeSalary);
        }
    }

    if(myRec.bracket3.count > 0){
        printf("\n\n===BRACKET 3===\n");
        for(i = 0; i < myRec.bracket3.count; i++){
            printf("%d - ", myRec.bracket3.employees[i].idNum);
            printf("%s,", myRec.bracket3.employees[i].empName.lName);
            printf("%s ", myRec.bracket3.employees[i].empName.fName);
            printf("%c --- ", myRec.bracket3.employees[i].empName.MI);
            printf("Php %.2f\n", myRec.bracket3.employees[i].takeHomeSalary);
        }
    }

}