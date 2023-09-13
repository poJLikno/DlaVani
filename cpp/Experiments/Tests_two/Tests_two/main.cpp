#include <iostream>
#include "Shapes.h"

using figure_type = float;

int main(int argc, const char * argv[])
{
    Shapes2d::Shape<figure_type> *figure = nullptr;
    figure = new Shapes2d::Circle<figure_type>(1.f);
    
    if (dynamic_cast<const Shapes2d::Ellipse<figure_type> *>(figure))
    {
        std::cout << "\r\n";
        figure->what();
        std::cout << figure->get_area() << "\r\n\r\n";
    }
    
    delete figure;
    figure = nullptr;
    
    return 0;
}
