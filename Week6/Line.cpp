//
// Created by victo on 14/01/2020.
//

#include <iostream>
#include "Line.h"

Line::Line(double x1, double x2, double y1, double y2, double width)
        : x1(x1), x2(x2), y1(y1), y2(y2), width(width) {
}

void Line::OutputSVG(std::ostream &output) const {
    constexpr char q_c = '"';
//    double h = getFrameHeight();
//    double w = getFrameWidth();
    output << "<line x1=" << q_c << x1 << q_c << " y1=" << q_c << y1 << q_c << " x2=" << q_c << x2 << q_c << " y2="
           << q_c << y2 << q_c << " style=" << q_c << "stroke:rgb(0,0,0);stroke-width:" << width << q_c
           << " />";
}

double Line::getFrameWidth() const {
    if (x1 > x2) return x1;
    else return x2;
}

double Line::getFrameHeight() const {
    if (y1 > y2) return y1;
    else return y2;
}

//<< "<!DOCTYPE html><html><body><svg height=" << q_c << h << q_c << " width=" << q_c << w << q_c<< "> CONTENT </svg></body></html>"