// Problem: remove k digits
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using stack
// Time: O(n+k)
// Space: O(n)

class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        string ans;
        
        for(auto ch : s){
            while(k>0 && !ans.empty() && ans.back() > ch){
                ans.pop_back();
                k--;
            }
            
            ans.push_back(ch);
        }
        
        while(k>0){
            ans.pop_back();
            k--;
        }
        
        int i=0;
        while(i<ans.size() && ans[i]=='0')i++;
        
        ans = ans.substr(i);
        
        
        
        return (ans.empty()) ? "0": ans ;
    }
};