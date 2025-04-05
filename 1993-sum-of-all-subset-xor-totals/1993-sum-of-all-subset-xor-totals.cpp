class Solution {
public:
    int helper(vector<int>& nums, int n, int i, int xorr){
        if(i==n){
            return xorr;
        }
        int pick = helper(nums,n,i+1,xorr^nums[i]);
        int notPick = helper(nums,n,i+1,xorr);
        return pick+notPick;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,n,0,0);
    }
};