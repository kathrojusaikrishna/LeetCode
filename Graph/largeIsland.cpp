// Problem: Making a large island
// Difficulty: Hard
//platform: Leetcode
// Approach: connected components using DSU
// Time: O(n*n)
// Space: O(n*n)

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n, 0);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void solveUnion(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;
        DSU A(n * n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {

                    int node = i * n + j;
                    int dr[] = {0, 0, -1, 1};
                    int dc[] = {-1, 1, 0, 0};

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        int adjNode = nr * n + nc;

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                            grid[nr][nc] == 1) {
                            A.solveUnion(node, adjNode);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int node = i * n + j;
                    ans = max(ans, A.size[A.find(node)]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;

                    int node = i * n + j;

                    int dr[] = {0, 0, -1, 1};
                    int dc[] = {-1, 1, 0, 0};

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        int adjNode = nr * n + nc;

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                            grid[nr][nc] == 1) {

                            st.insert(A.find(adjNode));
                        }
                    }

                    int curr = 1;

                    for (auto root : st) {
                        curr += A.size[root];
                    }

                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};