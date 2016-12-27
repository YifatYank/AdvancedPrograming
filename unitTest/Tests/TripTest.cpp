#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;
using testing::Test;
using testing::Eq;

#include "Point.h"
#include <list>
#include "Enums.h"
#include "Trip.h"
#include "TaxiCenter.h"
namespace {
    class TripTest : public ::testing::Test {
    public:
        Trip * t;
        Point *ps;
        Point *pe;
        Passenger *p;
        /**
        * Setting things up for the tests.
        */
        void SetUp() {
            ps = new Point(0,0);
            pe = new Point(0,0);
            t = new Trip(123456,5,*ps,*pe,50);
            p= new Passenger(*ps,*pe);
            ps = new Point (0,1);
            pe = new Point(2,3);
        }
        /**
         * Deletes objets allocated in 'SetUp' function.
         */
        void TearDown(){
            delete(t);
            delete (ps);
            delete (pe);
            delete (p);
        }
    };
}
/**
* checks the getId function.
*/
TEST_F(TripTest,getid){
    EXPECT_EQ(123456,t->getID());
}

/**
*check if the function returns the starting point
*/
TEST_F(TripTest,getStartingPoint){
    EXPECT_EQ(p->getSP(),t->getSP());
}
/**
*check if the function returns the ending point
*/
TEST_F(TripTest,getEndingPoint) {
    EXPECT_EQ(p->getDP(), t->getEP());
}
/**
*check if the function returns the total meters passed
*/
TEST_F(TripTest,getTmp){
    EXPECT_EQ(12,t->getTMP());
}
/**
*check if the function sets the total meters passed
*/
TEST_F(TripTest,setTmp){
    t->setTMP(2);
    EXPECT_EQ(2,t->getTMP());
}

/**
*check if the function returns the number of passengers
*/
TEST_F(TripTest,geNop){
    EXPECT_EQ(13,t->getNOP());
}
/**
*check if the function sets the number of passengers
*/
TEST_F(TripTest,setNop){
    t->setNOP(2);
    EXPECT_EQ(2,t->getNOP());
}

/**
*check if the function returns the taarif
*/
TEST_F(TripTest,getTaarif){
    EXPECT_EQ(50,t->getTaarif());
}
/**
*check if the function sets the taarif
*/
TEST_F(TripTest,setTaarif){
    t->setTaarif(70);
    EXPECT_EQ(70,t->getTaarif());
}
/**
*check if the function returns the trip path
*/
TEST_F(TripTest,getTripPath){
//   todo EXPECT_EQ(123456,t->getID());
}
/**
*check if the function sets the trip path
*/
TEST_F(TripTest,setTripPath){
//    t->setID(2);
//  todo  EXPECT_EQ(2,t->getID());
}