#include "Game.h"

void Game::runGame()
{
    // Initialize the random number generator
    srand(static_cast<unsigned>(time(0)));

    Game G;


    Circle* circles[6] = { 0 };
        
        //, * circles2[6], * circle3[6], * circles4[6], * circles5[6], * circles6[6], * circles7[6], * circles8[6], * circles9[6], * circles10[6];


    // Create the main game window
    sf::RenderWindow window(sf::VideoMode(850, 600), "Diary Lock Game");

    // Initialize the squares and their colors
    sf::RectangleShape squares[NUM_SQUARES];

    int currentColors[NUM_SQUARES] = { 0 };

    // Initialize the check button
    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text checkButton;
    checkButton.setFont(font);
    checkButton.setString("Check");
    checkButton.setCharacterSize(30);
    checkButton.setFillColor(sf::Color::White);
    checkButton.setPosition(500, 75);

    //display squares you can operate
    G.displayGameRules();
    G.displaySquares(squares, colors, currentColors);

    // Initialize the game state
    int triesLeft = NUM_TRIES;
    bool gameWon = false;
    vector<int> pattern = G.generateRandomPattern();

    int triesNow = triesLeft;

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Handle window close event
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Handle mouse click events if there are tries left and the game is not won
            if (event.type == sf::Event::MouseButtonPressed && triesLeft > 0 && !gameWon) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Change the color of the clicked square
                    G.changeColor(squares, colors, currentColors, mousePos);

                    // Check the current pattern against the generated pattern when the check button is clicked
                    if (checkButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        int prevTries = triesLeft;
                        triesLeft--;

                        int correctColors = checkCorrectness(pattern, currentColors);

                        // Update the game state based on the number of correct colors
                        if (correctColors == NUM_SQUARES) {
                            gameWon = true;
                        }
                        else {
                            std::cout << "Correct colors: " << correctColors << ", Incorrect colors: " << (NUM_SQUARES - correctColors) << std::endl;
                        }

                        //record the tried patterns
                        //G.displayRecord(one, two, three, four, five, six, seven, eight, nine, ten, circles, circles2, circles3, circles4, circles5, circles6, circles7, circles8, circles9, circles10, currentColors, triesLeft, correctColors, colors);
                        G.displayRecord(circles, currentColors, triesLeft, correctColors, colors);

                    }
                }
            }
        }

        // Clear the window for drawing
        window.clear(sf::Color(128, 128, 128));

        // Display the appropriate game state message (win/lose/tries left)
        G.checkWon(window, checkButton, gameWon, triesLeft, font);

        //reveal pattern
        G.revealPattern(pattern, squares, colors, triesLeft);

        // Draw the squares
        for (int i = 0; i < NUM_SQUARES; i++) {
            window.draw(squares[i]);
            window.draw(one[i]);
            window.draw(two[i]);
            window.draw(three[i]);
            window.draw(four[i]);
            window.draw(five[i]);
            window.draw(six[i]);
            window.draw(seven[i]);
            window.draw(eight[i]);
            window.draw(nine[i]);
            window.draw(ten[i]);



            sf::CircleShape C1a = circles[i]->getShape(100 * (i + 1) - 60 * i - 50, 200);
            window.draw(C1a);

            delete circles;
            //window.draw(circles[i]);
            //window.draw(circles2[i]);
            //window.draw(circles3[i]);
            //window.draw(circles4[i]);
            //window.draw(circles5[i]);
            //window.draw(circles6[i]);
            //window.draw(circles7[i]);
            //window.draw(circles8[i]);
            //window.draw(circles9[i]);
            //window.draw(circles10[i]);

        }

        // Display the window contents
        window.display();
    }

}


