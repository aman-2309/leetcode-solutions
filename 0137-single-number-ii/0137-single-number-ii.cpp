class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> freq(32,0);
        for(int n:nums){
            int i = 0;
            while(n!=0 and i<32){
                if(n&1){
                    freq[i]++;
                }
                n = n>>1;
                i++;
            }
        }
        int ans = 0;
        for(int i=0;i<32;i++){
            if(freq[i]%3){
                ans+=(1 << i);
            }
        }

        return ans;

    }
};