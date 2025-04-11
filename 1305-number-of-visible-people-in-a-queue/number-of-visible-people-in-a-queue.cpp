class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        vector<int>ans(heights.size(), 0);
        stack<int>st;

        for(int i=heights.size()-1; i>=0; i--)
        {
            int count = 0;
            while(!st.empty() && heights[i] > st.top())
            {
                st.pop();
                count++;
            }
            if(!st.empty())
            {
                count++;
            }

            ans[i] = count;
            st.push(heights[i]);
        }

        return ans;
    }
};