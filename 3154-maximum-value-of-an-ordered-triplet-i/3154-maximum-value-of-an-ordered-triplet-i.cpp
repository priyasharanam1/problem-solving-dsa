#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxEl=0;
        int maxDiff=0;
        ll maxTriplet=0LL;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxTriplet = max(maxTriplet, (ll)maxDiff*nums[i]);
            maxDiff = max(maxDiff,maxEl-nums[i]);
            maxEl = max(maxEl,nums[i]);
        }
        return maxTriplet;
    }
};