#pragma once
#include <SFML/Graphics.hpp>

class Button;

class MainMenu {

private:

    sf::Font font;
    sf::Text textTitle;
    sf::Text textCreator;
    Button* startButton;

public:

    MainMenu();

    MainMenu(int, int);

    ~MainMenu();

    void render(sf::RenderWindow*);


};