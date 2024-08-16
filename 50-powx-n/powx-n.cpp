class Solution {
public:
    double f(double x, int n)
    {
        if(n == 0) return 1;
        if(n < 0)
        {
            n = abs(n);
            x = 1/x;
        }
        if(n % 2)
        {
            return x * f(x, n-1);
        }
        else
        {
            return f(x*x, n/2);
        }
    }
    double myPow(double x, int n) {
        
        return f(x, n);
    }
};