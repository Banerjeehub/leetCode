class Solution {
public:
    string nearestPalindromic(string n) {
        int length = n.size();
        set<string> candidates;

        // Edge cases: smallest and largest possible palindromes around the length of n
        candidates.insert(string(length - 1, '9'));  // "999...999"
        candidates.insert("1" + string(length - 1, '0') + "1");  // "100...001"

        // Prefix of the first half
        long prefixNum = 0;
        try {
            prefixNum = stol(n.substr(0, (length + 1) / 2));
        } catch (const invalid_argument& e) {
            // Handle invalid argument if stol fails
            return "";
        }

        // Generate candidates by modifying the prefix
        for (int i = -1; i <= 1; i++) {
            string prefix = to_string(prefixNum + i);
            string candidate;

            if (length % 2 == 0) {
                candidate = prefix + string(prefix.rbegin(), prefix.rend());
            } else {
                candidate = prefix + string(prefix.rbegin() + 1, prefix.rend());
            }

            candidates.insert(candidate);
        }

        // Remove the original number itself from the set of candidates
        candidates.erase(n);

        // Find the closest palindrome
        string closest;
        long minDiff = LONG_MAX;

        for (const string& candidate : candidates) {
            long diff = 0;
            try {
                diff = abs(stol(candidate) - stol(n));
            } catch (const invalid_argument& e) {
                // Handle invalid argument if stol fails
                continue;
            }

            if (diff < minDiff || (diff == minDiff && stol(candidate) < stol(closest))) {
                minDiff = diff;
                closest = candidate;
            }
        }

        return closest;
    }
};