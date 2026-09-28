// Problem: Maximum Nesting Depth of the Parentheses
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxDepth(string s) {
        
        int depth=0;
        int counter=0;

        for(auto x : s){
            if(x=='('){
                counter++;
                depth = max(depth,counter);

            }
            else if (x==')')counter--;
            else{
                continue;
            }
        }

        return depth;
    }
};