#include "Button.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

Button::Button() {

}

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::String text) {
    rectangle.setSize(size);
    rectangle.setPosition(position);
    sf::FloatRect buttonRect = rectangle.getLocalBounds();
    rectangle.setOrigin(buttonRect.left + buttonRect.width / 2.0, buttonRect.top + buttonRect.height / 2.0);

    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    } 

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(42);
    this->text.setPosition(position);
    sf::FloatRect textRect = this->text.getLocalBounds();
    this->text.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
    this->text.setFillColor(sf::Color::Red);
}

Button::~Button() {
    
}

bool Button::click(const sf::Event& event) const {
    return rectangle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

void Button::render(sf::RenderWindow* window) {
    window->draw(rectangle);
    window->draw(text);
}
