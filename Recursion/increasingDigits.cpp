// Problem: N-Digit Numbers with Increasing Digits
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: using recursion
// Time: O(C(9,n))
// Space: O(n) -> for ans
class Solution {
  public:
  
    void dfs(int lastDigit, int currentVal, int digitsTaken, vector<int>& ans,int& n){
        if(digitsTaken==n){
            ans.push_back(currentVal);
            return;
        }
        
        for(int i=lastDigit+1;i<=9;i++){
            dfs(i,currentVal*10+i,digitsTaken+1,ans,n);
        }
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int>ans;
        
        if(n>9)return ans;
        int maxf = 9-n+1;
        
        if(n==1){
            for(int i=0;i<=9;i++)ans.push_back(i);
            
            return ans;
        }else{
            for(int firstDigit = 1;firstDigit<=maxf;firstDigit++){
            dfs(firstDigit,firstDigit,1,ans,n);
            }
        }
        
        return ans;
    }
};