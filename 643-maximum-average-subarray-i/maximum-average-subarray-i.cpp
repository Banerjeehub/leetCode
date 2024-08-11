#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Initialize the sum and maximum average
        double sum = 0;
        double maxAverage = -numeric_limits<double>::infinity();

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // Calculate the average of the first window
        maxAverage = max(maxAverage, sum / k);

        // Slide the window across the array
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];  // Update the sum for the new window
            maxAverage = max(maxAverage, sum / k);  // Calculate the average
        }

        return maxAverage;
    }
};