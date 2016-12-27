//
// Created by adi on 03/12/16.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;
using testing::Test;
using testing::Eq;

#include "Point.h"
#include "GridNode.h"
namespace {
    /**
     * This class make tests to the clas GrideNode.
     */
    class GridNodeTest : public ::testing::Test {
    public:
        GridNode *t;
        Point * place;
        /**
        * Setting things up for the tests.
        */
        void SetUp() {
            t = new GridNode(0,0);
        }

        /**
         * Deletes objets allocated in 'SetUp' function.
         */
        void TearDown() {
            delete(t);
        }
    };
}

/**
 * Checks the function get place.
 */
TEST_F(GridNodeTest,getplace){
    Point *p2 = new Point(0,0);
    place = t->getPlace();
    EXPECT_EQ(p2,place);
}

/**
 * Checks the functions isObstical setAsObstical snd removeObstical.
 */
TEST_F(GridNodeTest,obstacle){
    EXPECT_FALSE(t->isObstical());
    t->setAsOnbltical();
    EXPECT_TRUE(t->isObstical());
    t->removeObstical();
    EXPECT_FALSE(t->isObstical());
}
