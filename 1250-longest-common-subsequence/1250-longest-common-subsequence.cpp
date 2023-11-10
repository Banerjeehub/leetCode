class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();

        // Use two arrays for current and previous rows
        vector<int> currentRow(t2 + 1, 0);
        vector<int> previousRow(t2 + 1, 0);

        for (int i = 1; i <= t1; i++) {
            // Swap currentRow and previousRow at the beginning of each outer loop iteration
            swap(currentRow, previousRow);

            for (int j = 1; j <= t2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If the characters match, extend the LCS by 1
                    currentRow[j] = 1 + previousRow[j - 1];
                } else {
                    // If the characters don't match, take the maximum of the LCS without considering one character from each string
                    currentRow[j] = max(currentRow[j - 1], previousRow[j]);
                }
            }
        }

        // The final result is stored in the last element of the currentRow array
        return currentRow[t2];
    }
};
