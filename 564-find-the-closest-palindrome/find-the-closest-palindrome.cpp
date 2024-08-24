class Solution {
public:
    string nearestPalindromic(string n) {

        int len = n.size();
        set<string> candidates;

        candidates.insert(string(len - 1, '9'));
        candidates.insert("1" + string(len - 1, '0') + "1");

        long prefix = 0;

        try {
            prefix = stol(n.substr(0, (len + 1) / 2));
        } catch (const invalid_argument& e) {
            return "";
        }

        // generate the possible answers

        for (int i = -1; i <= 1; i++) {
            string str = to_string(prefix + i);
            string candidate;

            if (len % 2 == 0) {
                candidate = str + string(str.rbegin(), str.rend());
            } else {
                candidate = str + string(str.rbegin() + 1, str.rend());
            }

            candidates.insert(candidate);
        }

        candidates.erase(n);

        string ans;
        long min_diff = LONG_MAX;

        for (auto it : candidates) {
            long diff = 0;
            try {

                diff = abs(stol(it) - stol(n));
            } catch (const invalid_argument& e) {
                continue;
            }

            if (diff < min_diff || (diff == min_diff && stol(it) < stol(ans))) {
                min_diff = diff;
                ans = it;
            }
        }

        return ans;
    }
};