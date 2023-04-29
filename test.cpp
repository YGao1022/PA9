//#include "test.hpp"
//
//TEST(GameTest, DisplaySquaresTest) {
//    MockGame game;
//    sf::RectangleShape squares[Game::NUM_SQUARES];
//    sf::Color colors[Game::NUM_COLORS] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue };
//    int currentColors[Game::NUM_SQUARES] = { 0, 1, 2 };
//
//    game.displaySquares(squares, colors, currentColors);
//
//    for (int i = 0; i < Game::NUM_SQUARES; ++i) {
//        EXPECT_EQ(squares[i].getSize(), sf::Vector2f(50, 50));
//        EXPECT_EQ(squares[i].getPosition(), sf::Vector2f(100 * (i + 1) - 10 * i, 75));
//        EXPECT_EQ(squares[i].getFillColor(), colors[currentColors[i]]);
//    }
//}
//
//TEST(GameTest, GenerateRandomPatternTest) {
//    MockGame game;
//    std::vector<int> pattern = game.generateRandomPattern();
//
//    EXPECT_EQ(pattern.size(), Game::NUM_SQUARES);
//    for (int i = 0; i < Game::NUM_SQUARES; ++i) {
//        EXPECT_GE(pattern[i], 0);
//        EXPECT_LT(pattern[i], Game::NUM_COLORS);
//    }
//}
//
//TEST(GameTest, RevealPatternTest) {
//    MockGame game;
//    sf::RectangleShape squares[Game::NUM_SQUARES];
//    sf::Color colors[Game::NUM_COLORS] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue };
//    std::vector<int> pattern = { 0, 1, 2 };
//
//    game.revealPattern(pattern, squares, colors, 0);
//
//    for (int i = 0; i < Game::NUM_SQUARES; ++i) {
//        EXPECT_EQ(squares[i].getFillColor(), colors[pattern[i]]);
//    }
//
//
//    game.revealPattern(pattern, squares, colors, 1);
//
//    for (int i = 0; i < Game::NUM_SQUARES; ++i) {
//        EXPECT_NE(squares[i].getFillColor(), colors[pattern[i]]);
//    }
//}