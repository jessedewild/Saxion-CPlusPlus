//
// Created by victo on 09/01/2020.
//

#ifndef CPPWEEK6_CIRCLE_H
#define CPPWEEK6_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
private:
    double x;
    double y;
    double r;

public:
    Circle(double x, double y, double r);

    void OutputSVG(std::ostream &output) const;

    double getFrameHeight() const;

    double getFrameWidth() const;
};


#endif //CPPWEEK6_CIRCLE_H
