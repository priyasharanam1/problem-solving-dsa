class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            int sum = 0;
            int num = nums[i];
            while(num){
                sum += num%10;
                num/=10;
            }
            mpp[sum].push_back(nums[i]);
        }

        int ans = -1;
        for(auto it : mpp){
            vector<int>v = it.second;
            int sz = v.size();
            if(sz<2) continue;
            sort(v.begin(),v.end());
            ans = max(ans, v[sz-1]+v[sz-2]);
        }
        return ans;
    }
};