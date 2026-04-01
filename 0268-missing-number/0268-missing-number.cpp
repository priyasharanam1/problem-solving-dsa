class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        int xor1 = 0;
        for (int i = 0; i < n; i++) {
            xor1 = xor1 ^ a[i] ^ (i+1);
        }
        return xor1;
    }
};