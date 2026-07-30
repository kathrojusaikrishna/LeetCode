// Problem: Minimum number of pushes to type word - I
// Difficulty: Easy
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minimumPushes(string word) {
        
        int factor=1;
        int ans=0;

        for(int i=1;i<=word.size();i++){
            ans += factor;

            if(i%8==0)factor++;
        }

        return ans;
    }
};