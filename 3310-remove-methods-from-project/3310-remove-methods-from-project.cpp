class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> dir(n), undir(n);

        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            dir[u].push_back(v);
            undir[u].push_back(v);
            undir[v].push_back(u);
        }

        vector<bool> suspicious(n, false);
        vector<bool> vis(n, false);

        function<void(int)> dfs1 = [&](int u) {
            suspicious[u] = true;
            for (int v : dir[u]) {
                if (!suspicious[v])
                    dfs1(v);
            }
        };

        dfs1(k);

        function<void(int)> dfs2 = [&](int u) {
            vis[u] = true;
            for (int v : undir[u]) {
                if (!vis[v]) {
                    suspicious[v] = false;
                    dfs2(v);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!suspicious[i] && !vis[i])
                dfs2(i);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};