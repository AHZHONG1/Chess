#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class InGame {

private:

    

public:

    InGame();

    InGame(int, int);

    ~InGame();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};