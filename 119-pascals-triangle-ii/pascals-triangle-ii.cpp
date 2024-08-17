class Solution {
public:
    vector<int> generateRow(int row)
    {
        vector<int>temp;
        temp.push_back(1);
        long long ans = 1;

        for(int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<int> getRow(int rowIndex) {
        
        vector<int>ans = generateRow(rowIndex+1);
        return ans;
    }
};