#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>
#include<SFML/Graphics/Font.hpp>
#include<SFML/Graphics/Text.hpp>

namespace sf {
    class RectangleShape;
    class RenderWindow;
}

class Button {

private:

    sf::RectangleShape* rectangle;
    sf::Font font;
    sf::Text text;


public:
    Button();

    Button(sf::Vector2f, sf::Vector2f, sf::String);

    ~Button();

    void render(sf::RenderWindow*);

};