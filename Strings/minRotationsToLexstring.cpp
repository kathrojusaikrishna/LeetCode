// Problem: Lexicographically smallest string with 0 more rotations
// Difficulty: Hard
//platform: Geeksforgeeks
// Approach: Booths algorithm
// Time: O(n)
// Space: O(n)

class Solution {
  public:
    string lexiString(string &s) {
        // code here
        
        string temp = s+s;
        int n =s.size();
        
        int i=0;
        int j=1;
        int k=0;
        
        while(i<n && j<n && k<n){
            
            char a = temp[i+k];
            char b = temp[j+k];
            
            if(a==b){
                k++;
            }else{
                if(a>b){
                    i = i+k+1;
                    if(i<=j){
                        i=j+1;
                    }
                }else{
                    j= j+k+1;
                    if(j<=i){
                        j=i+1;
                    }
                }
                k=0;
            }
        }
        int start = min(i,j);
        
        return temp.substr(start,n);
    }
};