// Problem: Identical trees
// Difficulty: Easy
//platform: Geeksforgeeks
// Approach: using recursion
// Time: O(n)
// Space: O(1)

class Solution {
  public:
  
    bool solve(Node* r1, Node* r2){
        if(!r1 || !r2)return r1 == r2;
        
        return (r1->data == r2->data) && solve(r1->left,r2->left) &&solve(r1->right,r2->right);
    }
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        
        return solve(r1,r2);
    }
};