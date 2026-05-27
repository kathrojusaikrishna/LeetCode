// Problem: Wifi range
// Difficulty: Easy
// Approach: iteration
// Time: O(n)
// Space: O(1)

class Solution {
  public:
  
    
    bool wifiRange(string &s, int x) {
        // code here
        
        int n = s.size();
        
        int covered = -1;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='1'){
                
                int start = max(0,i-x);
                int end = min(n-1,i+x);
                
                
                if(start > covered + 1)return false;
                
                
                covered = max(covered,end);
            }
            
        }
        
        return covered==n-1;
    }
};