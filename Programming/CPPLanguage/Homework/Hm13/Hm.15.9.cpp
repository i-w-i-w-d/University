#include <iostream>
#include <vector>
using namespace std;

class Move {
public:
    int dx, dy;
    Move(int x, int y) : dx(x), dy(y) {}
};

class Figure {
public:
    string name;
    vector<Move> moves;
    Figure(string n, vector<Move> m) : name(n), moves(m) {}
};

class GameBoard {
public:
    int size;
    string game;
    vector<vector<Figure*>> board;
    
    GameBoard(int s, string g) : size(s), game(g) {
        board.resize(size, vector<Figure*>(size, nullptr));
    }
    
    void place(int x, int y, Figure* fig) {
        if (x >= 0 && x < size && y >= 0 && y < size) {
            board[x][y] = fig;
        }
    }
    
    void show() {
        cout << game << " " << size << "x" << size << ":\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j]) cout << board[i][j]->name[0] << " ";
                else cout << ". ";
            }
            cout << endl;
        }
    }
};