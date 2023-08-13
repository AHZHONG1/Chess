#pragma once
#include "General.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Button;
class PopUpMessageBox;
class InGame;
class DropdownBox;

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

    sf::RectangleShape iconRect;

    GameMode chosenGamemode;
    
    PopUpMessageBox* messageBox;

    bool bDead;

    DropdownBox* timeSelectBox;

    sf::String time[4] = {"1:00", "3:00", "10:00", "30:00"};

    int timeSelectedIndex;

    int timeSelected;


public:

    GameSetting();

    GameSetting(int, int);

    ~GameSetting();

    void update(sf::RenderWindow*, State&, InGame*&);

    void render(sf::RenderWindow*);


};