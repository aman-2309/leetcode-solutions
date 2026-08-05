class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int ans = 1;
        int left = points[0][0];
        int right = points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>right){
                ans++;
                right = points[i][1];
            } 
            else {
                right = min(right,points[i][1]);
            }
        }
        return ans;
    }
};