#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> board;

// Check if it's safe to place a queen at (row, col)
// This version checks against all already-placed queens anywhere on the board.
bool isSafe(int row, int col) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 1) {
                if (r == row && c == col) continue; // same cell (not needed but safe)
                // Same column?
                if (c == col) return false;
                // Same diagonal?
                if (abs(r - row) == abs(c - col)) return false;
            }
        }
    }
    return true;
}

// Recursive function to place remaining queens
bool solve(int row) {
    if (row == n) return true; // all queens placed

    // If this row already contains a queen (preplaced), skip it
    bool skipThisRow = false;
    for (int c = 0; c < n; c++) {
        if (board[row][c] == 1) { skipThisRow = true; break; }
    }
    if (skipThisRow) return solve(row + 1);

    // Try every column in current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            if (solve(row + 1)) return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    cout << "Enter size of board (n): ";
    cin >> n;
    if (n < 1) return 0;

    board = vector<vector<int>>(n, vector<int>(n, 0));

    int firstRow, firstCol;
    cout << "Enter row and column (0 to n-1) for first queen: ";
    cin >> firstRow >> firstCol;
    if (firstRow < 0 || firstRow >= n || firstCol < 0 || firstCol >= n) {
        cout << "Invalid position for first queen!" << endl;
        return 0;
    }

    board[firstRow][firstCol] = 1; // place the pre-placed queen

    if (solve(0)) {
        cout << "\nFinal N-Queens matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution found with this first queen position.\n";
    }
    return 0;
}
