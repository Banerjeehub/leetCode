class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int totalRabbits = 0;
        unordered_map<int, int> freq;

        for (auto it : answers) {
            freq[it]++;
        }

        for (auto it : freq) {
            int groupSize = it.first + 1;
            int totalGroups = ceil((double)it.second / groupSize);
            totalRabbits += totalGroups * groupSize;
        }

        return totalRabbits;
    }
};