class Solution {
public:
    void dfs(string &tiles, vector<bool> &used, string current, set<string> &st) {
        if (!current.empty()) st.insert(current);

        for (int i = 0; i < tiles.length(); i++) {
            if (used[i]) continue;
            used[i] = true;
            dfs(tiles, used, current + tiles[i], st);
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        set<string> st;
        vector<bool> used(tiles.size(), false);
        dfs(tiles, used, "", st);
        return st.size();
    }
};
