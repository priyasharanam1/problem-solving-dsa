class Solution {
public:
    string RLE(string s) {
        string ans = "";
        int cnt = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1])
                cnt++;
            else {
                ans += to_string(cnt);
                ans += s[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans += s.back();
        return ans;
    }
    string countAndSay(int n) {
        vector<string> dp(n + 1);
        dp[1] = "1";

        for (int i = 2; i <= n; i++) {
            dp[i] = RLE(dp[i - 1]);
        }

        return dp[n];
    }
};