#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace sf {
    class RenderWindow;
}

class Timer {

private:

    sf::Clock* clock;

    int hour, minute, second, millisecond;
    int totalTime, remainingTime;

    sf::RectangleShape rectangle;
    sf::Font font;
    sf::Text text;



public:

    Timer();

    Timer(int, int, int, sf::Vector2f);

    ~Timer();

    void start();

    void pause();

    void update();

    void render(sf::RenderWindow*);

    


};