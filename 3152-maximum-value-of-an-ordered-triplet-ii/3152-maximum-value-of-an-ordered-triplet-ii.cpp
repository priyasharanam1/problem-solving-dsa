#define ll long long 
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll maxTriplet=0LL;
        int maxDiff=0, maxEl=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxTriplet = max(maxTriplet,(ll)maxDiff*nums[i]);
            maxDiff = max(maxDiff,maxEl-nums[i]);
            maxEl = max(maxEl,nums[i]);
        }
        return maxTriplet;
    }
};