/*
=================================================
NAME: CODE FOR POINTY AND HIS DEADASS FRIENDS
NOTE: Without the header files etc.
DATE: APRIL 11, 2024
=================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "pointy.h"A

/**
    Function: getMrPointyAndFriends()
    Description: The function will get all points with the same cluster (location) in the cartesian plane. Mr Pointy is the first index in the collection followed by the others.
    Param: points - a collection of points starting with Mr. Pointy followed by the others.
    Return: a collection of Mr Pointy and with his friends. Still Mr Pointy will still be in the first index follwed by his friends.
*/
Points getMrPointyAndFriends(Points points) {
    // [2] to do code login here
    Points pointyAndFriends;
    pointyAndFriends.max = points.count;
    pointyAndFriends.count = 0;
    pointyAndFriends.points = (MyPoint*) malloc(sizeof(MyPoint) * points.count);
    
    int i;
    int pointyLocation = identifyPoint(points.points[0]);
    for(i = 0; i < points.count; i++){
        int friendLocation = identifyPoint(points.points[i]);
        if(pointyLocation == friendLocation){
            pointyAndFriends.points[pointyAndFriends.count++] = points.points[i];
        }
    }
    
    return pointyAndFriends;
}

void main() {
    Points points = createPoints(30);
    Points friends;
    int x, y;

    populatePoints(&points);

    printf("Enter x - coordinate: ");
    scanf("%d", &x);
    printf("Enter y - coordinate: ");
    scanf("%d", &y);

    // [1] insert code after this comment to override the first value in the populated points by the new value x and y known as Mr. Pointy
    points.points[0] = createPoint(x, y);

    displayPointMsg(points.points[0]);
    // [3] insert you function call of getMrPointyAndFriends() after this line
    friends = getMrPointyAndFriends(points);


    printf("Friends: ");
    // [4] use the function displayAllPointsWithStartIndex()
    displayAllPointsWithStartIndex(friends, 1);
}