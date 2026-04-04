class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, len = 0, maxlen = 0;
        unordered_map<char, int> mpp;
        for (int r = 0; r < n; r++) {
            if (mpp.find(s[r]) == mpp.end()) {
                len = r - l + 1;
                maxlen = max(maxlen, len);
            } else {
                while (mpp.find(s[r]) != mpp.end()) {
                    mpp.erase(s[l]);
                    l++;
                }
            }
            mpp[s[r]]++;
        }
        return maxlen;
    }
};