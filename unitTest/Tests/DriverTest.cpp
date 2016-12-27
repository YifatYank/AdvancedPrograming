//
// Created by yifat on 30/11/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Driver.h"
using namespace std;
using testing::Test;
using testing::Eq;
using std::list;
typedef Point * pPoint;

namespace {

    /**
     * This class takes tests for the calss driver.
     */
class DriverTest : public ::testing::Test {
public:
    Driver * driver;
    Grid * grid = new Grid(3,3);
    Cab * cab;

    ~DriverTest() {
        delete(this->grid);
    }

    /**
     * Setting things up for the tests.
     */
    void SetUp() {
        cab = new Cab(0,HONDA,RED);
        driver = new Driver(123456, 50, married, 20,this->grid);
        driver->setCab(cab);
    }

    /**
     * Deletes objets allocated in 'SetUp' function.
     */
    void TearDown() {
        delete(driver);
    }
};
}

/**
 * Tests the function getId;
 */
TEST_F(DriverTest, getId) {
    EXPECT_EQ(123456, driver->getID());

}

/**
 * Tests the functions getAge, and setAge.
 */
TEST_F(DriverTest, getAge) {
    EXPECT_EQ(50,driver->getAge());
    driver->setAge(51);
    EXPECT_EQ(51,driver->getAge());
}

/**
 * Tests the function getPlace.
 */
TEST_F(DriverTest,getPlace) {
    Point * p = new  Point(0,0);
    Point * place = driver->getPlace();
    EXPECT_EQ(p,driver->getPlace());
    delete(p);
    delete(place);
}

/**
 * Checks the function isOcuupied.
 */
TEST_F(DriverTest, is_occupied) {
    EXPECT_FALSE(driver->isAvalable());
}

/**
 * Test the function get MlStatus and setMlstatus.
 */
TEST_F(DriverTest, getMlStatus) {
    driver->setMlStatus(single);
    EXPECT_EQ(single ,driver->getMlStatus());
    driver->setMlStatus(married);
    EXPECT_EQ(married, driver->getMlStatus());
}

/**
 * Checks the functions addReview and getAvSa
 */
TEST_F(DriverTest, addReview) {
    driver->addReview(5);
    EXPECT_EQ(5,driver->getAvSa());
    driver->addReview(3);
    EXPECT_EQ(4,driver->getAvSa());
}

/**
 * Tests the function calculate path.
 */
TEST_F(DriverTest, calculatepath) {
    list<pPoint> *lstWanted;
    Point *pWanted;
    Point *p;

    list<pPoint> *lst = new list<pPoint >();//driver->calculatePath(Point(0, 0), Point(2, 2));

    lstWanted = new list<pPoint>();
    lstWanted->push_front(new Point(0, 0));
    lstWanted->push_front(new Point(1, 0));
    lstWanted->push_front(new Point(2, 0));
    lstWanted->push_front(new Point(2, 1));
    lstWanted->push_front(new Point(2, 2));

    EXPECT_EQ(lst->size(), lstWanted->size());

    if (lst->size() == lstWanted->size()) {
        while (!lst->empty()) {
            p = lst->front();
            lst->pop_front();

            pWanted = lstWanted->front();
            lstWanted->pop_front();

            EXPECT_EQ(p, pWanted);
            delete (p);
            delete (pWanted);
        }
    }
    else {
        while(!lst->empty()) {
            p = lst->front();
            lst->pop_front();
            delete(p);
        }


        while(!lstWanted->empty()) {
            p = lstWanted->front();
            lstWanted->pop_front();
            delete(p);
        }
    }
    delete(lst);
    delete(lstWanted);
}

/**
 * Tests the function getExpirience.
 */
TEST_F(DriverTest, getExpiriecse) {
    EXPECT_EQ(20,driver->getExp());
    driver->setEx(25);
    EXPECT_EQ(25,driver->getExp());
}