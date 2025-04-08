class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        // int secondLastOcc=-1; (i will storesecond last occurrence)
        for(int i=n-1;i>=0;i--){
            if(mpp.find(nums[i])!=mpp.end()){
                return i/3 + 1;
            }
            mpp[nums[i]]++;
        }
        return 0;
    }
};