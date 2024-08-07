class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            string word = top.first;
            int steps = top.second;

            if (word == endWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (int j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if (st.find(word) != st.end()) {
                        q.push({word, steps+ 1});
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }
        return 0;
    }
};