class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        sort(products.begin(), products.end());
        string prefix = "";
        vector<vector<string>> ans;

        for (auto ch : searchWord) {
            vector<string> temp;
            prefix += ch;
            for (auto product : products) {
                if (product.find(prefix) == 0) {
                    temp.push_back(product);
                    if (temp.size() == 3) {
                        break;
                    }
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};