class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26,0);
        queue<char> qu;
        for(char ch:s){
            qu.push(ch);
            v[ch-'a']++;
        }
        int idx = 0;
        while(!qu.empty()){
            if(v[qu.front()-'a']==1) return idx;
            qu.pop();
            idx++;
        }
        return -1;
    }
};