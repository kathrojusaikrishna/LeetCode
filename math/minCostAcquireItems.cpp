// Problem: Min cost to acquire required items
// Difficulty: Medium
// Platform: Leetcode
// Approach: simple math
// Time: O(1)
// Space: O(1) 

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans1 = 1LL * cost1 * need1+
                         1LL * cost2 * need2;

        long long common = min(need1,need2);

        long long ans2 = 1LL * costBoth * common +
                         1LL * cost1 * (need1-common) + 
                         1LL * cost2 * (need2-common);
        
        long long ans3 = 1LL * costBoth * max(need1,need2);

        return min({ans1,ans2,ans3});
    }
};