// Problem: Minimum absolute difference in BST
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: In-order
// Time: O(n)
// Space: O(1)

class Solution {
public:
    void solve(Node* root, int &prev, int &ans) {

        if (!root)
            return;

        solve(root->left, prev, ans);

        if (prev != -1) {
            ans = min(ans, abs(root->data - prev));
        }

        prev = root->data;

        solve(root->right, prev, ans);
    }

    int absDiff(Node* root) {

        int prev = -1;
        int ans = 1e9;

        solve(root, prev, ans);

        return ans;
    }
};