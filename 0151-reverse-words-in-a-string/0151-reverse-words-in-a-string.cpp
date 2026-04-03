class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        string ans = "", word = "";
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != ' ') {
                word += s[i];
            } else {
                if(!word.empty()) {
                    reverse(word.begin(), word.end());
                    ans += word + " ";
                    word = "";
                }
            }
        }

        // last word
        if(!word.empty()) {
            reverse(word.begin(), word.end());
            ans += word;
        }

        // remove trailing space
        if(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};