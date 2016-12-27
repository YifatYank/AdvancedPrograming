//
// Created by yifat on 01/12/16.
//

#ifndef UNITTEST_TRIP_H
#define UNITTEST_TRIP_H

#include "Point.h"
#include <list>

class Trip {
    // The trip responsible for its start point and end point.
private:
    int id;
    int total_meters_passed;
    Point * starting_point;
    Point * ending_point;
    int number_of_passenger;
    int tarrif;
    list<pPoint>* trip_path;
public:
    /**
 * Trip
 * constructor
 * @param taarif taarif
 * @param start striting point
 * @param end ending point
 * @param numOfPassangers num of passengers
*/
    Trip(int id,int taarif, Point start, Point end, int numOfPassangers);
    /**
   * Trip
   * destructor
  */
    ~Trip();

    int getID();
    /**
 * getTMP
 * returns the total meters passed
 * @return tmp
*/
    int getTMP();
    /**
 * setTMP
 * sets total meters passed
 * @param x total meters passed
*/
    void setTMP(int x);
    /**
 * getSP
 * returns the source point
 * @return sp
*/
    Point * getSP();
    /**
 * getEP
 * returns the ending point
 * @return ep
*/
    Point * getEP();
    /**
 * getNOP
 * returns the number of passengers
 * @return nop
*/
    int getNOP();
    /**
 * setNOP
 * sets the number of passengers
 * @param x num pf passengers
*/
    void setNOP(int x);
    /**
 * getTaarif
 * returns the taarif
 * @return t taarif
*/
    int getTaarif();
    /**
 * setTaarif
 * sets the taarif
 * @param x taarif
*/
    void setTaarif(int x);
    /**
 * getTrip_path
 * returns the trip path
 * @return point list of points
*/
    list<pPoint> * getTrip_path();
    /**
 * setTrip_path
 * sets the trip path
 * @param lst list of points
*/
    void setTrip_path(list<pPoint> * lst);
};

typedef Trip * pTrip;
#endif //UNITTEST_TRIP_H