#include <iostream>

class Shape {
public:
    virtual double area() = 0;
};
class Ellipse : public Shape { // Овал
public:
    double area() override { return 0.0; }
};
class Circle : public Ellipse { // Круг
public:
    double area() override { return 0.0; }
};
class Rectangle : public Shape { // Прямоугольник
public:
    double area() override { return 0.0; }
};
class Square : public Rectangle { // Квадрат
public:
    double area() override { return 0.0; }
};


bool IsCircle(const Shape& shape)
{
    if (dynamic_cast<const Circle*>(&shape))
        return true;
    return false;
}

bool IsEllipse(const Shape& shape)
{
    if (IsCircle(shape))
        return false;
    if (dynamic_cast<const Ellipse*>(&shape))
        return true;
    return false;
}

bool IsSquare(const Shape& shape)
{
    if (dynamic_cast<const Square*>(&shape))
        return true;
    return false;
}

bool IsRectangle(const Shape& shape)
{
    if (IsSquare(shape))
        return false;
    if (dynamic_cast<const Rectangle*>(&shape))
        return true;
    return false;
}

int main(int argc, const char *argv[])
{
    Square sq;
    Rectangle rt;
    Ellipse el;
    Circle ci;
    
    Shape *a[] = { &sq, &rt, &el, &ci };
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Rectangle " << (IsRectangle(*a[i]) ? "true" : "false") << '\n';
        std::cout << "Square " << (IsSquare(*a[i]) ? "true" : "false") << '\n';
        std::cout << "Ellipse " << (IsEllipse(*a[i]) ? "true" : "false") << '\n';
        std::cout << "Circle " << (IsCircle(*a[i]) ? "true" : "false") << "\n\n";
    }
    
    return EXIT_SUCCESS;
}
