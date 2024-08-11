
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double sum = 0;
        double maxAverage = -numeric_limits<double>::infinity();
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        maxAverage = max(maxAverage, sum / k);
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k]; 
            maxAverage = max(maxAverage, sum / k);  
        }

        return maxAverage;
    }
};