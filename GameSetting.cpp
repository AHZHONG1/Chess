#include "GameSetting.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Button.h"

GameSetting::GameSetting() {

}

GameSetting::GameSetting(int width, int height) {
    gamemode1Button = new Button(sf::Vector2f(400, 50), sf::Vector2f(1200, 300), "Player VS Player (offline)", sf::Color::White, sf::Color::Red);
    gamemode2Button = new Button(sf::Vector2f(400, 50), sf::Vector2f(1200, 400), "Player VS AI", sf::Color::White, sf::Color::Red);
    gamemode3Button = new Button(sf::Vector2f(400, 50), sf::Vector2f(1200, 500), "Player VS Player (online)", sf::Color::White, sf::Color::Red);
    readyButton = new Button(sf::Vector2f(400, 50), sf::Vector2f(1200, 600), "Ready", sf::Color::White, sf::Color::Red);

}

GameSetting::~GameSetting() {
    delete gamemode1Button;
    delete gamemode2Button;
    delete gamemode3Button;
    delete readyButton;
}

void GameSetting::update(sf::RenderWindow* window, State& state) {
    sf::Event event;

    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        }
    }
}

void GameSetting::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    gamemode1Button->render(window);
    gamemode2Button->render(window);
    gamemode3Button->render(window);
    readyButton->render(window);
    window->display();
}
