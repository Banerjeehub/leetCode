#include <string>
#include <vector>

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int factorial = 1;
        
        // Create a list of numbers and compute (n-1)!
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
            if (i < n) {
                factorial *= i;
            }
        }
        
        k--; // convert to 0-based index
        string result;
        
        for (int i = 0; i < n; i++) {
            int index = k / factorial;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            
            if (i < n - 1) {
                k %= factorial;
                factorial /= (n - 1 - i);
            }
        }
        
        return result;
    }
};
