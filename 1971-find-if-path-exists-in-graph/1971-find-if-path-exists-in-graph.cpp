class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination) return true;
        vector<vector<int>>adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    q.push(it);
                    if(it==destination) return true;
                    visited[it]=true;
                }
            }
        }
        return false;
    }
};