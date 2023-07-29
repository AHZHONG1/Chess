#include "GameSetting.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

GameSetting::GameSetting() {

}

GameSetting::GameSetting(int width, int height) {

}

GameSetting::~GameSetting() {

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
    window->display();
}
