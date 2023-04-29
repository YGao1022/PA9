#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

//#include "Block.hpp"
#include "Circle.hpp"

#define NUM_COLORS 6
#define NUM_SQUARES 4
#define NUM_TRIES 10
static sf::Color colors[NUM_COLORS] = { sf::Color::Color(255, 165, 0), sf::Color::Blue, sf::Color::Green, sf::Color::Yellow, sf::Color::Red, sf::Color::Magenta };

using namespace std;

class Game {
public:
    Game() {};
    void runGame();
    void displayGameRules(); //display the game rule in sfml window
    void displaySquares(sf::RectangleShape squares[NUM_SQUARES], sf::Color colors[NUM_COLORS], int* currentColors);
    vector<int> generateRandomPattern(); //generate a correct pattern as the answer

    void changeColor(sf::RectangleShape squares[NUM_SQUARES], sf::Color colors[NUM_COLORS], int* currentColors, sf::Vector2i mousePos);

    int checkCorrectness(vector<int> pattern, int* currentColors);
    void checkWon(sf::RenderWindow& window, sf::Text checkButton, bool gameWon, int triesLeft, sf::Font& font); //display win or lose
    void revealPattern(vector<int> pattern, sf::RectangleShape squares[NUM_SQUARES], sf::Color colors[NUM_COLORS], int triesLeft);

    //void displayRecord(sf::RectangleShape one[NUM_SQUARES], sf::RectangleShape two[NUM_SQUARES], sf::RectangleShape three[NUM_SQUARES], sf::RectangleShape four[NUM_SQUARES], sf::RectangleShape five[NUM_SQUARES], sf::RectangleShape six[NUM_SQUARES], sf::RectangleShape seven[NUM_SQUARES], sf::RectangleShape eight[NUM_SQUARES], sf::RectangleShape nine[NUM_SQUARES], sf::RectangleShape ten[NUM_SQUARES], sf::CircleShape circles[6], sf::CircleShape circles2[6], sf::CircleShape circles3[6], sf::CircleShape circles4[6], sf::CircleShape circles5[6], sf::CircleShape circles6[6], sf::CircleShape circles7[6], sf::CircleShape circles8[6], sf::CircleShape circles9[6], sf::CircleShape circles10[6], int *currentColors, int triesLeft, int correctColors, sf::Color colors[6]);
    void displayRecord(Circle** circles, int* currentColors, int triesLeft, int correctColors, sf::Color colors[6]);

private:
    sf::RectangleShape one[NUM_SQUARES];
    sf::RectangleShape two[NUM_SQUARES];
    sf::RectangleShape three[NUM_SQUARES];
    sf::RectangleShape four[NUM_SQUARES];
    sf::RectangleShape five[NUM_SQUARES];
    sf::RectangleShape six[NUM_SQUARES];
    sf::RectangleShape seven[NUM_SQUARES];
    sf::RectangleShape nine[NUM_SQUARES];
    sf::RectangleShape eight[NUM_SQUARES];
    sf::RectangleShape ten[NUM_SQUARES];




    sf::CircleShape circles[6];
    sf::CircleShape circles2[6];
    sf::CircleShape circles3[6];
    sf::CircleShape circles4[6];
    sf::CircleShape circles5[6];
    sf::CircleShape circles6[6];
    sf::CircleShape circles7[6];
    sf::CircleShape circles8[6];
    sf::CircleShape circles9[6];
    sf::CircleShape circles10[6];

};
