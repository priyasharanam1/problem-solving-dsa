class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        //sort the array and find the minimum element
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        //impossible case
        if(mini<k) return -1;

        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>k){
                cnt++;
                while(i+1<n && nums[i]==nums[i+1]) i++;
            }
        }
        return cnt;
    }
};