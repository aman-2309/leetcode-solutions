class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int l = 0;
        int r = 0;
        int n = fruits.size();
        int ans = 0;
        for(int r=0;r<n;r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};