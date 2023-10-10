class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        set<int>st;
        for(const auto &it : nums)
        {
            st.insert(it);
        }
        nums.clear();
        for(const auto& it : st)
        {
            nums.push_back(it);
        }
        sort(nums.begin(), nums.end());
        int maxCount = INT_MIN;
        int end = 0;
        for(int start = 0; start < nums.size(); start++)
        {
            while(end < nums.size() && nums[end] < nums[start] + size )
            {
                end += 1;
            }

            int candidateCount = end - start;
            maxCount = max(maxCount, candidateCount);
        }

        return size - maxCount;
    }
};