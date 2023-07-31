#include "Knight.h"

Knight::Knight() {

}

Knight::Knight(sf::String texturePath, int i, int j, Player color) : GamePieces(texturePath, i, j, color) {

}

Knight::~Knight() {

}

void Knight::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
