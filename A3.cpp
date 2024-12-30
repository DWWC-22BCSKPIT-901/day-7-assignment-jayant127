#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
    // Check if the current position is out of bounds or the character doesn't match
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
        return false;
    }

    // Check if all characters in the word have been found
    if (index == word.size() - 1) {
        return true;
    }

    // Temporarily mark the current cell as visited
    char temp = board[i][j];
    board[i][j] = '#';

    // Explore all four possible directions (up, down, left, right)
    bool found = dfs(board, word, i + 1, j, index + 1) ||
                 dfs(board, word, i - 1, j, index + 1) ||
                 dfs(board, word, i, j + 1, index + 1) ||
                 dfs(board, word, i, j - 1, index + 1);

    // Restore the original value of the cell
    board[i][j] = temp;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // Start a DFS if the first character matches
            if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int m, n;
    cout << "Enter the number of rows (m): ";
    cin >> m;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    vector<vector<char>> board(m, vector<char>(n));
    cout << "Enter the board characters row by row:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cout << "Enter the word to search: ";
    cin >> word;

    if (exist(board, word)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
