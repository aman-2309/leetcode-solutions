class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1<<n;
        total--;
        vector<vector<int>> ans;
        while(total>=0){
            int t = total;
            vector<int> v;
            for(int i=0;i<n;i++){
                if(t&1){
                    v.push_back(nums[i]);
                }
                t=t>>1;
            }
            ans.push_back(v);
            total--;
        }
        return ans;
    }
};