// Problem: Stone removal game
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(1)
// Space: O(1) 

class Solution {
public:
    bool canAliceWin(int n) {
        
        int total=10;
        bool alice=true;

        while(n>=0){
            if(alice){
                if(total > n)return false;
                alice=false;
            }else{
                if(total > n)return true;
                alice=true;
            }
            n-= total;
            total--;
        }

        return alice;
    }
};