class Solution {
public:
    int myAtoi(string s) {
        bool sign = false;
        char si = '+';
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                sign = true;
                if(j>0){
                    s[j++] = s[i];
                }else{
                    continue;
                }
                
                
            } else if (s[i] >= '1' and s[i] <= '9') {
                s[j++] = s[i];
                sign = true;
            } else if (s[i] == '+') {
                if (sign) {
                    break;
                } else {
                    sign = true;
                }
            } else if (s[i] == '-') {
                if (sign) {
                    break;
                } else {
                    sign = true;
                    si = '-';
                }
            } else if (s[i] == ' ') {
                if (sign) {
                    break;
                }
            } else
                break;
        }
        s.resize(j);
        if (j == 0)
            return 0;
        if (j > 10) {
            return (si == '+') ? INT_MAX : INT_MIN;
        }
        long ans = stol(s);

        if (si == '-') {
            ans *= -1;
            return max<long>(INT_MIN, ans);
        }
        return min<long>(INT_MAX, ans);
    }
};