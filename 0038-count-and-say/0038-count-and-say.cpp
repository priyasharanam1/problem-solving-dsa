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
        if (n == 1)
            return "1";
        return RLE(countAndSay(n - 1));
    }
};