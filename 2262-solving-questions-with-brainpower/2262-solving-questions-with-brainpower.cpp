#define ll long long
class Solution {
public:
    ll solve(vector<vector<int>>& questions, int i, int n, vector<ll>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        ll pick = questions[i][0] + solve(questions,i+questions[i][1]+1, n,dp);
        ll notPick = solve(questions,i+1,n,dp);
        return dp[i] = max(pick,notPick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll>dp(n,-1);
        return solve(questions,0,n,dp);
    }
};