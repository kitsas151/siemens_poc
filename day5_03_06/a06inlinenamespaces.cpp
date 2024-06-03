#if 1

#include <iostream>
#include <cmath>

// Base namespace for geometric shapes
namespace Geometry {

// Initial version of the library
inline namespace v1 {
    struct Point {
        double x, y;
    };

    // Function to calculate the distance between two points
    double distance(const Point& p1, const Point& p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return std::sqrt(dx * dx + dy * dy);
    }
}

// Updated version of the library
inline namespace v2 {
    struct Circle {
        Point center;
        double radius;
    };

    // Function to calculate the area of a circle
    double area(const Circle& circle) {
        return 3.14159 * circle.radius * circle.radius;
    }
}

} // namespace Geometry

int main() {
    Geometry::Point p1{1.0, 2.0};
    Geometry::Point p2{4.0, 6.0};

    // Using the distance function from the initial version
    double dist = Geometry::distance(p1, p2);
    std::cout << "Distance between points: " << dist << std::endl;

    // Creating a circle using the updated version
    Geometry::Circle circle{{3.0, 4.0}, 2.5};
    double circleArea = Geometry::area(circle);
    std::cout << "Circle area: " << circleArea << std::endl;

    return 0;
}


#endif