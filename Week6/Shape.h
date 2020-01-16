//
// Created by victo on 09/01/2020.
//

#ifndef CPPWEEK6_SHAPE_H
#define CPPWEEK6_SHAPE_H


#include <ostream>

class Shape {
public:
    Shape() {}

    virtual void OutputSVG(std::ostream &output) const = 0;

    virtual double getFrameHeight() const = 0;

    virtual double getFrameWidth() const = 0;

    virtual ~Shape() {}
};


#endif //CPPWEEK6_SHAPE_H
