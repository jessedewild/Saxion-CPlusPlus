//
// Created by victo on 14/01/2020.
//

#include "Circle.h"

Circle::Circle(double x, double y, double r)
        : x(x), y(y), r(r) {
}

void Circle::OutputSVG(std::ostream &output) const {
//    constexpr char q_c = '"';
//    double h = getFrameHeight();
//    double w = getFrameWidth();
    output << R"(<circle cx=")" << x
           << R"(" cy=")" << y << R"(" r=")" << r
           << R"(" stroke="black" stroke-width="3" fill="white" />)";
}

double Circle::getFrameHeight() const {
    return y + r + 3; // stroke width
}

double Circle::getFrameWidth() const {
    return x + r + 3; //stroke width
}

//<< R"(<!DOCTYPE html><html><body><svg height=")" << h << R"(" width=")" << w << R"("> CONTENT </svg></body></html>)";