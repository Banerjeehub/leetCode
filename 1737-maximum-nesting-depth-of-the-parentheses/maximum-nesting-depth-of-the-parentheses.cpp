class Solution {
public:
    int maxDepth(string s) {
        
        int openCount = 0;
        int maxi = 0;
        for(char it : s)
        {
            if(it == '(')
            {
                openCount++;
                maxi = max(openCount, maxi);
            }
            else if(it == ')')
            {
                openCount--;
            }
        }

        return maxi;
    }
};