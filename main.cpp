#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
    int width = 1600, height = 900;
    sf::RenderWindow window(sf::VideoMode(width, height), "Chess", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        cout << "Loading error" << endl;
    }

    sf::Text textTitle;
    sf::Text textCreator;

    textTitle.setFont(font);
    textCreator.setFont(font);
    textTitle.setString("Chess");
    textCreator.setString("By AHZHONG");
    textTitle.setCharacterSize(42);
    textCreator.setCharacterSize(32);
    textTitle.setPosition(width / 2.0, 300);
    textCreator.setPosition(width/2.0, 400);
    sf::FloatRect textTitleRect = textTitle.getLocalBounds();
    sf::FloatRect textCreatorRect = textCreator.getLocalBounds();
    textTitle.setOrigin(textTitleRect.left + textTitleRect.width / 2.0, textTitleRect.top + textTitleRect.height / 2.0);
    textCreator.setOrigin(textCreatorRect.left + textCreatorRect.width / 2.0, textCreatorRect.top + textCreatorRect.height / 2.0);

    textTitle.setFillColor(sf::Color::Red);
    textCreator.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(textTitle);
        window.draw(textCreator);
        window.display();
    }

    return 0;
}