//
// Created by yifat on 01/12/16.
//

#ifndef UNITTEST_LUXURY_H
#define UNITTEST_LUXURY_H

#include "Cab.h"

class Luxury : public ::Cab{
public:
    /**
 * Luxury
 * @param col color
 * @param manufact manufacturer
*/
    Luxury(int id, Manufacturer manufact, Color col);
    /**
 * Luxury
 * destructor
*/
    virtual ~Luxury();

    /**
 * moveNext
 * move to the next point
*/
    virtual void moveNext();
    /**
 * updateTaarif
 * updating the taarif
*/
    virtual void updateTaarif();
};


#endif //UNITTEST_LUXURY_H
