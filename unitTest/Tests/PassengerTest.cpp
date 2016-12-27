#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;
using testing::Test;
using testing::Eq;
#include "Point.h"
#include "Definitions.h"

namespace {
    /**
     * This class takes tests to the class Passanger.
     */
    class PassengerTest : public ::testing::Test {
    public:
        Passenger * pass;
        /**
         * Setting things up for the tests.
         */
        void SetUp() {
            pass = new Passenger(Point(0,0), Point(2,2));
        }
        /**
         * Deletes objets allocated in 'SetUp' function.
         */
        void TearDown() {
            delete(pass);
        }
    };
}

/**
 * Checks the function getSP
 */
TEST_F(PassengerTest,getsp){
    Point *p = new Point (1,1);
    Point * passangerStart = pass->getSP();
    EXPECT_EQ(p,passangerStart);
    delete(p);
}

/**
 * Checks the functions getDP
 */
TEST_F(PassengerTest,getdp){
    Point *p = new Point (2,1);
    EXPECT_EQ(p,pass->getDP());
}
