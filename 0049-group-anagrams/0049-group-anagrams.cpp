class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(string str:strs){
            string st = str;
            sort(st.begin(),st.end());
            mp[st].push_back(str);
        }
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};