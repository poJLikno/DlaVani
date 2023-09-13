#include <iostream>
#include "math.h"

class Num
{
public:
    int num;
    
    Num() : num(0) { std::cout << "Num con\r\n"; }
    Num(int l) : num(l) { std::cout << "Num con\r\n"; }
    Num(const Num &var) : num(var.num) { std::cout << "Num copy con\r\n"; }
    Num(const Num *var) : num(var->num) { std::cout << "Num point con\r\n"; }
    ~Num() { std::cout << "Num des\r\n"; }
};

void func(Num var)
{
    std::cout << var.num << "\r\n";
}

int main()
{
    Num b;
    b.num = 12;
    
    func(&b);
    
    for (double i = 0.0; i < 721.0; ++i)
    {
        double j = sin(i * 3.14 / 180.0);
        double d = asin(j) * 180.0 / 3.14;
        std::cout << i << "   " << j << "   " << ((((cos(i * 3.14 / 180.0) < 0) ? 180.0 - d : d) < 0) ? 360 + ((cos(i * 3.14 / 180.0) < 0) ? 180.0 - d : d) : ((cos(i * 3.14 / 180.0) < 0) ? 180.0 - d : d)) << "\r\n";
    }
    
    return 0;
}
