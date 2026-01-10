class Solution {
public:
    void helper(int idx, int n, int &count,vector<int>&col, vector<int>&diag, vector<int>&antiDiag){
        if(idx == n){
            count++;
            return;
        }

        for(int i=0; i<n; i++){
            if(!col[i] && !diag[idx-i + (n-1)] && !antiDiag[idx+i]){
                col[i] = 1;
                diag[idx-i+(n-1)] = 1;
                antiDiag[idx+i] = 1;
                helper(idx+1, n, count, col, diag, antiDiag);
                col[i] = 0;
                diag[idx-i+(n-1)] = 0;
                antiDiag[idx+i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int>col(n, 0), diag(2*n, 0), antiDiag(2*n, 0);
        int count = 0;
        helper(0, n, count, col, diag, antiDiag);
        return count;
    }
};