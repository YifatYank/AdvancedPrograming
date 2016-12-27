//
// Created by yifat on 01/12/16.
//

#ifndef UNITTEST_STANDART_H
#define UNITTEST_STANDART_H

#include "Cab.h"
#include "Enums.h"
class Standart : public ::Cab{
public:
    /**
 * Standart
 * constructor
 * @param col color
 * @param manufact manufacturer
*/
    Standart(int id, Manufacturer manufact, Color col);
    /**
 * Standart
 * destructor
*/
    virtual ~Standart();
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


#endif //UNITTEST_STANDART_H
