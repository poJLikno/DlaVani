#ifndef SHAPES_H
#define SHAPES_H

namespace Shapes2d
{
    // Interface Shape
    template <typename T>
    class Shape
    {
    protected:
        T a_, b_;
        
    public:
        Shape() : a_((T)0), b_((T)0) { std::cout << "Shape con\r\n"; }
        virtual ~Shape() { std::cout << "Shape des\r\n"; }
        
        virtual T get_area() const = 0;
        virtual void what() { std::cout << "What Shape\r\n"; }
    };
    
    // Rectangle
    template <typename T>
    class Rect : public Shape<T>
    {
    private:
        using Shape<T>::a_;
        using Shape<T>::b_;
        
    public:
        Rect(T width, T height) {
            std::cout << "Rect con\r\n";
            a_ = width;
            b_ = height;
        }
        ~Rect() override { std::cout << "Rect des\r\n"; }
        
        T get_area() const override { return a_ * b_; }
        void what() override { std::cout << "What Rect\r\n"; }
    };
    
    // Square
    template <typename T>
    class Square : public Rect<T>
    {
    public:
        Square(T side) : Rect<T>(side, side) { std::cout << "Square con\r\n"; }
        ~Square() override { std::cout << "Square des\r\n"; }
        
        //T get_area() const override { return 3; }
        void what() override { std::cout << "What Square\r\n"; }
    };
    
    //Ellipse
    template<typename T>
    class Ellipse : public Shape<T>
    {
    private:
        using Shape<T>::a_;
        using Shape<T>::b_;
        
    public:
        Ellipse(T a, T b) {
            std::cout << "Ellipse con\r\n";
            a_ = a;
            b_ = b;
        }
        ~Ellipse() override { std::cout << "Ellipse des\r\n"; }
        
        T get_area() const override { return 3.1415f * a_ * b_ ; };
        void what() override { std::cout << "What Ellipse\r\n"; }
    };
    
    // Circle
    template<typename T>
    class Circle : public Ellipse<T>
    {
    public:
        Circle(T r) : Ellipse<T>(r, r) { std::cout << "Circle con\r\n"; }
        ~Circle() override { std::cout << "Circle des\r\n"; }
        
        //T get_area() const override { return 3.1415f * a_ * b_ ; };
        void what() override { std::cout << "What Circle\r\n"; }
    };
}

#endif
