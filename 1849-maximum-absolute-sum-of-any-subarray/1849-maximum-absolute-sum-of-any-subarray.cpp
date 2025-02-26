class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0, sum2 = 0, maxSum = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums[i];
            sum2 += nums[i] * (-1);
            maxSum = max(maxSum, max(sum1,sum2));
            if (sum1 < 0)
                sum1 = 0;
            if (sum2 < 0)
                sum2 = 0;
        }
        return maxSum;
    }
};