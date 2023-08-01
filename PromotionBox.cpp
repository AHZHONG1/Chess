#include "PromotionBox.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "GamePieces.h"

PromotionBox::PromotionBox() {

    promotionBackground.setFillColor(sf::Color(0, 0, 0, 100));
    promotionBackground.setSize(sf::Vector2f(900, 900));
    promotionBackground.setPosition(0, 0);

    boxBackground.setFillColor(sf::Color(0, 0, 0, 150));
    boxBackground.setSize(sf::Vector2f(260, 260));
    boxBackground.setPosition(450, 450);
    sf::FloatRect boxRect = boxBackground.getLocalBounds();
    boxBackground.setOrigin(boxRect.left + boxRect.width / 2.0, boxRect.top + boxRect.height / 2.0);
}

PromotionBox::PromotionBox(int width, int height, Player turn) {
    promotionBackground.setFillColor(sf::Color(0, 0, 0, 100));
    promotionBackground.setSize(sf::Vector2f(width, height));
    promotionBackground.setPosition(0, 0);

    boxBackground.setFillColor(sf::Color(0, 0, 0, 150));
    boxBackground.setSize(sf::Vector2f(260, 260));
    boxBackground.setPosition(width / 2.0, height / 2.0);
    sf::FloatRect boxRect = boxBackground.getLocalBounds();
    boxBackground.setOrigin(boxRect.left + boxRect.width / 2.0, boxRect.top + boxRect.height / 2.0);

    for (int i = 0; i < 3; ++i) {
        borderLine[0][i].setSize(sf::Vector2f(260, 20));
        borderLine[0][i].setFillColor(sf::Color(27, 153, 139));
        borderLine[0][i].setPosition(width / 2.0, 320 + 120 * i);
        sf::FloatRect borderRect = borderLine[0][i].getLocalBounds();
        borderLine[0][i].setOrigin(borderRect.left + borderRect.width / 2.0, borderRect.top);
    }

    for (int i = 0; i < 3; ++i) {
        borderLine[1][i].setSize(sf::Vector2f(20, 260));
        borderLine[1][i].setFillColor(sf::Color(27, 153, 139));
        borderLine[1][i].setPosition(670 + 120 * i, height / 2.0);
        sf::FloatRect borderRect = borderLine[1][i].getLocalBounds();
        borderLine[1][i].setOrigin(borderRect.left, borderRect.top + borderRect.height / 2.0);
    }

    if (!queenTexture.loadFromFile((turn == Player::White) ? "./Textures/White-Queen.png" : "./Textures/Black-Queen.png")) {
        
    }
    if (!knightTexture.loadFromFile((turn == Player::White) ? "./Textures/White-Knight.png" : "./Textures/Black-Knight.png")) {
        
    }
    if (!rookTexture.loadFromFile((turn == Player::White) ? "./Textures/White-Rook.png" : "./Textures/Black-Rook.png")) {
        
    }
    if (!bishopTexture.loadFromFile((turn == Player::White) ? "./Textures/White-Bishop.png" : "./Textures/Black-Bishop.png")) {
        
    }
    queenSprite.setTexture(queenTexture);
    queenSprite.setPosition(690, 340);

    knightSprite.setTexture(knightTexture);
    knightSprite.setPosition(810, 340);

    rookSprite.setTexture(rookTexture);
    rookSprite.setPosition(690, 460);

    bishopSprite.setTexture(bishopTexture);
    bishopSprite.setPosition(810, 460);

    
}

PromotionBox::~PromotionBox() {

}

bool PromotionBox::overlapPiece(const sf::Event& event, sf::String& outString) const {
    if (queenSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        outString = "Queen";
        return true;
    }
    if (knightSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        outString = "Knight";
        return true;
    }
    if (rookSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        outString = "Rook";
        return true;
    }
    if (bishopSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        outString = "Bishop";
        return true;
    }
    outString = "";
    return false;
}

void PromotionBox::update(sf::RenderWindow* window) {

}

void PromotionBox::render(sf::RenderWindow* window) {
    window->draw(promotionBackground);
    window->draw(boxBackground);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            window->draw(borderLine[i][j]);
        }
    }
    window->draw(queenSprite);
    window->draw(knightSprite);
    window->draw(rookSprite);
    window->draw(bishopSprite);
}
