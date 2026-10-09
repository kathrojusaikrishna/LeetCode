// Problem: Minimum operations to reach n from 0
// Difficulty: Easy
// Platform: Geeksforgeeks
// Approach: greedy
// Time: O(logn)
// Space: O(1) 

class Solution{
  public:
    int minOperation(int n){
        
        int ans=0;
        
        while(n>0){
            if(n%2==0){
                n /=2;
            }
            else{
                n -=1;
            }
            ans++;
        }
        
        return ans;
    }
};