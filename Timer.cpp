#include "Timer.h"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

Timer::Timer() : hour(0), minute(10), second(0), totalTime((hour * 3600 + minute * 60 + second) * 1000) {   

}

Timer::Timer(int hour, int minute, int second, sf::Vector2f position) : hour(hour), minute(minute), second(second), millisecond(0), totalTime((hour * 3600 + minute * 60 + second) * 1000), clock(nullptr), remainingTime(totalTime) {
    
    rectangle.setSize(sf::Vector2f(300, 40));
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color::White);

    if (!font.loadFromFile("./Font/roboto/Roboto-Regular.ttf")) {
        std::cout << "Loading error" << std::endl;
    } 

    text.setFont(font);
    text.setString(std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second));
    text.setCharacterSize(32);
    text.setPosition(position);
    sf::FloatRect textRect = text.getLocalBounds();
    //text.setOrigin(textRect.left + textRect.width / 2.0, textRect.top + textRect.height / 2.0);
    text.setFillColor(sf::Color::Red);
}

Timer::~Timer() {
    if (clock) {
        delete clock;
    }
}


void Timer::start() {
    if (clock == nullptr) {
        clock = new sf::Clock();
    }
}

void Timer::pause() {
    totalTime = remainingTime;
    delete clock;
    clock = nullptr;
}

void Timer::update() {
    if (clock) {
        sf::Time elapsed = clock->getElapsedTime();
        remainingTime = totalTime - elapsed.asMilliseconds();
        hour = remainingTime / 3600000;
        minute = remainingTime % 3600000 / 60000;
        second = (remainingTime % 3600000) % 60000 / 1000;
        millisecond = (remainingTime % 3600000) % 60000 % 1000;
    }

    text.setString("Time: " + ((hour >= 10) ? std::to_string(hour) : "0" + std::to_string(hour)) + ":" + ((minute >= 10) ? std::to_string(minute) : "0" + std::to_string(minute)) + ":" + ((second >= 10) ? std::to_string(second) : "0" + std::to_string(second)) + ":" + ((millisecond >= 100) ? std::to_string(millisecond) : ((millisecond >= 10) ? "0" + std::to_string(millisecond) : "00" + std::to_string(millisecond))));
    //std::cout << remainingTime << std::endl;
    if (remainingTime <= 0) {
        text.setString("End");
        return;
    }
    
}

void Timer::render(sf::RenderWindow* window) {
    window->draw(rectangle);
    window->draw(text);
}

