class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        vector<vector<string>>ans;
        string prefix = "";

        for(char ch : searchWord)
        {
            vector<string>temp;
            prefix += ch;
            auto it = lower_bound(products.begin(), products.end(), prefix);
            for(int i = 0; i < 3 && (it + i) != products.end(); i++)
            {
                if((*(it + i)).find(prefix) == 0)
                {
                    temp.push_back((*(it + i)));
                    
                }
                else break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};