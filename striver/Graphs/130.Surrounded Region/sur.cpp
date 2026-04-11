#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int x, int y) {
        vis[x][y] = true;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size()) {
                if (!vis[nx][ny] && board[nx][ny] == 'O') {
                    dfs(board, vis, nx, ny);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Top row
        for (int j = 0; j < n; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(board, vis, 0, j);
            }
        }

        // Left column
        for (int i = 0; i < m; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(board, vis, i, 0);
            }
        }

        // Right column
        for (int i = 0; i < m; i++) {
            if (!vis[i][n - 1] && board[i][n - 1] == 'O') {
                dfs(board, vis, i, n - 1);
            }
        }

        // Bottom row
        for (int j = 0; j < n; j++) {
            if (!vis[m - 1][j] && board[m - 1][j] == 'O') {
                dfs(board, vis, m - 1, j);
            }
        }

        // Convert surrounded 'O' to 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    Solution obj;

    vector<vector<char>> board = {
        {'X','O','X'},
        {'O','X','O'},
        {'X','O','X'}
    };

    obj.solve(board);

    cout << "Final Board:\n";
    for (auto &row : board) {
        for (auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}