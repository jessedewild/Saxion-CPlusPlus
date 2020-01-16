#include "AllocateStatistics.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

void CreateLine(std::vector<std::shared_ptr<Shape>> &shapes, double x1, double y1, double x2, double y2, double width) {
    shapes.push_back(std::make_shared<Line>(x1, x2, y1, y2, width));
}

void CreateCircle(std::vector<std::shared_ptr<Shape> > &shapes, double x1, double y1, double radius) {
    shapes.push_back(std::make_shared<Circle>(x1, y1, radius));
}

struct FigureCount {
    unsigned int circles = 0;
    unsigned int lines = 0;
};

std::vector<std::shared_ptr<Shape>> LoadFigure(std::string const &filename) {

    std::vector<std::shared_ptr<Shape>> shapes;

    std::ifstream input(filename);

    while (true) {
        std::string type;
        input >> type;
        if (input.eof()) break;
        else if (input.fail()) throw std::runtime_error("Failed to parse file");
        else if (type == "circle") {
            double vals[3];
            for (double &val : vals) {
                input >> val;
                if (input.fail()) throw std::runtime_error("Failed to parse file");
            }
            CreateCircle(shapes, vals[0], vals[1], vals[2]);
        } else if (type == "line") {
            double vals[5];
            for (double &val : vals) {
                input >> val;
                if (input.fail()) throw std::runtime_error("Failed to parse file");
            }
            CreateLine(shapes, vals[0], vals[1], vals[2], vals[3], vals[4]);
        } else throw std::runtime_error("Unknown type: " + type);
    }

    return shapes;
}

void RenderImage(const std::vector<std::shared_ptr<Shape>>& shapes) {
    std::ofstream output("figure.html");
    std::string content;

    //start svg file
    constexpr char q_c = '"';
    output << "<!DOCTYPE html><html><body><svg height=" << q_c << 1000 << q_c << " width=" << q_c << 1000 << q_c << ">";

    //fill content
    for (auto & shape : shapes) {
        shape->OutputSVG(output);
    }

    //end svg file
    output << "</svg></body></html>";

}

void Run() {
    // Load and generate the figure from this function
    std::vector<std::shared_ptr<Shape>> figure = LoadFigure("figure.txt");


    FigureCount counter = FigureCount();
    for (unsigned int i = 0; i < figure.size(); ++i) {
        if (instanceof<Circle>(&*figure.at(i))) {
            counter.circles++;
        } else {
            counter.lines++;
        }
    }

    std::cout << "Shapes: " << counter.lines + counter.circles << ", circles: " << counter.circles << ", lines: "
              << counter.lines << std::endl;

    RenderImage(figure);


//    alloc_tracker.Dump();
    // Memory should be automatically be deallocated
    // at the end of this function


}

int main() {

    Run();

    // Stop memory tracking and write the graph file now
    alloc_tracker.StopTracking();
    alloc_tracker.DumpPeaks();
    alloc_tracker.WriteGraph();
    return 0;
}
