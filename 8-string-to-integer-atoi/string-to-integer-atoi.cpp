class Solution {
public:
    int myAtoi(string s) {
        
        double ans = 0;
        int i = 0;

        while(s[i] == ' ')
        {
            i++;
        }
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true ? i++ : i;
        negative == true ? i++ : i; 

        while(i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            ans = ans*10 + (s[i] - '0');
            i++;
        }
        if(negative) ans = -1 * ans;
        ans = (ans > INT_MAX) ? INT_MAX : ans;
        ans = (ans < INT_MIN) ? INT_MIN : ans;
        
        return static_cast<int>(ans);
    }
};