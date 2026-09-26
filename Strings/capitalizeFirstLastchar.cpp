// Problem: Capitalize first and last char of each word
// Difficulty: Medium
// Platform: TakeUforward
// Approach: simple iteration
// Time: O(n)
// Space: O(1)  

class Solution {
public:
    string capitalizeFirstLast(string s) {
        // Your code goes here

        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                s[i-1] = toupper(s[i-1]);
                s[i+1] = toupper(s[i+1]);
            }
        }

        s[0] = toupper(s[0]);
        s[n-1] = toupper(s[n-1]);

        return s;
    }
};
