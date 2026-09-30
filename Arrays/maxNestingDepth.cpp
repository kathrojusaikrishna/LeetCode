// Problem: Maximum Nesting Depth of Two Valid Parentheses Strings
// Difficulty: Medium
// Platform: Leetcode
// Approach: finding depth and setting them in two different groups using the depth
// Time: O(n)
// Space: O(1)

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int depth=0;
        for(auto& ch : seq){
            if(ch=='('){
                depth++;
                ans.push_back(depth%2==0);
            }else{
                ans.push_back(depth%2==0);
                depth--;
            }
        }

        return ans;
    }
};