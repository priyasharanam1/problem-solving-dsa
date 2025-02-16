class Solution {
public:
    vector<int> ans;
    
    bool backtrack(int n, int index, vector<bool>& used) {
        // If all indices are filled, we found a valid sequence
        if (index == ans.size()) return true;

        // If already filled, move to the next index
        if (ans[index] != 0) return backtrack(n, index + 1, used);

        // Try placing the largest available number first
        for (int num = n; num >= 1; --num) {
            if (used[num]) continue; // Skip if number already used

            // Case for '1' (only needs one position)
            if (num == 1) {
                ans[index] = 1;
                used[num] = true;
                if (backtrack(n, index + 1, used)) return true;
                ans[index] = 0;
                used[num] = false;
            } 
            // Case for numbers >= 2 (need two positions)
            else if (index + num < ans.size() && ans[index + num] == 0) {
                ans[index] = ans[index + num] = num;
                used[num] = true;
                if (backtrack(n, index + 1, used)) return true;
                ans[index] = ans[index + num] = 0;
                used[num] = false;
            }
        }

        return false; // No valid sequence found
    }

    vector<int> constructDistancedSequence(int n) {
        ans.resize(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(n, 0, used);
        return ans;
    }
};
