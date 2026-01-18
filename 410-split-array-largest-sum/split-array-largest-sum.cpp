class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;
            int numberOfSubs = 1;
            int sum = 0;

            for(int i=0; i<nums.size(); i++){
                if(sum + nums[i] > mid){
                    numberOfSubs++;
                    sum = nums[i];
                }
                else sum += nums[i];
            }

            if(numberOfSubs <= k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};