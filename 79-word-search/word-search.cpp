class Solution {
public:
    bool helper(int row, int col, int idx, int n, int m,
                vector<vector<char>>& board, vector<vector<int>>& visited,
                string word) {
        if (idx == word.size()) return true;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for(int i=0; i<4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && board[nr][nc] == word[idx]){
                visited[nr][nc] = 1;
                if(helper(nr, nc, idx+1, n, m, board, visited, word)) return true;
                visited[nr][nc] = 0;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = 1;
                    if (helper(i, j, 1, n, m, board, visited, word))
                        return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};