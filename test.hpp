#pragma once
#include "Game.h"
class MockGame : public Game {
public:
    using Game::displaySquares;
    using Game::checkWon;
    using Game::generateRandomPattern;
    using Game::revealPattern;
};
