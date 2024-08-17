class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;

        while(low <= high)
        {
            int mid = (low + high)/2;
            int midEle = matrix[mid/m][mid%m];
            if(midEle == target) return true;
            else if(midEle < target)
            {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return false;
    }
};