#pragma once
#include "General.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <vector>
#include <SFML/Window/Event.hpp>

namespace sf {
    class RenderWindow;
}

class DropdownBox {
private:

    sf::RectangleShape clickBox;

    sf::Font font;

    sf::Text titleText;

    std::vector<sf::RectangleShape*> listBoxs;

    std::vector<sf::Text*> listTexts;

    bool bShow;

    sf::String time[4];



public:

    DropdownBox();

    DropdownBox(sf::Vector2f, sf::Vector2f, sf::String, sf::Color, sf::Color, sf::String[4], int);

    ~DropdownBox();

    void showList();

    void hideList();

    bool isShow();
    
    bool click(const sf::Event&) const;

    bool clickInside(const sf::Event&, int&);

    void checkSelection(sf::RenderWindow*, State&, int&);

    void render(sf::RenderWindow*);

};
