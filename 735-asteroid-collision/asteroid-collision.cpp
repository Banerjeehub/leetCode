class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> res;

        for (int a : as) {
            bool destroyed = false;

            while (!res.empty() && res.back() > 0 && a < 0) {
                if (res.back() < -a) {
                    res.pop_back(); // previous asteroid destroyed
                    continue;
                } else if (res.back() == -a) {
                    res.pop_back(); // both destroy each other
                }
                destroyed = true;
                break;
            }

            if (!destroyed) {
                res.push_back(a);
            }
        }

        return res;
    }
};