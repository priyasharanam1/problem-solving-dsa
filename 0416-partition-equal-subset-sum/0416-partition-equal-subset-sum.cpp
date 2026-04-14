class Solution {
public:
    bool helper(vector<int>& arr, int ind, vector<vector<int>>&dp, int n, int target){
        if(ind==0) return arr[ind]==target;
        if(target==0) return true;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notPick = helper(arr,ind-1,dp,n,target);
        int pick = false;
        if(arr[ind]<=target){
            pick = helper(arr,ind-1,dp,n,target-arr[ind]);
        }
        return dp[ind][target] = pick || notPick;
    }
    
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += arr[i];
        }
        if(totalSum & 1) return false;
        int target = totalSum / 2;
        //now check if target sum is possible or not
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return helper(arr,n-1,dp,n,target);
    }
};