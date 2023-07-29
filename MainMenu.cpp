#include "MainMenu.h"
#include "Button.h"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

MainMenu::MainMenu() {

}

MainMenu::MainMenu(int width, int height) {
    
    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    }  

    textTitle.setFont(font);
    textTitle.setString("Chess");
    textTitle.setCharacterSize(42);
    textTitle.setPosition(width / 2.0, 300);
    sf::FloatRect textTitleRect = textTitle.getLocalBounds();
    textTitle.setOrigin(textTitleRect.left + textTitleRect.width / 2.0, textTitleRect.top + textTitleRect.height / 2.0);
    textTitle.setFillColor(sf::Color::Red);

    textCreator.setFont(font);
    textCreator.setString("By AHZHONG");
    textCreator.setCharacterSize(32);
    textCreator.setPosition(width/2.0, 400);
    sf::FloatRect textCreatorRect = textCreator.getLocalBounds();
    textCreator.setOrigin(textCreatorRect.left + textCreatorRect.width / 2.0, textCreatorRect.top + textCreatorRect.height / 2.0);
    textCreator.setFillColor(sf::Color::Red);

    startButton = new Button(sf::Vector2f(200, 50), sf::Vector2f(width / 2.0, 500), "Start");
    quitButton = new Button(sf::Vector2f(200, 50), sf::Vector2f(width / 2.0, 600), "Quit");

}

MainMenu::~MainMenu() {
    delete startButton;
    delete quitButton;
}

void MainMenu::update(sf::RenderWindow* window, State& state) {
    sf::Event event;
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (startButton->click(event)) {
                    state = State::InGameState;
                }
                if (quitButton->click(event)) {
                    window->close();
                }
            }
            break;
        }
    }
}

void MainMenu::render(sf::RenderWindow* window) {
    window->clear(sf::Color::Black);
    window->draw(textTitle);
    window->draw(textCreator);
    startButton->render(window);
    quitButton->render(window);
    window->display();
}
