class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (const auto& pair : mp) {
            pq.push({pair.second,pair.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while (pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};