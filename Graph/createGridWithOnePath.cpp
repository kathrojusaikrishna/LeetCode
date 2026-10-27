// Problem: Create a grid with exactly one path
// Difficulty: Easy
//platform: Leetcode
// Approach: simple iteration
// Time: O(n*m)
// Space: O(1)

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string>ans;
        for(int i=0;i<m;i++){
            string val="";
            string hash="";
            for(int j=0;j<n-1;j++){
                val += '.';
                hash += '#';
            }
            if(i==0)ans.push_back(val);
            else ans.push_back(hash);
        }

        for(auto& st : ans){
            st+='.';
        }
        return ans;
    }
};