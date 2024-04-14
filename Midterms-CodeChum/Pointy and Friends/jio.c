#include <stdio.h>
#include <stdlib.h>
#include "pointy.h"

/**
    Function: getMrPointyAndFriends()
    Description: The function will get all points with the same cluster (location) in the cartesian plane. Mr Pointy is the first index in the collection followed by the others.
    Param: points - a collection of points starting with Mr. Pointy followed by the others.
    Return: a collection of Mr Pointy and with his friends. Still Mr Pointy will still be in the first index follwed by his friends.
*/
Points getMrPointyAndFriends(Points points) {
    // [2] to do code login here
    Points newPoints;
    newPoints.max = points.count;
    newPoints.count = 0;
    newPoints.points = (Points*) malloc(sizeof(MyPoint) * newPoints.max);
    
    int quadrant = identifyPoint(points.points[0]);
    for (int i = 1; i < points.count; ++i) {
        if (identifyPoint(points.points[i]) == quadrant) {
            newPoints.points[newPoints.count++] = points.points[i];
        }
    }

    newPoints.points = realloc(newPoints.points, sizeof(MyPoint) * newPoints.count);

    return newPoints;
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
    points.points[0]=createPoint(x,y);
    
    displayPointMsg(points.points[0]);
    // [3] insert you function call of getMrPointyAndFriends() after this line
    Points newPoints = getMrPointyAndFriends(points);
    
    printf("Friends: ");
    // [4] use the function displayAllPointsWithStartIndex()
    displayAllPointsWithStartIndex(newPoints, 0);
}