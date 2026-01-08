class Solution {
public:
    bool helper(int row, int col, int idx, string &word, vector<vector<char>>& board, vector<vector<int>>&visited){
        if(idx == word.size()){
            return true;
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && !visited[nr][nc] && board[nr][nc] == word[idx]){
                visited[nr][nc] = 1;
                if (helper(nr, nc, idx+1, word, board, visited)) return true;
                visited[nr][nc] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if(helper(i, j, 1, word, board, visited)) return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};