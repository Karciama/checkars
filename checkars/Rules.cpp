//
// Created by User on 2024-12-01.
//

#include "Rules.h"
#include <cstdlib>

const int ROWS = 8;
const int COLS = 8;

bool Rules::move(int startRow, int startCol, int endRow, int endCol, const Lenta& lenta) {

    int piece = lenta.board[startRow][startCol];
    if (piece == 2 || piece == 4) {
        if (abs(startRow - endRow) == abs(startCol - endCol)) {
            int rowStep = (endRow > startRow) ? 1 : -1;
            int colStep = (endCol > startCol) ? 1 : -1;
            int row = startRow + rowStep, col = startCol + colStep;
            while (row != endRow && col != endCol) {
                if (lenta.board[row][col] != 0) return false;
                row += rowStep;
                col += colStep;
            }
            return true;
        }
        return false;
    }
    if (piece == 1 || piece == 3) {
        return abs(startRow - endRow) == 1 && abs(startCol - endCol) == 1;
    }
    return false;
}

bool Rules::capture(int startRow, int startCol, int endRow, int endCol, const Lenta& lenta) {
    if (startRow < 0 || startCol < 0 || endRow < 0 || endCol < 0 ||
        startRow >= ROWS || startCol >= COLS ||
        endRow >= ROWS || endCol >= COLS) {
        return false;
    }
    int piece = lenta.board[startRow][startCol];
    int opponentStart = (piece == 1 || piece == 2) ? 3 : 1;
    int opponentEnd = (piece == 1 || piece == 2) ? 4 : 2;

    if (piece == 2 || piece == 4) {
        if (abs(startRow - endRow) == abs(startCol - endCol)) {
            int rowStep = (endRow > startRow) ? 1 : -1;
            int colStep = (endCol > startCol) ? 1 : -1;
            int row = startRow + rowStep, col = startCol + colStep;
            bool opponentFound = false;
            while (row != endRow && col != endCol) {
                if (lenta.board[row][col] != 0) {
                    if (!opponentFound && lenta.board[row][col] >= opponentStart && lenta.board[row][col] <= opponentEnd) {
                        opponentFound = true;
                    } else {
                        return false;
                    }
                }
                row += rowStep;
                col += colStep;
            }
            return opponentFound;
        }
        return false;
    }
    if (piece == 1 || piece == 3) {
        if (abs(startRow - endRow) == 2 && abs(startCol - endCol) == 2) { // Diagonal jump check
            int midRow = (startRow + endRow) / 2;
            int midCol = (startCol + endCol) / 2;
            int capturedPiece = lenta.board[midRow][midCol];
            return capturedPiece >= opponentStart && capturedPiece <= opponentEnd;
        }
    }
    return false;
}

void Rules::promote(int row, int col, Lenta& lenta) {
    if (lenta.board[row][col] == 1 && row == 7) {
        lenta.board[row][col] = 2;
    }
    else if (lenta.board[row][col] == 3 && row == 0) {
        lenta.board[row][col] = 4;
    }
}


