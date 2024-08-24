class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int minReps = (b.size() + a.size() - 1) / a.size(); // Ceiling of b.size() / a.size()
        
        
        string repeatedA = a;
        for (int i = 1; i < minReps; ++i) {
            repeatedA += a;
        }
        
        // Check if b is a substring of the repeated string
        if (repeatedA.find(b) != string::npos) {
            return minReps;
        }
        
        // Add one more repetition and check again
        repeatedA += a;
        if (repeatedA.find(b) != string::npos) {
            return minReps + 1;
        }
        
        // If not found in either case, return -1
        return -1;
    }
};