class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        int totalRabbits = 0;
        unordered_map<int, int>freq;
        for(auto it : answers)
        {
            freq[it]++; // how many rabbits have the same count will save it
        }

        for(auto it : freq)
        {
            int groupSize = it.first + 1; // total count of the same colour including this one
            int totalGroups = ceil(double(it.second) / groupSize); // how many groups needed to seperate the total counts
            totalRabbits += groupSize * totalGroups;

        }

        return totalRabbits;
    }
};