// Problem: Digit sum of a string
// Difficulty: Easy
// Platform: Leetcode
// Approach: simple iteration
// Time: O(nlogn)
// Space: O(n) 

class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k){
            int sum=0;
            string temp="";
            for(int i=0;i<s.size();i++){
                sum += s[i]-'0';
                if((i+1)%k==0){
                    temp += to_string(sum);
                    sum=0;
                }
            }

            if(s.size()%k !=0){
                temp += to_string(sum);
            }
            s= temp;
        }

        return s;
    }
};