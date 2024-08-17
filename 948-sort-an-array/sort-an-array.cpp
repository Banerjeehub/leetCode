class Solution {
public:
    void ms(int s, int mid, int e, vector<int>&nums)
    {
        int left = s;
        int right = mid + 1;
        vector<int>temp;

        while(left <= mid && right <= e)
        {
            if(nums[left] < nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else temp.push_back(nums[right++]);
        }
        while(left <= mid)
        {
            temp.push_back(nums[left++]);
        }
        while(right <= e)
        {
            temp.push_back(nums[right++]);
        }

        for(int i=s; i<=e; i++)
        {
            nums[i] = temp[i-s];
        }
    }
    void merge(int s, int e, vector<int>&nums)
    {
        if(s >= e) return;
        int mid = (s + e)/2;

        merge(s, mid, nums);
        merge(mid+1, e, nums);

        ms(s, mid, e, nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        merge(0, nums.size()-1, nums);
        return nums;
    }
};