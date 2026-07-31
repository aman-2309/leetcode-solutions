class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        unordered_multimap<int,int> m;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto pair:mp){
            m.insert({pair.second,pair.first});

        }
        priority_queue<pair<int,int>> pq;
        for(auto pair:m){
            pq.push(pair);
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();

        }
        return ans;
    }
};