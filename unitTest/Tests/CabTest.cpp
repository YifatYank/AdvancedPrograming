//
// Created by yifat on 03/12/16.
//

//
// Created by yifat on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cab.h"
#include "Standart.h"
#include "Luxury.h"
#include "Driver.h"
#include "Point.h"
using namespace std;
using testing::Test;
using testing::Eq;
using std::list;


namespace {
    /**
     * This class take tests for the calss Cab and its subclasses
     * Standart and luxurius.
     */
class CabTest : public ::testing::Test {
public:
    Standart * standart;
    Luxury * luxury;
    /**
     * Setting things up for the tests.
     */
    void SetUp() {
        standart = new Standart(111,HONDA, WHITE);
        luxury = new Luxury(222,HONDA, WHITE);
    }

    /**
     * Deletes objets allocated in 'SetUp' function.
     */
    void TearDown() {
        delete(standart);
        delete(luxury);
    }
};
}

/**
 * Checks the functions getKilometers and set kilometers.
 */
TEST_F(CabTest, getCilometers) {
    EXPECT_EQ(0, standart->getKilometers());
    standart->setKilometers(50);
    EXPECT_EQ(50, standart->getKilometers());
}

/**
 * Checks the function getManufactorer.
 */
TEST_F(CabTest, getManufectorer) {
    EXPECT_EQ(HONDA,standart->getManufacturer());
}

/**
 * Checks the function get color.
 */
TEST_F(CabTest,getColor) {
    EXPECT_EQ(WHITE,standart->getColor());
}

/**
 * Checlk the function get location.
 */
TEST_F(CabTest, getLocation) {
    Point * p, * place;
    p = new Point(0,0);
    place = standart->getLocation();
    EXPECT_EQ(p->getX() ,place->getX());
    EXPECT_EQ(p->getY() ,place->getY());
    delete(p);
    delete(place);
}

// Check function get taarif for both standart and luxurious cab.
TEST_F(CabTest, getTaarif) {
    EXPECT_EQ(1 , standart->getTaarif());
    EXPECT_EQ(4 , luxury->getTaarif());
}

/**
 * Checks the function getSpeed for both standart and luxurois cab.
 */
TEST_F(CabTest, getSpeed) {
    EXPECT_EQ(1 , standart->getSpeed());
    EXPECT_EQ(2 , luxury->getSpeed());
}

/**
 * Checks the function MoveNext for both standart and luxurius cab.
 */
TEST_F(CabTest, moveNext) {
    Point * p = new Point(0,0);
    Point * place;
    list<pPoint> *lst;
    Trip * trp = new Trip(1234,10,Point(0,0), Point(2,2), 3);


    // If the cab has no trip.
    standart->moveNext();
    place = standart->getLocation();
    EXPECT_EQ(p->getX() , place->getX());
    EXPECT_EQ(p->getY() , place->getY());
    delete(place);

    place = luxury->getLocation();
    EXPECT_EQ(p->getX() , place->getX());
    EXPECT_EQ(p->getY() , place->getY());

    delete(place);

    delete(p);

    // When there is a trip assigned to the cab.
    lst = new list<pPoint>();
    lst->push_front(new Point(0, 0));
    lst->push_front(new Point(1, 0));
    lst->push_front(new Point(2, 0));
    lst->push_front(new Point(2, 1));
    lst->push_front(new Point(2, 2));

    trp->setTrip_path(lst);
    standart->setTrip(trp);
    standart->moveNext();
    place = standart->getLocation();
    p = new Point(1,0);
    EXPECT_EQ(p->getX() , place->getX());
    EXPECT_EQ(p->getY() , place->getY());
    delete(p);
    delete(place);


    while(!lst->empty()) {
        p = lst->front();
        lst->pop_front();
        delete(p);
    }
    delete(lst);

    lst = new list<pPoint>();
    lst->push_front(new Point(0, 0));
    lst->push_front(new Point(1, 0));
    lst->push_front(new Point(2, 0));
    lst->push_front(new Point(2, 1));
    lst->push_front(new Point(2, 2));


    trp->setTrip_path(lst);
    luxury->setTrip(trp);
    luxury->moveNext();
    place = luxury->getLocation();
    p = new Point(2,0);
    EXPECT_EQ(p , place);



    delete(p);
    delete(place);

    while(!lst->empty()) {
        p = lst->front();
        lst->pop_front();
        delete(p);
    }

    delete(lst);
    delete(trp);
}