void Game::displayGameRules() {
    // Create a new SFML window for the game rules
    sf::RenderWindow window(sf::VideoMode(1300, 500), "Game Rules");

    // Create a font for the text
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Create a text object for the game rules
    sf::Text rules;
    rules.setFont(font);
    rules.setCharacterSize(20);
    rules.setString("Game Rules:\n\nThe diary lock has a 4-digit password, each digit is represented by a square filled with a random color (orange, blue, green, red, or purple).}, \n\nThe default color of the 4 squares is orange. You can click on the block to change the color of any of the squares.\n\nOnce you think you are ready, click on the 'check' button to check if your 4 square pattern is correct.\n\nIf your pattern is incorrect, the system will prompt you that how many squares in your pattern are correct and how many are wrong.\n\nTo win the game, your color pattern of all 4 squares must match the randomly generated password.\n\nYou have 10 turns to try to enter the 4-digit password. The correct color pattern will be revealed after 10 tries or when you win the game.\n\n\nOnce you have read the gamerules, close this window and start your game.");
    rules.setPosition(25, 25);

    // Main loop for the game rules window
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close the window if the close button is clicked
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Draw the game rules text
        window.draw(rules);

        // Display the window
        window.display();
    }
}

void Game::displaySquares(sf::RectangleShape squares[NUM_SQUARES], sf::Color colors[NUM_COLORS], int *currentColors)
{
    for (int i = 0; i < NUM_SQUARES; i++) {
        squares[i].setSize(sf::Vector2f(50, 50));
        squares[i].setPosition(100 * (i + 1) - 10 * i, 75);
        squares[i].setFillColor(colors[currentColors[i]]);
    }
}


void Game::checkWon(sf::RenderWindow& window, sf::Text checkButton, bool gameWon, int triesLeft, sf::Font& font) {
    window.draw(checkButton);

    if (gameWon)
    {
        sf::Text winText;
        winText.setFont(font);
        winText.setString("You won!");
        winText.setCharacterSize(50);
        winText.setFillColor(sf::Color::White);
        winText.setPosition(500, 500);
        window.draw(winText);
    }
    else if (triesLeft == 0)
    {
        sf::Text loseText;
        loseText.setFont(font);
        loseText.setString("You lost!");
        loseText.setCharacterSize(50);
        loseText.setFillColor(sf::Color::White);
        loseText.setPosition(500, 500);
        window.draw(loseText);

        sf::Text revealPattern;
        revealPattern.setFont(font);
        revealPattern.setString("The correct pattern was:");
        revealPattern.setCharacterSize(30);
        revealPattern.setFillColor(sf::Color::White);
        revealPattern.setPosition(100, 25);
        window.draw(revealPattern);

    }
    else
    {
        sf::Text triesLeftText;
        triesLeftText.setFont(font);
        triesLeftText.setString("Tries left: " + std::to_string(triesLeft));
        triesLeftText.setCharacterSize(30);
        triesLeftText.setFillColor(sf::Color::White);
        triesLeftText.setPosition(500, 500);
        window.draw(triesLeftText);
    }
}


vector<int> Game::generateRandomPattern()
{
    std::vector<int> pattern;
    for (int i = 0; i < NUM_SQUARES; i++) {
        pattern.push_back(rand() % NUM_COLORS);
    }
    return pattern;
}




void Game::revealPattern(vector<int> pattern, sf::RectangleShape squares[NUM_SQUARES], sf::Color colors[NUM_COLORS], int triesLeft)
{
    if (triesLeft == 0)
    {
        for (int i = 0; i < NUM_SQUARES; i++)
        {
            squares[i].setFillColor(colors[pattern[i]]);
        }
    }
}

