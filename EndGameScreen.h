#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>
#include "General.h"

class Button;

namespace sf {
    class RenderWindow;
}

class EndGameScreen {

private:

    sf::RectangleShape background;
    sf::Font font;
    sf::Text endGameMessage;
    sf::Text endGameText;

    Button* leaveGameBtn;


public:

    EndGameScreen();

    EndGameScreen(sf::String, Player);

    ~EndGameScreen();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);

};