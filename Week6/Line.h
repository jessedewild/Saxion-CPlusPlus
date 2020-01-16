//
// Created by victo on 09/01/2020.
//

#ifndef CPPWEEK6_LINE_H
#define CPPWEEK6_LINE_H


#include "Shape.h"

class Line : public Shape {
private:
    double x1;
    double x2;
    double y1;
    double y2;
    double width;

public:
    Line(double x1, double x2, double y1, double y2, double width);

    void OutputSVG(std::ostream &output) const;

    double getFrameWidth() const;

    double getFrameHeight() const;
};


#endif //CPPWEEK6_LINE_H
