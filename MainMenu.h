#pragma once
#include "State.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace sf {
    class RenderWindow;
}

class Button;

class MainMenu {

private:

    sf::Font font;
    sf::Text textTitle;
    sf::Text textCreator;
    Button* startButton;
    Button* quitButton;

public:

    MainMenu();

    MainMenu(int, int);

    ~MainMenu();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};