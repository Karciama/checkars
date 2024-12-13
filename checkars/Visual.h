#ifndef VISUAL_H
#define VISUAL_H

#include <SFML/Graphics.hpp>
#include "Lenta.h"

class Visual {
private:
    sf::RenderWindow window;
    sf::RectangleShape squares[8][8];
    sf::CircleShape pieces[8][8];
    const int windowSize = 600;
    const int squareSize = windowSize / 8;
    int selectedRow = -1, selectedCol = -1;
    bool pieceSelected = false;

    void drawBoard();
    void drawPieces(const Lenta& lenta);
    void handleClick(sf::Vector2i clickPos, Lenta& lenta);
    void movePiece(sf::Vector2i clickPos, Lenta& lenta);

public:
    Visual();
    void display(Lenta& lenta);
};


#endif // VISUAL_H
