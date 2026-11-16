
#include <iostream>
#include <vector>
using namespace std;

// TC = O(n!)
// SC = O(n) recursion stack

vector<vector<string>> result;
int N;

bool isValid(vector<string> &board, int row, int col) {

    // Upward check
    for(int i = row-1; i >= 0; i--) {
        if(board[i][col] == 'Q') return false;
    }

    // Upper-right diagonal
    for(int i = row-1, j = col+1;
        i >= 0 && j < N; i--, j++) {

        if(board[i][j] == 'Q') return false;
    }

    // Upper-left diagonal
    for(int i = row-1, j = col-1;
        i >= 0 && j >= 0; i--, j--) {

        if(board[i][j] == 'Q') return false;
    }

    return true;
}

void solve(vector<string> board, int row) {

    if(row >= N) {
        result.push_back(board);
        return;
    }

    for(int col = 0; col < N; col++) {

        if(isValid(board, row, col)) {

            board[row][col] = 'Q';

            solve(board, row+1);

            // Backtracking
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveQueens(int n, int firstRow, int firstCol) {

    result.clear();
    N = n;

    vector<string> board(n, string(n,'.'));

    // Place first Queen at user-given position
    board[firstRow][firstCol] = 'Q';

    // Start from the next row
    solve(board, firstRow + 1);

    return result;
}

int main() {

    int n;
    cout << "Enter board size: ";
    cin >> n;

    int row, col;

    cout << "Enter first Queen row (0 to " << n-1 << "): ";
    cin >> row;

    cout << "Enter first Queen column (0 to " << n-1 << "): ";
    cin >> col;

    if(row < 0 || row >= n || col < 0 || col >= n) {
        cout << "Invalid position!";
        return 0;
    }

    vector<vector<string>> ans = solveQueens(n, row, col);

    for(int i = 0; i < ans.size(); i++) {

        cout << "\nSolution : " << i+1 << endl;

        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << endl;
        }
    }

    if(ans.empty()) {
        cout << "\nNo solution exists!";
    }

    return 0;
}
