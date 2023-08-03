#include "EndGameScreen.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "Button.h"

EndGameScreen::EndGameScreen() : leaveGameBtn(new Button(sf::Vector2f(350, 50), sf::Vector2f(800, 550), "Leave this match", sf::Color(0, 0, 0, 100), sf::Color::White)) {
    background.setFillColor(sf::Color(0, 0, 0, 100));
    background.setSize(sf::Vector2f(1600, 900));
    background.setPosition(0, 0);

    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    }

    endGameMessage.setFont(font);
    endGameMessage.setString("End Game");
    endGameMessage.setPosition(800, 450);
    sf::FloatRect messageRect = endGameMessage.getLocalBounds();
    endGameMessage.setOrigin(messageRect.left + messageRect.width / 2.0, messageRect.top + messageRect.height / 2.0);

    endGameText.setFont(font);
    endGameText.setString("Someone win");
    endGameText.setPosition(800, 500);
    sf::FloatRect textRect = endGameText.getLocalBounds();
    endGameText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
    

}

EndGameScreen::EndGameScreen(sf::String message, Player color) : leaveGameBtn(new Button(sf::Vector2f(350, 50), sf::Vector2f(800, 550), "Leave this match", sf::Color(0, 0, 0, 100), sf::Color::White)) {
    background.setFillColor(sf::Color(0, 0, 0, 100));
    background.setSize(sf::Vector2f(1600, 900));
    background.setPosition(0, 0);

    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    }

    endGameMessage.setFont(font);
    endGameMessage.setString(message);
    endGameMessage.setPosition(800, 450);
    sf::FloatRect messageRect = endGameMessage.getLocalBounds();
    endGameMessage.setOrigin(messageRect.left + messageRect.width / 2.0, messageRect.top + messageRect.height / 2.0);
    
    endGameText.setFont(font);
    endGameText.setString((color == Player::White) ? "Black win" : "White win");
    endGameText.setPosition(800, 500);
    sf::FloatRect textRect = endGameText.getLocalBounds();
    endGameText.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);

}

EndGameScreen::~EndGameScreen() {
    delete leaveGameBtn;
}

void EndGameScreen::update(sf::RenderWindow* window, State& state) {
    sf::Event event;

    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (leaveGameBtn->click(event)) {
                    state = State::MainMenuState;
                }
            }
            break;
        }
    }
}

void EndGameScreen::render(sf::RenderWindow* window) {
    window->draw(background);
    window->draw(endGameMessage);
    window->draw(endGameText);
    leaveGameBtn->render(window);
}
