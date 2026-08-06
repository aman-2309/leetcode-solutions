class Solution {
public:
    void func(vector<string>& result, string& s, int n, int left, int right) {
        if (s.size() == (2 * n)) {
            if (left == right)
                result.push_back(s);
            return;
        }
        if (left < n) {
            s.push_back('(');
            func(result, s, n, left + 1, right);
            s.pop_back();
        }
        if (left > right) {
            s.push_back(')');
            func(result, s, n, left, right + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> result;
        func(result, s, n, 0, 0);
        return result;
    }
};