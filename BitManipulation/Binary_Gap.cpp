// Problem: Binary Gap
// Difficulty: Easy
// Approach: Iteration
// Time: O(log n )
// Space: O(log n)

class Solution {
public:
    int binaryGap(int n) {

        vector<int>binary(32);
        int t=0;

        for(int i=0;i<32;i++){
            if((n>>i)&1)binary[t++]=i;
        }

        int ans=0;
        for(int i=0;i<t-1;i++){
            ans = max(ans,binary[i+1]-binary[i]);
        }

        return ans;
    }
};