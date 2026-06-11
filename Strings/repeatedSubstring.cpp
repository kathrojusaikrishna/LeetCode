// Problem: Check Repeated Substring with K Replacements
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using map
// Time: O(n)
// Space: O(n)

class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        
        unordered_map<string,int>mp;
        
        int i=0;
        int blocks =0;
        while(i+k<=s.size()){
            mp[s.substr(i,k)]++;
            i+=k;
            blocks++;
        }
        
        int maxFrequency=0;
        
        for(auto& x:mp){
            maxFrequency = max(maxFrequency,x.second);
        }
        
        return blocks-maxFrequency <=1;
        
    }
};