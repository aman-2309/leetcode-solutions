class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> vec(n+1,0);
        vector<bool> flag(n+1,true);
        for(auto &v:trust){
            vec[v[1]]++;
            flag[v[0]]=false;
            
        }
        for(int i=1;i<=n;i++){
            if(vec[i]==n-1 and flag[i]){
                return i;
            }
        }
        return -1;
    }
};