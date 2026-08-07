// Напишете програма, която в безкраен цикъл чете двойки фигури на всяка своя итерация и сравнява лицата им. Използвайте namespaces, enums и structs за представяне и обработка на данните.
// можете да добавите и функционалност, която сравнява фигурите по "компактност", т.е. коя има по-малко отношение лице/периметър

#include <iostream>

namespace Constants {
    const double PI = 3.14159265358979323846;
    const double EPSILON = 1e-5;
}

enum class ShapeType {
    CIRCLE,
    TRIANGLE,
    RECTANGLE
};

namespace CircleNs {
    struct Circle {
        double radius;
    };

    void read(Circle& circle) {
        std::cin >> circle.radius;
    }

    double getArea(const Circle& circle) {
        return Constants::PI * circle.radius * circle.radius;
    }
}

namespace TriangleNs {
    struct Triangle {
        double a;
        double b;
        double c;
    };

    void read(Triangle& triangle) {
        std::cin >> triangle.a >> triangle.b >> triangle.c;
    }

    double getArea(const Triangle& triangle) {
        double s = (triangle.a + triangle.b + triangle.c) / 2.0;
        return sqrt(s * (s - triangle.a) * (s - triangle.b) * (s - triangle.c));
    }
}

namespace RectangleNs {
    struct Rectangle {
        double width;
        double height;
    };

    void read(Rectangle& rectangle) {
        std::cin >> rectangle.width >> rectangle.height;
    }

    double getArea(const Rectangle& rectangle) {
        return rectangle.width * rectangle.height;
    }
}

bool areEqual(double d1, double d2) {
    return abs(d1 - d2) < Constants::EPSILON;
}

double getAreaShape() {
    int type;
    std::cout << "Choose shape type(0 -> circle, 1 -> triangle, 2 -> rectangle): ";
    std::cin >> type;

    switch ((ShapeType)type) {
        case ShapeType::CIRCLE: {
            CircleNs::Circle c;
            CircleNs::read(c);
            return CircleNs::getArea(c);
        }
        case ShapeType::TRIANGLE: {
            TriangleNs::Triangle t;
            TriangleNs::read(t);
            return TriangleNs::getArea(t);
        }
        case ShapeType::RECTANGLE: {
            RectangleNs::Rectangle r;
            RectangleNs::read(r);
            return RectangleNs::getArea(r);
        }
        default: return -1;
    }
}

int main() {
    while(true) {
        double area1 = getAreaShape();
        double area2 = getAreaShape();

        if (area1 == -1 || area2 == -1) {
            std::cout << "Invalid input" << std::endl;
            break;
        }

        if (areEqual(area1, area2)) {
            std::cout << "Both areas are equal: " << area1 << std::endl;
        } else if (area1 < area2) {
            std::cout << "Area of second shape is bigger: " << area2 << " > " << area1 << std::endl;
        } else {
            std::cout << "Area of first shape is bigger: " << area1 << " > " << area2 << std::endl;
        }        
    }
}