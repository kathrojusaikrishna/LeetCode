// Problem: Total Waviness of Numbers in Range I
// Difficulty: Medium
// Approach: iteration, bruteforce
// Time: O(num2-num1 * max(num2,num1))
// Space: O(1)

class Solution {
public:

    int solve(int num){
        string s = to_string(num);
        int peaks=0;
        int valleys=0;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]> s[i-1] && s[i]>s[i+1])peaks++;

            else if(s[i]<s[i-1] && s[i]<s[i+1])valleys++;
        }

        return peaks+valleys;
    }
    int totalWaviness(int num1, int num2) {
        
        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans += solve(i);
        }
        return ans;
    }
};