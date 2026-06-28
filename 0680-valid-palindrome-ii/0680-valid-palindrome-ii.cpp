class Solution {
public:
    bool pali(string& s, int l, int r) {
        for (; l < r; l++, r--) {
            if (s[l] != s[r])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        for (; l < r; l++, r--) {
            if (s[l] != s[r]) {

                return pali(s, l + 1, r) or pali(s, l, r - 1);
            }
        }
        return true;
    }
};