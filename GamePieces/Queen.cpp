#include "Queen.h"

Queen::Queen() {

}

Queen::Queen(sf::String texturePath, int i, int j, Player color) : GamePieces(texturePath, i, j, color) {

}

Queen::~Queen() {

}

void Queen::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
