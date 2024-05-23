#include <iostream>
#include <cmath>

using namespace std;
class Shape {
public:
    virtual double area() const{
        return 0.0; 
    }
   virtual  double perimeter() const{
        return 0.0; 
    }
    virtual void display() const{
        cout << "Shape" << endl;
    }
    virtual ~Shape() {}  
};

class Circle : public Shape {
private:
    double radius;

public:
    void getRadius(double r){
        radius=r;
    }

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void display() const override {
        cout << "Circle with radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, breadth;

public:
    void setDimension(double l, double b){
        length=l;
        breadth=b;
    }

    double area() const override {
        return length * breadth;
    }

    double perimeter() const override {
        return 2 * (length + breadth);
    }

    void display() const override {
        cout << "Rectangle with length: " << length << " and breadth: " << breadth << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

double totalArea( const Shape& shape1, const Shape& shape2) {
    return shape1.area() + shape2.area();
}

inline double totalPerimeter( const Shape& shape1, const Shape& shape2) {
    return shape1.perimeter() + shape2.perimeter();
}

int main() {
    Circle* circle = new Circle();
    circle->getRadius(5.0);
    Rectangle* rectangle = new Rectangle();
    rectangle->setDimension(4.0, 6.0);
    circle->display();
    rectangle->display();
    cout << "Total Area: " << totalArea(*circle, *rectangle) << endl;
    cout << "Total Perimeter: " << totalPerimeter(*circle, *rectangle) << endl;
    delete circle;
    delete rectangle;

    return 0;
}