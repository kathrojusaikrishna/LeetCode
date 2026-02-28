
// Problem: Concatenation of consequitive binary numbers
// Difficulty: Medium
// Approach: Iteration
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    int concatenatedBinary(int n) {
        
        const int MOD = 1e9+7;
        long long result =0;

        for(int i=1;i<=n;i++){

            int bits = log2(i)+1;

            result = ((result << bits)+i)%MOD;
        }

        return result;
    }
};