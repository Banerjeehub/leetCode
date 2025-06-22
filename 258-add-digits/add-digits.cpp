class Solution {
public:
    int addDigits(int num) {
        // pre-order recurssion

        if (num < 10)
            return num;

        int sum = 0;
        while (num > 0) {
            int mod = num % 10;
            sum += mod;
            num /= 10;
        }

        return addDigits(sum);
    }
};