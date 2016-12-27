//
// Created by adi on 03/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;
using testing::Test;
using testing::Eq;

#include "Point.h"
#include "PointNode.h"
namespace {
    class PointNodeTest : public ::testing::Test {
    public:
        Point *data, *p;
        PointNode * t;
        PointNode * next;
        /**
        * Setting things up for the tests.
        */

        void SetUp(){
            p = new Point(0,0);
            data = new Point (0,0);
            next = new PointNode(*data);
            t = new PointNode(*data);
        }
        /**
        * Deletes objets allocated in 'SetUp' function.
        */
        void TearDown() {
            delete(data);
            delete (t);
            delete(next);
        }
    };
}
/**
*check if the function returns the data
*/
TEST_F(PointNodeTest,getdata){
    EXPECT_EQ(p,t->getData());
}
/**
*check if the function returns the next pointer
*/
TEST_F(PointNodeTest,getnext){
    EXPECT_EQ(t,next);
}
/**
*check if the function sets the next pointer
*/
TEST_F(PointNodeTest,setnext){
    next->setNext(t);
    EXPECT_EQ(t,next->getNext());
}
/**
*check if the function knows if the next difined
*/
TEST_F(PointNodeTest,isnexdifined){
    EXPECT_FALSE(t->isNextDifined());
}
