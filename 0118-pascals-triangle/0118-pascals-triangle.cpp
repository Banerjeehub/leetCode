class Solution {
public:
    vector<int> generateRows(int row)
    {
        long long ans = 1;
        vector<int>temp;

        temp.push_back(1);

        for(int col=1; col<row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            temp.push_back((int)ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=1; i<=numRows; i++)
        {
            vector<int>temp = generateRows(i);
            ans.push_back(temp);
        }

        return ans;
    }
};