class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long cnt = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int a = nums[i];

            // We want count of j > i such that:
            // lower - a <= nums[j] <= upper - a

            int lo = lower - a;
            int hi = upper - a;

            // Use binary search to find valid range in sorted array after i
            auto it1 = lower_bound(nums.begin() + i + 1, nums.end(), lo);
            auto it2 = upper_bound(nums.begin() + i + 1, nums.end(), hi);

            cnt += (it2 - it1);  // count of valid j's
        }

        return cnt;
    }
};
