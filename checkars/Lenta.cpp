//
// Created by User on 2024-12-01.
//

#include "Lenta.h"
#include <iostream>

using namespace std;

Lenta::Lenta() {
}
void Lenta::LentKurimas() {
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            board[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 1) {
                board[i][j] = 1;
            }
        }
    }
    for (int i = 5; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 1) {
                board[i][j] = 3;
            }
        }
    }
}
void Lenta::LentSpausdinimas() {
    cout << "  A B C D E F G H\n";
    for(int i = 0; i < 8; ++i) {
        cout << i+1 << " ";
        for(int j = 0; j < 8; ++j) {
            if(board[i][j] == 0) cout << ".";
            else if(board[i][j] == 1) cout << "x";
            else if(board[i][j] == 2) cout << "X";
            else if(board[i][j] == 3) cout << "o";
            else if(board[i][j] == 4) cout << "O";
            cout << " ";
        }
        cout << endl;
    }
}


