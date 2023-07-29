#include "GameSetting.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Button.h"

GameSetting::GameSetting() {

}

GameSetting::GameSetting(int width, int height) {
    gamemode1Button = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 250), "Player VS Player (offline)", sf::Color::White, sf::Color::Red);
    gamemode2Button = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 350), "Player VS AI", sf::Color::White, sf::Color::Red);
    gamemode3Button = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 450), "Player VS Player (online)", sf::Color::White, sf::Color::Red);
    readyButton = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 650), "Ready", sf::Color::White, sf::Color::Red);

    iconRect.setFillColor(sf::Color::White);
    iconRect.setSize(sf::Vector2f(800, 50));
    iconRect.setPosition(0, 850);

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
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (readyButton->click(event)) {
                    state = State::InGameState;
                }
            }
            break;
        }
        
    }
}

void GameSetting::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    window->draw(iconRect);
    gamemode1Button->render(window);
    gamemode2Button->render(window);
    gamemode3Button->render(window);
    readyButton->render(window);
    window->display();
}
