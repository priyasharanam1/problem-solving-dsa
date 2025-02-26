class Solution {
public:
    int solveOriginal(vector<int>& nums,int n){
        int sum=0, maxSum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
    int solveNegated(vector<int>& nums,int n){
        int sum=0, maxSum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]*(-1);
            maxSum=max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        return max(solveOriginal(nums,n), solveNegated(nums,n));
    }
};