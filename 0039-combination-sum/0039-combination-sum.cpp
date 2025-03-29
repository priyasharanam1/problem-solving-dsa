class Solution {
public:
    void findCombinations(vector<vector<int>>&ans, vector<int>ds, vector<int>&arr, int target, int n, int ind){
        if(ind == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            findCombinations(ans,ds,arr,target-arr[ind],n,ind);
            ds.pop_back();
        }
        findCombinations(ans,ds,arr,target,n,ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(ans, ds, arr, target, n, 0);
        return ans;
    }
};