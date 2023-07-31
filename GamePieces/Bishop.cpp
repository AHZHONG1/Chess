#include "Bishop.h"

Bishop::Bishop() {

}

Bishop::Bishop(sf::String texturePath, int i, int j, Player color) : GamePieces(texturePath, i, j, color) {

}

Bishop::~Bishop() {

}

void Bishop::render(sf::RenderWindow* window) {
    GamePieces::render(window);
}
