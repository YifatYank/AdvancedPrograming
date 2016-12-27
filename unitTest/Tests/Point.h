//
// Created by yifat on 30/11/16.
//

#ifndef UNITTEST_POINT_H
#define UNITTEST_POINT_H


#include <string>
#include <stdlib.h>

using namespace std;
class Point{
    private:
        int xCoord;
        int yCoord;

    public:
    /* Point.
    * <p>
    * constructor.
    * @param x x's position
    * @param y y's position
    */
        Point(int x, int y);
    /* getX.
    * <p>
    * returns the x's value.
    * @return xCoord
    */
        int getX();
    /* setX.
    * <p>
    * sets the x's value.
    * @param x
    */
        void setX(int x);
    /* getY.
    * <p>
    * returns the y's value.
    * @return yCoord
    */
        int getY();
    /* setY.
    * <p>
    * sets the y's value.
    * @param yCoord
    */
        void setY(int y);
    /* getString.
    * <p>
    * returns a string of points.
    * @return str a string
    */
        string * getString();
    /* operator==.
    * <p>
    * return true if the points are equal.
    * @param p a point
    * @return true\false
    */
        bool operator==(Point p);
    /* intToString.
    * <p>
    * function that does casting from int to string.
    * @param num a number to cast
    * @return str the number as a string
    */
    string * intToString(int num);
};

typedef Point * pPoint;

#endif //UNITTEST_POINT_H
