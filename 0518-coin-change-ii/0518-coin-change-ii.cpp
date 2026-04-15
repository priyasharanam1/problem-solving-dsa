class Solution {
public:
    int f(int amount, vector<int>& coins, int n, vector<vector<int>>&dp){
        if(n==0) return dp[n][amount] = amount%coins[n] == 0;
        if(dp[n][amount] != -1) return dp[n][amount]; 
        int pick = 0;
        if(amount>=coins[n]) pick = f(amount-coins[n], coins, n, dp);
        int notPick = f(amount, coins, n-1, dp);
        return dp[n][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return f(amount, coins, n-1, dp);
    }
};