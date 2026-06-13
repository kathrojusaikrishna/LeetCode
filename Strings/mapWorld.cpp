// Problem: Weighted Word Mapping
// Difficulty: Easy
//platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:

    char solve(string &s, vector<int>& weights){
        long long ans=0;

        for(auto& ch : s){
            ans += weights[ch-'a'];
        }

        return 'z' - (ans%26);
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
        string ans="";
        for(auto& s : words){
            ans += solve(s,weights);
        }

        return ans;
    }
};