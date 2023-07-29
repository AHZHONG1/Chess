#pragma once
#include "State.h"

namespace sf {
    class RenderWindow;
}

class GameSetting {

private:







public:

    GameSetting();

    GameSetting(int, int);

    ~GameSetting();

    void update(sf::RenderWindow*, State&);

    void render(sf::RenderWindow*);


};