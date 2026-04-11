class Solution {
public:
    int help(vector<int>& nums, int n, vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return dp[n]=nums[n];
        if(dp[n]!=-1) return dp[n];
        int rob = help(nums,n-2,dp)+nums[n];
        int skip = help(nums,n-1,dp);
        return dp[n]=max(rob,skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return help(nums,n-1,dp);
    }
};