#define ll long long
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,ll>freq;
        ll cnt=0,ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            cnt += freq[nums[r]];
            freq[nums[r]]++;

            while(cnt>=k){
                ans += (n-r);
                freq[nums[l]]--;
                cnt -= freq[nums[l]];
                l++;
            }
        }
        return ans;
    }
};