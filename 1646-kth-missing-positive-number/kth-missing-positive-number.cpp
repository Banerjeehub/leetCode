class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missing_count = 0;
        int current = 1;
        for (int num : arr) {
            // Count missing numbers before the current element in the array
            while (current < num) {
                missing_count++;
                if (missing_count == k) {
                    return current;
                }
                current++;
            }
            current++; // Move to the next number after the current array element
        }
        // If the loop completes and k-th missing is not found, it's beyond the last element
        return current + (k - missing_count - 1);
    }
};