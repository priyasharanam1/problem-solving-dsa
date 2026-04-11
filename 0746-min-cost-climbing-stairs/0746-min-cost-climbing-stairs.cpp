class Solution {
public:
    int helper(vector<int>&cost, int n, vector<int>&dp){
        if(n==0 || n==1) return dp[n]=cost[n];
        if(dp[n]!=-1) return dp[n];
        int oneStep = helper(cost, n-1, dp) + cost[n];
        int twoStep = helper(cost, n-2, dp) + cost[n];
        return dp[n] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,-1);
        return min(helper(cost,n-1,dp), helper(cost,n-2,dp));
    }
};