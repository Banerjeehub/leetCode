class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> result;
        long long start = pow(10, (intLength - 1) / 2); // The smallest number of the base string
        long long end = pow(10, (intLength + 1) / 2); // One past the largest number of the base string

        for (int query : queries) {
            long long baseNumber = start + query - 1;
            if (baseNumber >= end) {
                result.push_back(-1); // Not enough palindromes
                continue;
            }

            string baseStr = to_string(baseNumber);
            string palindrome;

            if (intLength % 2 == 0) {
                // Even length
                palindrome = baseStr + string(baseStr.rbegin(), baseStr.rend());
            } else {
                // Odd length
                palindrome = baseStr + string(baseStr.rbegin() + 1, baseStr.rend());
            }

            result.push_back(stoll(palindrome));
        }

        return result;
    }
};