void Game::changeColor(sf::RectangleShape squares[NUM_SQUARES], sf::Color colors[NUM_COLORS], int* currentColors, sf::Vector2i mousePos)
{
    for (int i = 0; i < NUM_SQUARES; i++) {
        if (squares[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
            currentColors[i] = (currentColors[i] + 1) % NUM_COLORS;
            squares[i].setFillColor(colors[currentColors[i]]);
        }
    }
}

int Game::checkCorrectness(vector<int> pattern, int* currentColors)
{
    int correctColors = 0;
    for (int i = 0; i < NUM_SQUARES; i++) {
        if (currentColors[i] == pattern[i]) {
            correctColors++;
        }
    }
    return correctColors;
}




void Game::displayRecord(Circle** circles, int* currentColors, int triesLeft, int correctColors, sf::Color colors[6])
{

    if (triesLeft == 9)
    {
        for (int i = 0; i < NUM_SQUARES; i++) {
            one[i].setSize(sf::Vector2f(30, 30));
            one[i].setPosition(100 * (i + 1) - 60 * i - 50, 200);
            one[i].setFillColor(colors[currentColors[i]]);

            //draw dots for prompting the user
            if (correctColors > 0)
            {
                circles[i] = new GreenCircle();
                correctColors--;
            }
            else
            {
                circles[i] = new RedCircle();
            }
            circles[i]->getShape(100 * (i + 1) - 60 * i - 42 + 200, 175);
        }
    }
    /*  else if (triesLeft == 8)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              two[i].setSize(sf::Vector2f(30, 30));
              two[i].setPosition(100 * (i + 1) - 60 * i + 150, 200);
              two[i].setFillColor(colors[currentColors[i]]);

              circles2[i].setRadius(8);
              circles2[i].setPosition(100 * (i + 1) - 60 * i - 42 + 200, 175);
              circles2[i].setOutlineThickness(3);
              circles2[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles2[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles2[i].setFillColor(sf::Color::Red);
              }
          }


      }
      else if (triesLeft == 7)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              three[i].setSize(sf::Vector2f(30, 30));
              three[i].setPosition(100 * (i + 1) - 60 * i + 350, 200);
              three[i].setFillColor(colors[currentColors[i]]);

              circles3[i].setRadius(8);
              circles3[i].setPosition(100 * (i + 1) - 60 * i - 42 + 400, 175);
              circles3[i].setOutlineThickness(3);
              circles3[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles3[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles3[i].setFillColor(sf::Color::Red);
              }
          }
      }
      else if (triesLeft == 6)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              four[i].setSize(sf::Vector2f(30, 30));
              four[i].setPosition(100 * (i + 1) - 60 * i + 550, 200);
              four[i].setFillColor(colors[currentColors[i]]);

              circles4[i].setRadius(8);
              circles4[i].setPosition(100 * (i + 1) - 60 * i - 42 + 600, 175);
              circles4[i].setOutlineThickness(3);
              circles4[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles4[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles4[i].setFillColor(sf::Color::Red);
              }
          }
      }
      else if (triesLeft == 5)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              five[i].setSize(sf::Vector2f(30, 30));
              five[i].setPosition(100 * (i + 1) - 60 * i - 50, 300);
              five[i].setFillColor(colors[currentColors[i]]);

              circles5[i].setRadius(8);
              circles5[i].setPosition(100 * (i + 1) - 60 * i - 42, 275);
              circles5[i].setOutlineThickness(3);
              circles5[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles5[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles5[i].setFillColor(sf::Color::Red);
              }
          }

      }
      else if (triesLeft == 4)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              six[i].setSize(sf::Vector2f(30, 30));
              six[i].setPosition(100 * (i + 1) - 60 * i + 150, 300);
              six[i].setFillColor(colors[currentColors[i]]);

              circles6[i].setRadius(8);
              circles6[i].setPosition(100 * (i + 1) - 60 * i - 42 + 200, 275);
              circles6[i].setOutlineThickness(3);
              circles6[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles6[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles6[i].setFillColor(sf::Color::Red);
              }
          }

      }
      else if (triesLeft == 3)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              seven[i].setSize(sf::Vector2f(30, 30));
              seven[i].setPosition(100 * (i + 1) - 60 * i + 350, 300);
              seven[i].setFillColor(colors[currentColors[i]]);

              circles7[i].setRadius(8);
              circles7[i].setPosition(100 * (i + 1) - 60 * i - 42 + 400, 275);
              circles7[i].setOutlineThickness(3);
              circles7[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles7[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles7[i].setFillColor(sf::Color::Red);
              }
          }
      }
      else if (triesLeft == 2)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              eight[i].setSize(sf::Vector2f(30, 30));
              eight[i].setPosition(100 * (i + 1) - 60 * i + 550, 300);
              eight[i].setFillColor(colors[currentColors[i]]);

              circles8[i].setRadius(8);
              circles8[i].setPosition(100 * (i + 1) - 60 * i - 42 + 600, 275);
              circles8[i].setOutlineThickness(3);
              circles8[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles8[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles8[i].setFillColor(sf::Color::Red);
              }
          }
      }
      else if (triesLeft == 1)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              nine[i].setSize(sf::Vector2f(30, 30));
              nine[i].setPosition(100 * (i + 1) - 60 * i - 50, 400);
              nine[i].setFillColor(colors[currentColors[i]]);

              circles9[i].setRadius(8);
              circles9[i].setPosition(100 * (i + 1) - 60 * i - 42, 375);
              circles9[i].setOutlineThickness(3);
              circles9[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles9[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles9[i].setFillColor(sf::Color::Red);
              }
          }
      }
      else if (triesLeft == 0)
      {
          for (int i = 0; i < NUM_SQUARES; i++) {
              ten[i].setSize(sf::Vector2f(30, 30));
              ten[i].setPosition(100 * (i + 1) - 60 * i + 150, 400);
              ten[i].setFillColor(colors[currentColors[i]]);

              circles10[i].setRadius(8);
              circles10[i].setPosition(100 * (i + 1) - 60 * i - 42 + 200, 375);
              circles10[i].setOutlineThickness(3);
              circles10[i].setOutlineColor(sf::Color(90, 90, 90));
              if (correctColors > 0)
              {
                  circles10[i].setFillColor(sf::Color::Green);
                  correctColors--;
              }
              else
              {
                  circles10[i].setFillColor(sf::Color::Red);
              }
          }
      }*/


}







//void Game::displayRecord(sf::RectangleShape one[NUM_SQUARES], sf::RectangleShape two[NUM_SQUARES], sf::RectangleShape three[NUM_SQUARES], sf::RectangleShape four[NUM_SQUARES], sf::RectangleShape five[NUM_SQUARES], sf::RectangleShape six[NUM_SQUARES], sf::RectangleShape seven[NUM_SQUARES], sf::RectangleShape eight[NUM_SQUARES], sf::RectangleShape nine[NUM_SQUARES], sf::RectangleShape ten[NUM_SQUARES], sf::CircleShape circles[6], sf::CircleShape circles2[6], sf::CircleShape circles3[6], sf::CircleShape circles4[6], sf::CircleShape circles5[6], sf::CircleShape circles6[6], sf::CircleShape circles7[6], sf::CircleShape circles8[6], sf::CircleShape circles9[6], sf::CircleShape circles10[6], int* currentColors, int triesLeft, int correctColors, sf::Color colors[6])
//{
    //if (triesLeft == 9)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        one[i].setSize(sf::Vector2f(30, 30));
    //        one[i].setPosition(100 * (i + 1) - 60 * i - 50, 200);
    //        one[i].setFillColor(colors[currentColors[i]]);

    //        //draw dots for prompting the user
    //        circles[i].setRadius(8);
    //        circles[i].setPosition(100 * (i + 1) - 60 * i - 42, 175);
    //        circles[i].setOutlineThickness(3);
    //        circles[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles[i].setFillColor(sf::Color::Red);
    //        }
    //    }
    //}
    //else if (triesLeft == 8)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        two[i].setSize(sf::Vector2f(30, 30));
    //        two[i].setPosition(100 * (i + 1) - 60 * i + 150, 200);
    //        two[i].setFillColor(colors[currentColors[i]]);

    //        circles2[i].setRadius(8);
    //        circles2[i].setPosition(100 * (i + 1) - 60 * i - 42 + 200, 175);
    //        circles2[i].setOutlineThickness(3);
    //        circles2[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles2[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles2[i].setFillColor(sf::Color::Red);
    //        }
    //    }


    //}
    //else if (triesLeft == 7)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        three[i].setSize(sf::Vector2f(30, 30));
    //        three[i].setPosition(100 * (i + 1) - 60 * i + 350, 200);
    //        three[i].setFillColor(colors[currentColors[i]]);

    //        circles3[i].setRadius(8);
    //        circles3[i].setPosition(100 * (i + 1) - 60 * i - 42 + 400, 175);
    //        circles3[i].setOutlineThickness(3);
    //        circles3[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles3[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles3[i].setFillColor(sf::Color::Red);
    //        }
    //    }
    //}
    //else if (triesLeft == 6)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        four[i].setSize(sf::Vector2f(30, 30));
    //        four[i].setPosition(100 * (i + 1) - 60 * i + 550, 200);
    //        four[i].setFillColor(colors[currentColors[i]]);

    //        circles4[i].setRadius(8);
    //        circles4[i].setPosition(100 * (i + 1) - 60 * i - 42 + 600, 175);
    //        circles4[i].setOutlineThickness(3);
    //        circles4[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles4[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles4[i].setFillColor(sf::Color::Red);
    //        }
    //    }
    //}
    //else if (triesLeft == 5)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        five[i].setSize(sf::Vector2f(30, 30));
    //        five[i].setPosition(100 * (i + 1) - 60 * i - 50, 300);
    //        five[i].setFillColor(colors[currentColors[i]]);

    //        circles5[i].setRadius(8);
    //        circles5[i].setPosition(100 * (i + 1) - 60 * i - 42, 275);
    //        circles5[i].setOutlineThickness(3);
    //        circles5[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles5[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles5[i].setFillColor(sf::Color::Red);
    //        }
    //    }

    //}
    //else if (triesLeft == 4)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        six[i].setSize(sf::Vector2f(30, 30));
    //        six[i].setPosition(100 * (i + 1) - 60 * i + 150, 300);
    //        six[i].setFillColor(colors[currentColors[i]]);

    //        circles6[i].setRadius(8);
    //        circles6[i].setPosition(100 * (i + 1) - 60 * i - 42 + 200, 275);
    //        circles6[i].setOutlineThickness(3);
    //        circles6[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles6[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles6[i].setFillColor(sf::Color::Red);
    //        }
    //    }

    //}
    //else if (triesLeft == 3)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        seven[i].setSize(sf::Vector2f(30, 30));
    //        seven[i].setPosition(100 * (i + 1) - 60 * i + 350, 300);
    //        seven[i].setFillColor(colors[currentColors[i]]);

    //        circles7[i].setRadius(8);
    //        circles7[i].setPosition(100 * (i + 1) - 60 * i - 42 + 400, 275);
    //        circles7[i].setOutlineThickness(3);
    //        circles7[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles7[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles7[i].setFillColor(sf::Color::Red);
    //        }
    //    }
    //}
    //else if (triesLeft == 2)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        eight[i].setSize(sf::Vector2f(30, 30));
    //        eight[i].setPosition(100 * (i + 1) - 60 * i + 550, 300);
    //        eight[i].setFillColor(colors[currentColors[i]]);

    //        circles8[i].setRadius(8);
    //        circles8[i].setPosition(100 * (i + 1) - 60 * i - 42 + 600, 275);
    //        circles8[i].setOutlineThickness(3);
    //        circles8[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles8[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles8[i].setFillColor(sf::Color::Red);
    //        }
    //    }
    //}
    //else if (triesLeft == 1)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        nine[i].setSize(sf::Vector2f(30, 30));
    //        nine[i].setPosition(100 * (i + 1) - 60 * i - 50, 400);
    //        nine[i].setFillColor(colors[currentColors[i]]);

    //        circles9[i].setRadius(8);
    //        circles9[i].setPosition(100 * (i + 1) - 60 * i - 42, 375);
    //        circles9[i].setOutlineThickness(3);
    //        circles9[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles9[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles9[i].setFillColor(sf::Color::Red);
    //        }
    //    }
    //}
    //else if (triesLeft == 0)
    //{
    //    for (int i = 0; i < NUM_SQUARES; i++) {
    //        ten[i].setSize(sf::Vector2f(30, 30));
    //        ten[i].setPosition(100 * (i + 1) - 60 * i + 150, 400);
    //        ten[i].setFillColor(colors[currentColors[i]]);

    //        circles10[i].setRadius(8);
    //        circles10[i].setPosition(100 * (i + 1) - 60 * i - 42 + 200, 375);
    //        circles10[i].setOutlineThickness(3);
    //        circles10[i].setOutlineColor(sf::Color(90, 90, 90));
    //        if (correctColors > 0)
    //        {
    //            circles10[i].setFillColor(sf::Color::Green);
    //            correctColors--;
    //        }
    //        else
    //        {
    //            circles10[i].setFillColor(sf::Color::Red);
    //        }
    //    }
    //}
//}

