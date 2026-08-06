class Solution {
public:
    vector<int> dp;

    bool func(string& s, unordered_set<string>& st, int idx) {
        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string test = "";

        for (int i = idx; i < s.size(); i++) {
            test.push_back(s[i]);

            if (st.count(test)) {
                if (func(s, st, i + 1))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        dp.assign(s.size(), -1);

        return func(s, st, 0);
    }
};