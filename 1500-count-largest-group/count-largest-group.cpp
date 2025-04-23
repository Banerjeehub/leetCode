#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> digitSumCache;

    Solution() {
        digitSumCache = vector<int>(10001, -1);
    }

    int getSum(int n) {
        if (digitSumCache[n] != -1) return digitSumCache[n];
        int sum = 0, x = n;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return digitSumCache[n] = sum;
    }

    int countLargestGroup(int n) {
        vector<int> group(37, 0); // max digit sum can be 36
        int maxSize = 0;

        for (int i = 1; i <= n; i++) {
            int sum = getSum(i);
            group[sum]++;
            maxSize = max(maxSize, group[sum]);
        }

        int count = 0;
        for (int size : group) {
            if (size == maxSize) count++;
        }

        return count;
    }
};