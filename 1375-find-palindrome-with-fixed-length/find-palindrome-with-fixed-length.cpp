class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> ans;
        long long start = pow(10, (intLength - 1) / 2);
        long long end = pow(10, (intLength + 1) / 2);

        for (int it : queries) {
            long long baseNum = start + it - 1;

            if (baseNum >= end) {
                ans.push_back(-1);
                continue;
            }
            string baseStr = to_string(baseNum);
            string palindrome;

            if (intLength % 2 == 0) {
                palindrome = baseStr + string(baseStr.rbegin(), baseStr.rend());
            } else {
                palindrome =
                    baseStr + string(baseStr.rbegin() + 1, baseStr.rend());
            }

            ans.push_back(stoll(palindrome));
        }

        return ans;
    }
};