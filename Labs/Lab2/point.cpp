#include "point.h"
using namespace std;

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
     double _distance;
     Point *_point = nullptr; //this will be the nearest point
    double fake_dis = 999999999; 
     if(arrSize==0)
     {
        cout << "Array empty. " << endl;
        return 0;
     }

     for(int i = 0; i<arrSize; i++)
     {
          if(pointList[i] ==_point) continue;
          _distance = distPoints(*pointList[i]);

          if(_distance < fake_dis)
          {
              fake_dis = _distance;
              _point = pointList[i];
          }
     }

    return _point;
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