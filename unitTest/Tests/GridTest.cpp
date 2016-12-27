//
// Created by yifat on 03/12/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Point.h"
#include "Grid.h"
using namespace std;
using testing::Test;
using testing::Eq;

namespace {
    /**
     * Take tests for the class Grid.
     */
class GridTest : public ::testing::Test {
public:
    Grid * grid;
    /**
     * Setting things up for the tests.
     */
    void SetUp() {
        grid = new Grid(3,2);
    }

    /**
     * Deletes objets allocated in 'SetUp' function.
     */
    void TearDown() {
        delete(grid);
    }
};
}

/**
 * Checks the functions is obctical.
 */
TEST_F(GridTest, obstical) {
    EXPECT_FALSE(grid->isObstical(1,2));
    EXPECT_FALSE(grid->isObstical(Point(2,2)));

    grid->setObstical(1,2);
    grid->setObstical(Point(2,2));

    EXPECT_TRUE(grid->isObstical(1,2));
    EXPECT_TRUE(grid->isObstical(Point(2,2)));

    grid->removeObstical(1,2);
    grid->removeObstical(Point(2,2));

    EXPECT_FALSE(grid->isObstical(1,2));
    EXPECT_FALSE(grid->isObstical(Point(2,2)));
}

/**
 * Checks the function calculate path.
 */
TEST_F(GridTest, calculatePath ) {
    //grid.
    list<pPoint> *lstWanted;
    Point *pWanted , * p;
    Point * start, * end;
    start = new Point(0,0);
    end = new Point(1,2);

    list<pPoint> *lst = grid->getSortesrPath(start, end);

    lstWanted = new list<pPoint>();
    lstWanted->push_front(new Point(0, 0));
    lstWanted->push_front(new Point(1, 0));
    lstWanted->push_front(new Point(1, 1));
    lstWanted->push_front(new Point(1, 2));

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
    delete(start);
    delete(end);

}

/**
 * Checks the function get neibors.
 */
TEST_F(GridTest, getNiebors){
    list<pPoint> * wantedList = new list<pPoint>();
    list<pPoint> * neibors;
    Point * p, * pWanted;

    // Check neibors of point (1,1)
    wantedList->push_front(new Point(0,1));
    wantedList->push_front(new Point(1,0));

    p = new Point(0,0);
    neibors = grid->getNeighborsOfPoint(p);
    delete(p);

    EXPECT_EQ(neibors->size(), wantedList->size());

    if (neibors->size() == wantedList->size()) {
        while (neibors->empty()) {
            p = neibors->front();
            neibors->pop_front();

            pWanted = wantedList->front();
            wantedList->pop_front();

            EXPECT_EQ(p, pWanted);
            delete (p);
            delete (pWanted);
        }
    }
    else {
        while(neibors->empty()) {
            p = neibors->front();
            neibors->pop_front();
            delete(p);
        }


        while(wantedList->empty()) {
            p = wantedList->front();
            wantedList->pop_front();
            delete(p);
        }
    }
    delete(wantedList);
    delete(neibors);



    // Check neibors of point (1,1)
    grid->setObstical(0,1);

    wantedList = new list<pPoint>();

    wantedList->push_front(new Point(1,2));
    wantedList->push_front(new Point(2,1));
    wantedList->push_front(new Point(1,0));

    p = new Point(1,1);
    neibors = grid->getNeighborsOfPoint(p);
    delete(p);

    EXPECT_EQ(neibors->size(), wantedList->size());

    if (neibors->size() == wantedList->size()) {
        while (neibors->empty()) {
            p = neibors->front();
            neibors->pop_front();

            pWanted = wantedList->front();
            wantedList->pop_front();

            EXPECT_EQ(p, pWanted);
            delete (p);
            delete (pWanted);
        }
    }
    else {
        while(neibors->empty()) {
            p = neibors->front();
            neibors->pop_front();
            delete(p);
        }


        while(wantedList->empty()) {
            p = wantedList->front();
            wantedList->pop_front();
            delete(p);
        }
    }
    delete(wantedList);
    delete(neibors);

}