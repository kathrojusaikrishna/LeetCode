// Problem: Lexicographically smallest after removing k
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using stack
// Time: O(n+k)
// Space: O(n)

class Solution {
  public:
  
    bool isPowerofTwo(int n){
        return n>0 && ((n&(n-1))==0);
    }
    string lexicographicallySmallest(string &s, int k) {
        // code here
        string ans;
        
        int n =s.size();
        
        k = isPowerofTwo(n)? k/2 : k*2;
        
        if(k >= n)return "-1";
        
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
        
        return ans;
        
    }
};