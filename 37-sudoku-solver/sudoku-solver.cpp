class Solution {
public:
    vector<int> nextEmptySpace(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    return {i, j};
                }
            }
        }

        return {};
    }
    bool isSafe(int row, int col, char val, vector<vector<char>>& board){
        // for the row
        for(int c = 0; c < 9; c++){
            if(board[row][c] == val){
                return false;
            }
        }

        // for the col
        for(int r = 0; r < 9; r++){
            if(board[r][col] == val){
                return false;
            }
        }

        // for the 3 * 3 blocks
        int sRow = row / 3 * 3;
        int sCol = col / 3 * 3;

        for(int i=sRow; i<sRow+3; i++){
            for(int j=sCol; j<sCol+3; j++){
                if(board[i][j] == val){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board) {
        auto pos = nextEmptySpace(board);
        if (pos.empty()) {
            return true;
        }
        int row = pos[0];
        int col = pos[1];
        for (char i = '1'; i <= '9'; i++) {
            if (isSafe(row, col, i, board)) {
                board[row][col] = i;
                if(helper(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};