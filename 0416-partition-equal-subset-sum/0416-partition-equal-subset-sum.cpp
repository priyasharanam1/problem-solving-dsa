class Solution {
public:
    bool f(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,0), cur(k+1,0);

    prev[0] = cur[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j < arr[i - 1]) {
                cur[j] = prev[j]; // Exclude current element
            } else {
                cur[j] = prev[j] || prev[j - arr[i - 1]]; // Exclude or include current element
            }
        }
        prev = cur;
    }

    return prev[k];
}
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++) sum+=arr[i];
        if(sum % 2) return false;
        int target = sum / 2;
        //now we will find out whether a subset with sum = target exists or not
        //if 1 such subset is found this means there is another such subset too
        return f(n,target,arr);
    }
};