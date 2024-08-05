class Solution {
public:
    int f(int i, vector<int>& freq, vector<int>& memo) {
        if (i < 0) return 0; // Base case
        
        // Check if this state is already computed
        if (memo[i] != -1) return memo[i];
        
        // Option not to take the current number
        int notTake = f(i - 1, freq, memo);
        
        // Option to take the current number
        int take = freq[i] * i + f(i - 2, freq, memo);
        
        // Store and return the maximum of taking or not taking
        return memo[i] = max(take, notTake);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Step 1: Count frequency of each number
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> freq(max_num + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Initialize memoization table
        vector<int> memo(max_num + 1, -1);
        
        // Step 3: Compute the result
        return f(max_num, freq, memo);
    }
};