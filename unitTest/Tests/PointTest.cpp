//
// Created by adi on 03/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;
using testing::Test;
using testing::Eq;

#include "Point.h"
namespace {
    class PointTest : public ::testing::Test {
    public:
        Point * t;
        /**
         * Setting things up for the tests.
         */
        void SetUp() {
            t= new Point(0,0);
        }
        /**
         * Deletes objets allocated in 'SetUp' function.
         */
        void TearDown() {
            delete(t);
        }
    };
};

/**
*check if the function returns x coordinate
*/
TEST_F(PointTest,getx){
    EXPECT_EQ(0,t->getX());
}
/**
*check if the function sets the x coordinate
*/
TEST_F(PointTest,setx){
    t->setX(2);
    EXPECT_EQ(2,t->getX());
}
/**
*check if the function returns the y coordinate
*/
TEST_F(PointTest,gety){
    EXPECT_EQ(0,t->getY());
}
/**
*check if the function sets the y coordinate
*/
TEST_F(PointTest,sety){
    t->setY(2);
    EXPECT_EQ(2,t->getY());
}
/**
*check if the function returns a string
*/
TEST_F(PointTest,getstring){
    string s = "(0,0)";
    EXPECT_EQ(s,*t->getString());
}
