#include "PopUpMessageBox.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/System/Time.hpp>

PopUpMessageBox::PopUpMessageBox() : totalTime(3.0 * 1000), remainingTime(3.0 * 1000) {

}

PopUpMessageBox::PopUpMessageBox(sf::Vector2f size, sf::Vector2f position, sf::String text, sf::Color backgroundColor, sf::Color textColor, float time) : totalTime(time * 1000), remainingTime(totalTime) {
    rectangle.setSize(size);
    rectangle.setPosition(position);
    sf::FloatRect buttonRect = rectangle.getLocalBounds();
    rectangle.setOrigin(buttonRect.left + buttonRect.width / 2.0, buttonRect.top + buttonRect.height / 2.0);
    rectangle.setFillColor(backgroundColor);
    
    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    } 

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(42);
    this->text.setPosition(position);
    sf::FloatRect textRect = this->text.getLocalBounds();
    this->text.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
    this->text.setFillColor(textColor);

    timer.restart();
}

PopUpMessageBox::~PopUpMessageBox() {
    
}

void PopUpMessageBox::render(sf::RenderWindow* window) {
    window->draw(rectangle);
    window->draw(text);
}

void PopUpMessageBox::update(sf::RenderWindow* window, bool& value) {
    sf::Time time = timer.getElapsedTime();
    remainingTime = totalTime - time.asMilliseconds();
    if (remainingTime <= 0) {
        value = true;
    }
}
