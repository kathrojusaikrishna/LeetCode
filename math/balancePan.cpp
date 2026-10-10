// Problem: Balance Pan
// Difficulty: Easy
// Platform: Geeksforgeeks
// Approach: re-arrange the equation and return based on b%a
// Time: O(logb)
// Space: O(1) 

class Solution {
  public:
    bool balancePan(int a, int b) {
        // code here
        
        while(b>0){
            int rem = b%a;
            
            if(rem==0) b/= a;
            else if(rem==1) b = (b-1)/a;
            else if(rem==a-1) b= (b+1)/a;
            else return false;
        }
        return true;
    }
};