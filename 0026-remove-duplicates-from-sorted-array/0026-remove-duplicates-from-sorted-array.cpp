class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;
        for(int i=0,j=1;i<nums.size(),j<nums.size();){
            if(nums[j]==nums[i]){
                nums[j]=101;
                j++;
            }else{
                count++;
                i=j;
                j++;
            }
        }
        sort(nums.begin(),nums.end());
        return count;
    }
};