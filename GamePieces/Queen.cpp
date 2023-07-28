#include "Queen.h"

Queen::Queen() {

}

Queen::Queen(sf::String texturePath, int i, int j) : GamePieces(texturePath, i, j) {

}

Queen::~Queen() {

}

void Queen::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
