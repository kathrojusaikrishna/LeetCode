// Problem: Roll the characters of the string
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: freq + suffix + compute
// Time: O(n)
// Space: O(n)

class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n = s.size();
        vector<int>fre(n+2,0);
        
        for(int i=0;i<roll.size();i++){
            fre[roll[i]]++;
        }
        
        for(int i=n;i>=1;i--){
            fre[i] += fre[i+1];
        }
        
        string ans="";
        for(int i=0;i<s.size();i++){
            int curr = s[i]-'a';
            
            curr = (curr + fre[i+1])%26;
            
            ans += (char)('a'+curr);
        }
        return ans;
    }
};
