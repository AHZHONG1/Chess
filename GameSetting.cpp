#include "GameSetting.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Button.h"
#include "PopUpMessageBox.h"
#include "InGame.h"
#include "DropdownBox.h"
#include <iostream>

GameSetting::GameSetting() : messageBox(nullptr), bDead(false) {

}

GameSetting::GameSetting(int width, int height) : chosenGamemode(GameMode::None), messageBox(nullptr), bDead(false), timeSelectedIndex(-1), timeSelected(-1) {
    gamemode1Button = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 250), "Player VS Player (offline)", sf::Color::White, sf::Color::Red);
    gamemode2Button = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 350), "Player VS AI", sf::Color::White, sf::Color::Red);
    gamemode3Button = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 450), "Player VS Player (online)", sf::Color::White, sf::Color::Red);
    readyButton = new Button(sf::Vector2f(500, 50), sf::Vector2f(1200, 650), "Ready", sf::Color::White, sf::Color::Red);

    iconRect.setFillColor(sf::Color::White);
    iconRect.setSize(sf::Vector2f(800, 50));
    iconRect.setPosition(0, 850);

    timeSelectBox = new DropdownBox(sf::Vector2f(500, 50), sf::Vector2f(1200, 550), "Choose Time", sf::Color::White, sf::Color::Red, time, 4);

}

GameSetting::~GameSetting() {
    delete gamemode1Button;
    delete gamemode2Button;
    delete gamemode3Button;
    delete readyButton;
    delete timeSelectBox;
}

void GameSetting::update(sf::RenderWindow* window, State& state, InGame*& inGame) {
    sf::Event event;

    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (gamemode1Button->click(event)) {
                    gamemode1Button->changeBackgroundColor(sf::Color::White);
                    gamemode2Button->changeBackgroundColor(sf::Color::White);
                    gamemode3Button->changeBackgroundColor(sf::Color::White);
                    chosenGamemode = GameMode::PVPOffline;
                    gamemode1Button->changeBackgroundColor(sf::Color::Green);
                    break;
                }
                if (gamemode2Button->click(event)) {
                    gamemode1Button->changeBackgroundColor(sf::Color::White);
                    gamemode2Button->changeBackgroundColor(sf::Color::White);
                    gamemode3Button->changeBackgroundColor(sf::Color::White);
                    chosenGamemode = GameMode::AIOffline;
                    gamemode2Button->changeBackgroundColor(sf::Color::Green);
                    break;
                }
                if (gamemode3Button->click(event)) {
                    gamemode1Button->changeBackgroundColor(sf::Color::White);
                    gamemode2Button->changeBackgroundColor(sf::Color::White);
                    gamemode3Button->changeBackgroundColor(sf::Color::White);
                    chosenGamemode = GameMode::PVPOnline;
                    gamemode3Button->changeBackgroundColor(sf::Color::Green);
                    break;
                }
                if (timeSelectBox->click(event)) {
                    timeSelectBox->showList();
                    break;
                }
                if (timeSelectBox->isShow()) {
                    if (!timeSelectBox->clickInside(event, timeSelectedIndex)) {
                        timeSelectBox->hideList();
                        break;
                    }
                    if (timeSelectedIndex != -1) {
                        switch (timeSelectedIndex) {
                        case 0:
                            timeSelected = 60;
                            break;
                        case 1:
                            timeSelected = 180;
                            break;
                        case 2:
                            timeSelected = 600;
                            break;
                        case 3:
                            timeSelected = 1800;
                            break;
                        default:
                            timeSelected = -1;
                            break;
                        }
                        std::cout << "TimeIs=" << timeSelected << std::endl;
                        break;
                    }
                    break;
                }
                
                
                if (!timeSelectBox->isShow() && readyButton->click(event)) {
                    switch(chosenGamemode) {
                    case GameMode::PVPOffline:
                        if (timeSelected == -1) {
                            if (messageBox == nullptr) {
                                messageBox = new PopUpMessageBox(sf::Vector2f(1000, 100), sf::Vector2f(800, 800), "You need to choose a time!", sf::Color(255, 255, 255, 100), sf::Color(0, 0, 0), 3);
                                break;
                            }
                            break;
                        }
                        inGame = new InGame(window->getSize().x, window->getSize().y, 0, timeSelected / 60, 0);
                        state = State::InGameState;
                        if (messageBox) {
                            delete messageBox;
                            messageBox = nullptr;
                        }
                        break;
                    case GameMode::AIOffline:

                        break;
                    case GameMode::PVPOnline:

                        break;
                    default:
                        if (messageBox == nullptr) {
                            messageBox = new PopUpMessageBox(sf::Vector2f(1000, 100), sf::Vector2f(800, 800), "You need to select a gamemode!", sf::Color(255, 255, 255, 100), sf::Color(0, 0, 0), 3);
                        } 
                        break;
                    }      
                }
            }
            break;
        }
        
    }
    if (messageBox) {
        messageBox->update(window, bDead);
        if (bDead) {
            delete messageBox;
            messageBox = nullptr;
            bDead = false;
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
    if (messageBox) {
        messageBox->render(window);
    }
    timeSelectBox->render(window);
    window->display();
}
