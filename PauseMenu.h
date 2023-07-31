#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "General.h"

namespace sf {
    class RenderWindow;
}

class Button;

class PauseMenu {

private:

    sf::Font font;
    sf::Text textPause;
    Button* resumeButton;
    Button* backMenuButton;

public:

    PauseMenu();

    PauseMenu(int, int);

    ~PauseMenu();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};