class Solution {
public:
    vector<int> seen;
    vector<int> dist;
    vector<vector<int>> adj;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        seen = *(new vector<int>(n));
        dist = *(new vector<int>(n));
        adj = *(new vector<vector<int>>(n, *(new vector<int>())));
        for (auto e : dislikes) {
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                bool t = dfs(i, 0);
                if (!t) {
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(int start, int count) {
        if (!seen[start]) {
            seen[start]=1;
            dist[start]=count;
            for (auto i : adj[start]) {
                bool t = dfs(i, count+1);
                if (!t) {
                    return false;
                }
            }
            return true;
        } else {
            if ((dist[start]-count)%2==1) {
                return false;
            }
            return true;
        }
    }
};