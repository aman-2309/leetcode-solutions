class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for(auto &str:operations){
            if(str=="+"){
                v.push_back(v[v.size()-1]+v[v.size()-2]);
            }else if(str=="D"){
                v.push_back(2*v[v.size()-1]);
            }else if(str=="C"){
                v.pop_back();
            }else{
                v.push_back(stoi(str));
            }
        }
        int ans = 0;
        for(auto &ele:v) ans+=ele;
        return ans;
    }
};