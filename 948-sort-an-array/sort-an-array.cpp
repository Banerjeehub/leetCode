class Solution {
public:
    void heapify(int i, int size, vector<int>&nums)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < size && nums[left] > nums[largest])
        {
            largest = left;
        }
        if(right < size && nums[right] > nums[largest])
        {
            largest = right;
        }

        if(largest != i)
        {
            swap(nums[largest], nums[i]);
            heapify(largest, size, nums);
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--)
        {
            heapify(i, n, nums);
        }
        for(int i=nums.size()-1; i>0; i--)
        {
            swap(nums[0], nums[i]);
            heapify(0, i, nums);
        }

        return nums;
    }
};