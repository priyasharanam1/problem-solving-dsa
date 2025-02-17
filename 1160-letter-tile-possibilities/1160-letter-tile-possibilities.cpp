class Solution {
public:
    void dfs(vector<int>& freq, int& count) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            freq[i]--;
            count++;  // Count this new sequence
            dfs(freq, count);
            freq[i]++; // Backtrack
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles) freq[c - 'A']++; // Count character frequencies
        int count = 0;
        dfs(freq, count);
        return count;
    }
};
