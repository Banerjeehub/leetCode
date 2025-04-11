class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> ans;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!ans.empty() && ans.back() > 0 && a < 0) {

                if (ans.back() < abs(a)) {
                    ans.pop_back();
                    continue;
                } else if (ans.back() == abs(a)) {
                    ans.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                ans.push_back(a);
            }
        }
        return ans;
    }
};