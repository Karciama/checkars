//
// Created by User on 2024-12-12.
//

#include "Visual.h"
#include "Rules.h"

Visual::Visual() : window(sf::VideoMode(600, 600), "Checkers Game") {
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(100, 100));
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares[i][j].setSize(sf::Vector2f(squareSize, squareSize));
            squares[i][j].setPosition(j * squareSize, i * squareSize);
            squares[i][j].setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            pieces[i][j].setRadius(squareSize / 2.5f);
            pieces[i][j].setOrigin(pieces[i][j].getRadius(), pieces[i][j].getRadius());
            pieces[i][j].setPosition(j * squareSize + squareSize / 2, i * squareSize + squareSize / 2);
        }
    }
}
void Visual::drawBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares[i][j].setSize(sf::Vector2f(squareSize, squareSize));
            squares[i][j].setPosition(j * squareSize, i * squareSize);
            squares[i][j].setFillColor((i + j) % 2 == 0 ? sf::Color::White : sf::Color::Black);
            window.draw(squares[i][j]);
        }
    }
}
void Visual::drawPieces(const Lenta& lenta) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int piece = lenta.board[i][j];
            if (piece == 1) {
                pieces[i][j].setFillColor(sf::Color::Red);
                window.draw(pieces[i][j]);
            }
            else if (piece == 2) {
                pieces[i][j].setFillColor(sf::Color(255, 182, 193)); // rausva
                window.draw(pieces[i][j]);
            }
            else if (piece == 3) {
                pieces[i][j].setFillColor(sf::Color::Blue);
                window.draw(pieces[i][j]);
            }
            else if (piece == 4) { //
                pieces[i][j].setFillColor(sf::Color(173, 216, 230)); // sviesiai melyna
                window.draw(pieces[i][j]);
            }
        }
    }
}

void Visual::handleClick(sf::Vector2i clickPos, Lenta& lenta) {
    int row = clickPos.y / squareSize;
    int col = clickPos.x / squareSize;
    if (pieceSelected) {
        if (lenta.board[row][col] == 0) {
            lenta.board[row][col] = lenta.board[selectedRow][selectedCol];
            lenta.board[selectedRow][selectedCol] = 0;
        }
        pieceSelected = false;
    } else {
        if (lenta.board[row][col] != 0) {
            selectedRow = row;
            selectedCol = col;
            pieceSelected = true;
        }
    }
}

void Visual::movePiece(sf::Vector2i clickPos, Lenta& lenta) {
    int row = clickPos.y / squareSize;
    int col = clickPos.x / squareSize;
    if (pieceSelected) {
        if (lenta.board[row][col] == 0) {
            Rules rules;
            if (rules.move(selectedRow, selectedCol, row, col, lenta)) {
                lenta.board[row][col] = lenta.board[selectedRow][selectedCol];
                lenta.board[selectedRow][selectedCol] = 0;
                rules.promote(row, col, lenta);
            }
            else if (rules.capture(selectedRow, selectedCol, row, col, lenta)) {
                int midRow = (selectedRow + row) / 2;
                int midCol = (selectedCol + col) / 2;
                lenta.board[row][col] = lenta.board[selectedRow][selectedCol];
                lenta.board[selectedRow][selectedCol] = 0;
                lenta.board[midRow][midCol] = 0; // Remove captured piece
                rules.promote(row, col, lenta);
            }
        }
        pieceSelected = false;
    } else {
        if (lenta.board[row][col] != 0) {
            selectedRow = row;
            selectedCol = col;
            pieceSelected = true;
        }
    }
}
void Visual::display(Lenta& lenta) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i clickPos = sf::Mouse::getPosition(window);
                    movePiece(clickPos, lenta);
                }
            }
        }
        window.clear();
        drawBoard();
        drawPieces(lenta);
        window.display();
    }
}

