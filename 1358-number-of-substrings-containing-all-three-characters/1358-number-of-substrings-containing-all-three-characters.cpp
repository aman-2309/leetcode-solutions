class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 0;

        int r = 0;
        for (; r < n; r++) {
            mp[s[r]]++;
            if (mp.size() == 3) {
                ans += (n - r);
                r++;
                break;
            }
        }

        for (int l = 0; l < n; l++) {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                mp.erase(s[l]);
            if (mp.size() == 3) {
                ans+=(n-r+1);
            } else {
                while (mp.size() < 3 and r < n) {
                    mp[s[r]]++;
                    if (mp.size() == 3) {
                        ans += (n - r);
                        r++;
                        break;
                    }
                    r++;
                }
            }
        }

        return ans;
    }
};