class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long oddCnt=0, prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            oddCnt += (prefixSum&1);
            oddCnt %= MOD;
        }
        //oddcount += evencount*oddcount
        oddCnt += (n-oddCnt)*oddCnt;
        oddCnt %= MOD;
        return (int)oddCnt;
    }
};