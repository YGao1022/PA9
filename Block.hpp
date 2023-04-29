//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//#include <SFML/Graphics.hpp>
//#include "Game.h"
//using namespace std;
//
////const sf::Color colors[NUM_COLORS] = { sf::Color::Color(255, 165, 0), sf::Color::Blue, sf::Color::Green, sf::Color::Yellow, sf::Color::Red, sf::Color::Magenta };
//
//class Block {
//public:
//    Block(sf::Color color) : color(color) {}
//    virtual ~Block() {}
//    virtual sf::RectangleShape getShape(float x, float y, float width, float height) const = 0;
//    virtual void changeColor(sf::Color newColor) { color = newColor; }
//    sf::Color getColor() const { return color; }
//private:
//    sf::Color color;
//};
//
//class OrangeBlock : public Block {
//public:
//    OrangeBlock() : Block(colors[0]) {}
//    virtual sf::RectangleShape getShape(float x, float y, float width, float height) const {
//        sf::RectangleShape shape(sf::Vector2f(width, height));
//        shape.setPosition(x, y);
//        shape.setFillColor(getColor());
//        return shape;
//    }
//};
//
//class BlueBlock : public Block {
//public:
//    BlueBlock() : Block(colors[1]) {}
//    virtual sf::RectangleShape getShape(float x, float y, float width, float height) const {
//        sf::RectangleShape shape(sf::Vector2f(width, height));
//        shape.setPosition(x, y);
//        shape.setFillColor(getColor());
//        return shape;
//    }
//};
//
//class GreenBlock : public Block {
//public:
//    GreenBlock() : Block(colors[2]) {}
//    virtual sf::RectangleShape getShape(float x, float y, float width, float height) const {
//        sf::RectangleShape shape(sf::Vector2f(width, height));
//        shape.setPosition(x, y);
//        shape.setFillColor(getColor());
//        return shape;
//    }
//};
//
//class YellowBlock : public Block {
//public:
//    YellowBlock() : Block(colors[3]) {}
//    virtual sf::RectangleShape getShape(float x, float y, float width, float height) const {
//        sf::RectangleShape shape(sf::Vector2f(width, height));
//        shape.setPosition(x, y);
//        shape.setFillColor(getColor());
//        return shape;
//    }
//};
//
//class RedBlock : public Block {
//public:
//    RedBlock() : Block(colors[4]) {}
//    virtual sf::RectangleShape getShape(float x, float y, float width, float height) const {
//        sf::RectangleShape shape(sf::Vector2f(width, height));
//        shape.setPosition(x, y);
//        shape.setFillColor(getColor());
//        return shape;
//    }
//};
//
//class MagentaBlock : public Block {
//public:
//    MagentaBlock() : Block(colors[5]) {}
//    virtual sf::RectangleShape getShape(float x, float y, float width, float height) const {
//        sf::RectangleShape shape(sf::Vector2f(width, height));
//        shape.setPosition(x, y);
//        shape.setFillColor(getColor());
//        return shape;
//    }
//};
