class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        string temp;
        for(auto ch : s)
        {
            temp.push_back(ch);

            while(temp.size() >= part.size() &&
            temp.substr(temp.size() - part.size()) == part)
            {
                temp.erase(temp.size() - part.size());
            }
        }

        return temp;
    }
};