class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>dp(n,1), hash(n);
        int ans=0, lastInd=0;
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<i;prev++){
                if(nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
                lastInd = i;
            }
        }
        vector<int>answer;
        answer.push_back(nums[lastInd]);
        while(hash[lastInd] != lastInd){
             answer.push_back(nums[hash[lastInd]]);
             lastInd = hash[lastInd];
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};