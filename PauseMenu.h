#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class PauseMenu {

private:

    sf::Font font;
    sf::Text textPause;

public:

    PauseMenu();

    PauseMenu(int, int);

    ~PauseMenu();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};