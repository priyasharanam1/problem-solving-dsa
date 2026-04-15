class Solution {
public:
    int f(vector<int>& coins, int amount, int n, vector<vector<int>>&dp){
        if(n==0){
            if(amount%coins[n]==0) return dp[n][amount] = amount/coins[n];
            return 1e9;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        int pick = INT_MAX;
        if(amount>=coins[n]) pick = 1 + f(coins, amount-coins[n], n, dp);
        int notPick = f(coins, amount, n-1, dp);
        return dp[n][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int ans = f(coins, amount, n-1, dp);
        if(ans==1e9) return -1;
        return ans;
    }
};