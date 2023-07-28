#include "King.h"

King::King() {

}

King::King(sf::String texturePath, int i, int j) : GamePieces(texturePath, i, j) {

}

King::~King() {

}

void King::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
