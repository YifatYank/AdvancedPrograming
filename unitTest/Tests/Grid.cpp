//
// Created by yifat on 01/12/16.
//

#include "Grid.h"
#include "BfsGrid.h"
typedef Point * pPoint;

Grid::Grid(int x, int y) {
    this->height = x + 2;
    this->width = y + 2;
    this->initiateGrid();
}

bool Grid::isObstical(int x, int y) {
    x += 1;
    y += 1;

    // Checks grid borders.
    if(x < 0) {
        return true;
    }
    if(y < 0) {
        return true;
    }
    if(x > height -1) {
        return true;
    }
    if(y > width -1) {
        return true;
    }
    return this->grideWorld[x][y]->isObstical();
}

bool Grid::isObstical(Point p) {
    int x,y;
    x = p.getX();
    y = p.getY();
    return Grid::isObstical(x,y);
}

void Grid::setObstical(int x, int y) {
    x += 1;
    y += 1;
    // Checks grid borders.
    if(!((x < 0) || (y < 0) || (x > height -1) || (y > width -1))) {
        grideWorld[x][y]->setAsOnbltical();
    }
}

void Grid::setObstical(Point p) {
    setObstical(p.getX(), p.getY());
}

void Grid::removeObstical(int x, int y) {
    x+=1;
    y+=1;
    if (!((x < 0) || (y < 0) || (x > height -1) || (y > width -1))) {
        grideWorld[x][y]->removeObstical();
    }
}

void Grid::removeObstical(Point  p) {
    removeObstical(p.getX(), p.getY());
}

Grid::~Grid() {
    int index, jndex;
    for(index = 0; index < height; ++index)
    {
        for(jndex = 0; jndex < width; ++jndex) {
            delete(grideWorld[index][jndex]);
        }
        delete [](grideWorld[index]);
    }
    delete [](grideWorld);
}


void Grid::initiateGrid() {
    int * num;
    int index, jndex;

    // Initiate the height of the grid
    this->grideWorld = new GridNode **[height];

    // Initiate the width of the grid.
    for(index = 0; index < height; ++index)
    {
        // Initiate the gtid width
        grideWorld[index] = new GridNode *[width];
    }

    for(index = 0; index < this->height; ++index) {
        for(jndex = 0; jndex < this->width; ++jndex) {
            this->grideWorld[index][jndex] = new GridNode(index,jndex);
            this->grideWorld[index][jndex]->setAsOnbltical();
        }
    }


    for(index = 1; index < height - 1; ++index)
    {
        for(jndex = 1; jndex < width - 1; ++ jndex)
        {
            grideWorld[index][jndex]->removeObstical();
        }
    }
}

list<pPoint> * Grid::getNeighborsOfPoint(Point * p) {
    Point temp(p->getX() + 1,p->getY() + 1);
    Point *  tempPointer;

    list<pPoint> * lst = new list<pPoint>();
    if(!this->grideWorld[temp.getX() - 1][temp.getY()]->isObstical()) {
        tempPointer = this->grideWorld[temp.getX() - 1][temp.getY()]->getPlace();
        lst->push_front(new Point(tempPointer->getX() - 1, tempPointer->getY() - 1));
    }
    if(!this->grideWorld[temp.getX()][temp.getY() + 1]->isObstical()) {
        tempPointer = this->grideWorld[temp.getX()][temp.getY() + 1]->getPlace();
        lst->push_front(new Point(tempPointer->getX() - 1, tempPointer->getY() - 1));
    }
    if(!this->grideWorld[temp.getX() + 1][temp.getY()]->isObstical()) {
        tempPointer = this->grideWorld[temp.getX() + 1][temp.getY()]->getPlace();
        lst->push_front(new Point(tempPointer->getX() - 1, tempPointer->getY() - 1));

    }
    if(!this->grideWorld[temp.getX()][temp.getY() - 1]->isObstical()) {
        tempPointer = this->grideWorld[temp.getX()][temp.getY() - 1]->getPlace();
        lst->push_front(new Point(tempPointer->getX() - 1, tempPointer->getY() - 1));
    }
    return lst;
}

list<Point *> *Grid::getSortesrPath(Point *start, Point *end) {
    start = this->grideWorld[start->getX() + 1][start->getY() + 1]->getPlace();
    end = this->grideWorld[end->getX() + 1][end->getY() + 1]->getPlace();
    Point * tempPoint;
    list <pPoint>  * lstToReturn, * tempList;

    if (this->grideWorld[start->getX()][start->getY()]->isObstical()) {
        return new list<pPoint>();
    }
    if(this->grideWorld[end->getX()][end->getY()]->isObstical()) {
        return new list<pPoint>();
    }


    lstToReturn = (list <pPoint> *)BfsGrid::getShortestPath(this, start, end);

    tempList = new list<pPoint>();

    while(!lstToReturn->empty()){
        tempPoint = lstToReturn->front();
        lstToReturn->pop_front();
        tempList->push_front(tempPoint);
    }

    while(!tempList->empty()) {
        tempPoint = tempList->front();
        tempList->pop_front();
        tempPoint->setX(tempPoint->getX() - 1);
        tempPoint->setY(tempPoint->getY() - 1);
        lstToReturn->push_front(tempPoint);
    }

    delete(tempList);

    return lstToReturn;
}