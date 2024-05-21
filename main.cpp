#include <iostream>
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int checkwin();
void board();

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        board();
        if (player % 2 == 1) {
            player = 1;
        } else {
            player = 2;
        }

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        if (player == 1) {
            mark = 'X';
        } else {
            mark = 'O';

        }

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
            square[choice] = mark;
        } else {
            cout << "Invalid move! ";
            player--;
            cin.ignore();
            cin.get();
        }

        i = checkwin();
        player++;
    } while (i == -1);

    board();
    if (i == 1) {
        cout << "==>\aPlayer " << --player << " wins!";
    } else {
        cout << "==>\aGame draw!";
    }

    cin.ignore();
    cin.get();
    return 0;
}

int checkwin() {
    const int winCombos[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, // Columns
        {1, 5, 9}, {3, 5, 7}             // Diagonals
    };
    
    for (int i = 0; i < 8; i++) {
        if (square[winCombos[i][0]] == square[winCombos[i][1]] && 
            square[winCombos[i][1]] == square[winCombos[i][2]]) {
            return 1;
        }
    }
    
    for (int i = 1; i <= 9; i++) {
        if (square[i] != 'X' && square[i] != 'O') {
            return -1;
        }
    }
    
    return 0;
}

void board() {
    system("clear");
    cout << "\n==========================";
    cout << "\n\tTic Tac Toe\n";
    cout << "\n==========================\n";
    cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}
