class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mpp;
        int n = nums.size();
        int secondLastOcc=-1;
        for(int i=n-1;i>=0;i--){
            if(mpp.find(nums[i])!=mpp.end()){
                secondLastOcc=i;
                break;
            }
            mpp[nums[i]]++;
        }
        return ceil((double)(secondLastOcc+1)/3);
    }
};