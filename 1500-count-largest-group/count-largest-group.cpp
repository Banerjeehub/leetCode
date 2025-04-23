class Solution {
public:
    int getSumOfDigit(int n)
    {
        int digit = n;
        int sum = 0;
        while(digit)
        {
            int mod = digit % 10;
            sum += mod;
            digit /= 10;

        }

        return sum;
    }
    int countLargestGroup(int n) {
        int maxSize = 0;
        unordered_map<int, int>group;
        for(int i=1; i<=n; i++)
        {
            int sumOfDigit = getSumOfDigit(i);
            group[sumOfDigit]++;
            maxSize = max( group[sumOfDigit], maxSize);

        }
        int count = 0;
        for(auto it : group)
        {
            if(it.second == maxSize) count++;
        }

        return count;
    }
};