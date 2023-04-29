#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace std;

//In this code, we define a base class called Circle, which has a protected member radius and a virtual function getShape() that takes x and y coordinates as arguments. 
//The two derived classes, GreenCircle and RedCircle, inherit from the base class Circle. 
//They define their own implementations of the getShape() //function, setting the fill color to green or red, respectively.

class Circle {
public:
    Circle(float radius) : radius(radius) {}
    virtual ~Circle() {}
    virtual sf::CircleShape getShape(float x, float y) const = 0;

protected:
    float radius;
};

class GreenCircle : public Circle {
public:
    GreenCircle() : Circle(8.0f) {}

    virtual sf::CircleShape getShape(float x, float y) const {
        sf::CircleShape shape(radius);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Green);
        shape.setOutlineThickness(3);
        shape.setOutlineColor(sf::Color(90, 90, 90));
        return shape;
    }
};

class RedCircle : public Circle {
public:
    RedCircle() : Circle(8.0f) {}

    virtual sf::CircleShape getShape(float x, float y) const {
        sf::CircleShape shape(radius);
        shape.setPosition(x, y);
        shape.setFillColor(sf::Color::Red);
        shape.setOutlineThickness(3);
        shape.setOutlineColor(sf::Color(90, 90, 90));
        return shape;
    }
};