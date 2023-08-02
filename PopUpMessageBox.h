#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Clock.hpp>

namespace sf {
    class RenderWindow;
}

class PopUpMessageBox {

private:

    sf::RectangleShape rectangle;
    sf::Font font;
    sf::Text text;

    sf::Clock timer;

    float totalTime;

    float remainingTime;


public:
    PopUpMessageBox();

    PopUpMessageBox(sf::Vector2f, sf::Vector2f, sf::String, sf::Color, sf::Color, float);

    ~PopUpMessageBox();

    void update(sf::RenderWindow*, bool&);

    void render(sf::RenderWindow*);

};