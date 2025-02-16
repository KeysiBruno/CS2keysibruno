#include "point.h"

//Constructor
points::Point::Point(int X, int Y, points::Point* closestPoint) : x(X), y(Y), nearestPoint(closestPoint)
{
}
//Destructor
points::Point::~Point()
{
}

//Getters
int points::Point::getX()
{
    return x;
}

int points::Point::getY()
{
    return y;
}

points::Point* points::Point::getNearestPoint()
{
    return nearestPoint;
}

points::Point* points::Point::calcNearestPoint(Point* pointList[], unsigned long arrSize)
{  
     double fake_distance = 99999;
     double _distance;
     Point *Nearest_Point;

      while(arrSize > 0)
      {
         for(int i=0; i<arrSize; i++)
         {
         }
      }


    return nullptr;
}

//Setters
void points::Point::setX(int newVal)
{
    x = newVal;
}

void points::Point::setY(int newVal)
{
   y = newVal;
}

void points::Point::setNearestPoint(Point* newNearestPoint)
{
   nearestPoint = newNearestPoint;
}

double points::Point::distPoints(Point& point)
{
    double distance;
    distance = sqrt(pow(x-point.getX(), 2) + pow(y-point.getY(), 2));
    return distance;
}