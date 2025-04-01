#define ll long long
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int points = questions[i][0];
            int skip = questions[i][1];

            ll pick = points;
            if(i+skip+1 < n) pick += dp[i+skip+1];

            ll notPick = dp[i+1];
            dp[i] = max(pick,notPick);
        }
        return dp[0];
    }
};