#include "PauseMenu.h"
#include "Button.h"
#include <iostream>

PauseMenu::PauseMenu() {

}

PauseMenu::PauseMenu(int width, int height) {
    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    }  

    textPause.setFont(font);
    textPause.setString("Pause");
    textPause.setCharacterSize(42);
    textPause.setPosition(width / 2.0, 300);
    sf::FloatRect textPauseRect = textPause.getLocalBounds();
    textPause.setOrigin(textPauseRect.left + textPauseRect.width / 2.0, textPauseRect.top + textPauseRect.height / 2.0);
    textPause.setFillColor(sf::Color::Red);

    resumeButton = new Button(sf::Vector2f(250, 50), sf::Vector2f(width / 2.0, 500), "Resume");
    backMenuButton = new Button(sf::Vector2f(250, 50), sf::Vector2f(width / 2.0, 600), "Back to Menu");

}

PauseMenu::~PauseMenu() {
    delete resumeButton;
    delete backMenuButton;
}

void PauseMenu::update(sf::RenderWindow* window, State& state) {
    sf::Event event;

    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (resumeButton->click(event)) {
                    state = State::InGameState;
                }
                if (backMenuButton->click(event)) {
                    state = State::MainMenuState;
                }
            }
            break;
        }
    }
}

void PauseMenu::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    window->draw(textPause);
    resumeButton->render(window);
    backMenuButton->render(window);
    window->display();
}
