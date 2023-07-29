#pragma once
#include "State.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Button;

namespace sf {
    class RenderWindow;
}

class GameSetting {

private:

    sf::Font font;
    sf::Text userName;
    sf::Text timeText;

    Button* gamemode1Button;
    Button* gamemode2Button;
    Button* gamemode3Button;
    Button* readyButton;


public:

    GameSetting();

    GameSetting(int, int);

    ~GameSetting();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};