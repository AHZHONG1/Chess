#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace sf {
    class RenderWindow;
}

class Button {

private:

    sf::RectangleShape rectangle;
    sf::Font font;
    sf::Text text;


public:
    Button();

    Button(sf::Vector2f, sf::Vector2f, sf::String);

    ~Button();

    bool click(const sf::Event& event) const;

    void render(sf::RenderWindow*);

};