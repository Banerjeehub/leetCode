class Solution {
public:
    string removeOccurrences(string s, string part) {
        
         size_t pos = s.find(part);
    while (pos != string::npos) { // While part exists in s
        s.erase(pos, part.length()); // Erase the first occurrence
        pos = s.find(part); // Search again
    }
    return s;
        
    }
};