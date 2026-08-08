class Solution {
public:
    void bfs(int m, int n, int a, int b, queue<pair<int, int>>& qu,
             vector<vector<char>>& board) {
        board[a][b] = '*';
        qu.push({a, b});
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> qu;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                bfs(m, n, i, 0, qu, board);
            if (board[i][n - 1] == 'O')
                bfs(m, n, i, n - 1, qu, board);
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O')
                bfs(m, n, 0, j, qu, board);
            if (board[m - 1][j] == 'O')
                bfs(m, n, m - 1, j, qu, board);
        }

        while (!qu.empty()) {
            auto [a, b] = qu.front();
            qu.pop();
            for (auto& v : dir) {
                int nr = a + v[0];
                int nc = b + v[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    board[nr][nc] == 'O') {

                    bfs(m, n, nr, nc, qu, board);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};