class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n,0);
        for(auto &v:bookings){
            int l = v[0]-1;
            int r = v[1];
            int seat = v[2];
            diff[l]+=seat;
            if(r<n) diff[r]-=seat;

        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        return diff;

    }
};