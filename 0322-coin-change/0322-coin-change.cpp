class Solution {
public:
    int f(int i, int target, vector<int>& a, vector<vector<int>>& dp){
        if(i==0){
            if(target%a[i] == 0) return target/a[i];
            return 1e9;
        }
        if(dp[i][target] != -1) return dp[i][target];
        int notpick = 0 + f(i-1,target,a,dp);
        int pick = INT_MAX;
        if(a[i]<=target) pick = 1 + f(i,target-a[i], a,dp);
        return dp[i][target] = min(notpick,pick);
    }
    int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1,amount,a,dp);
        if(ans==1e9) return -1;
        return ans; 
    }
};