class Solution {
public:
    int sumOfDigit(int num) {
        if(num == 0) return num;
        return num % 10 + sumOfDigit(num/10);
        
    }
    int addDigits(int num) {
        // pre-order recurssion

        if (num < 10)
            return num;
        return addDigits(sumOfDigit(num));
    }
};