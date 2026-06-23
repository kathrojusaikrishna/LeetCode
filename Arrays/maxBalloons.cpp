// Problem: Maximum number of balloons 
// Difficulty: Easy
// Platform: Leetcode
// Approach: iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;

        for(auto& ch: text){
            mp[ch]++;
        }
        

        return min({mp['b'],mp['a'],mp['l']/2, mp['o']/2, mp['n']});
    }
};