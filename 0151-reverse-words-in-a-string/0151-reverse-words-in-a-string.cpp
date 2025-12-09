class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";

        // Phase 1: Extract words and push into stack
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            }
        }

        // last word push (if any)
        if (!word.empty()) {
            st.push(word);
        }

        // Phase 2: Pop from stack and build answer
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            ans += " ";
            st.pop();
        }

        // remove last extra space
        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }
};
