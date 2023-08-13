#include "DropdownBox.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>

DropdownBox::DropdownBox() {

}

DropdownBox::DropdownBox(sf::Vector2f size, sf::Vector2f position, sf::String text, sf::Color backgroundColor, sf::Color textColor, sf::String listStrings[4], int listSize) : bShow(false) {
    clickBox.setFillColor(backgroundColor);
    clickBox.setSize(size);
    clickBox.setPosition(position);
    sf::FloatRect boxRect = clickBox.getLocalBounds();
    clickBox.setOrigin(boxRect.left + boxRect.width / 2.0, boxRect.top + boxRect.height / 2.0);

    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Cannot load font" << std::endl;
    }

    titleText.setFont(font);
    titleText.setFillColor(textColor);
    titleText.setString(text);
    titleText.setCharacterSize(42);
    titleText.setPosition(position);
    sf::FloatRect titleRect = titleText.getLocalBounds();
    titleText.setOrigin(titleRect.left + titleRect.width / 2.0, titleRect.top + titleRect.height / 2.0);

    for (int i = 0; i < listSize; ++i) {
        listBoxs.push_back(new sf::RectangleShape());
        backgroundColor.a = 200;
        listBoxs.back()->setFillColor(backgroundColor);
        listBoxs.back()->setSize(size);
        listBoxs.back()->setPosition(sf::Vector2f(position.x, position.y + size.y * (i + 1)));
        sf::FloatRect boxRect = listBoxs.back()->getLocalBounds();
        listBoxs.back()->setOrigin(boxRect.left + boxRect.width / 2.0, boxRect.top + boxRect.height / 2.0);

        listTexts.push_back(new sf::Text());
        listTexts.back()->setFont(font);
        listTexts.back()->setFillColor(textColor);
        listTexts.back()->setString(listStrings[i]);
        listTexts.back()->setCharacterSize(42);
        listTexts.back()->setPosition(sf::Vector2f(position.x, position.y + size.y * (i + 1)));
        sf::FloatRect titleRect = listTexts.back()->getLocalBounds();
        listTexts.back()->setOrigin(titleRect.left + titleRect.width / 2.0, titleRect.top + titleRect.height / 2.0);
    }
    for (int i = 0; i < 4; ++i) {
        time[i] = listStrings[i];
    }   
}

DropdownBox::~DropdownBox() {
    for (sf::RectangleShape* listBox : listBoxs) {
        delete listBox;
    }
    for (sf::Text* listText : listTexts) {
        delete listText;
    }
}

void DropdownBox::showList() {
    bShow = true;
}

void DropdownBox::hideList() {
    bShow = false;
}

bool DropdownBox::click(const sf::Event& event) const {
    return clickBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
}

bool DropdownBox::isShow() {
    return bShow;
}

void DropdownBox::checkSelection(sf::RenderWindow* window, State& state, int& timeSelected) {
    sf::Event event;
    for (int i = 0; i < listBoxs.size(); ++i) {
        if (listBoxs[i]->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            
        }
    }
}

void DropdownBox::render(sf::RenderWindow* window) {
    window->draw(clickBox);
    window->draw(titleText);
    if (bShow) {
        for (sf::RectangleShape* listBox : listBoxs) {
            window->draw(*listBox);
        }
        for (sf::Text* listText : listTexts) {
            window->draw(*listText);
        }
    }
}

bool DropdownBox::clickInside(const sf::Event& event, int& clicked) {   
    for (int i = 0; i < listBoxs.size(); ++i) {
        if (listBoxs[i]->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            std::cout << "Time=" << i << std::endl;
            clicked = i;
            titleText.setString("Time:" + time[i]);
            sf::FloatRect titleRect = titleText.getLocalBounds();
            titleText.setOrigin(titleRect.left + titleRect.width / 2.0, titleRect.top + titleRect.height / 2.0);
            hideList();
            return true;
        }
    }
    clicked = -1;
    titleText.setString("Choose Time");
    sf::FloatRect titleRect = titleText.getLocalBounds();
    titleText.setOrigin(titleRect.left + titleRect.width / 2.0, titleRect.top + titleRect.height / 2.0);
    return false;
}
