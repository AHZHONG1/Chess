#include "Knight.h"

Knight::Knight() {

}

Knight::Knight(sf::String texturePath, int i, int j) : GamePieces(texturePath, i, j) {

}

Knight::~Knight() {

}

void Knight::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
