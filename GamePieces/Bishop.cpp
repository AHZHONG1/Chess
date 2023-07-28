#include "Bishop.h"

Bishop::Bishop() {

}

Bishop::Bishop(sf::String texturePath, int i, int j) : GamePieces(texturePath, i, j) {

}

Bishop::~Bishop() {

}

void Bishop::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
