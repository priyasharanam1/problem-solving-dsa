class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> distinctSet(nums.begin(), nums.end());
        int totalDistinct = distinctSet.size();

        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freqMap;
            int distinctCount = 0;

            for (int j = i; j < n; ++j) {
                if (freqMap[nums[j]] == 0) {
                    distinctCount++;
                }
                freqMap[nums[j]]++;

                if (distinctCount == totalDistinct) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
