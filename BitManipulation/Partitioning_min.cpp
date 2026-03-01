
// Problem: Partitioning into minimum number of deci-binary numbers
// Difficulty: Medium
// Approach: Iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minPartitions(string n) {
        
        int ans=0;

        for(auto x : n){
            ans = max(ans,x-'0');
            if(ans==9)break;
        }

        return ans;
    }
};