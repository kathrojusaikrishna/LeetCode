// Problem: Find unique binary string
// Difficulty: Medium
// Approach: generate all binary string and find if its exist 
// Time: O(n * 2^n)
// Space: O(n * 2^n)

class Solution {
public:

    void generate(int i,int n,string curr, vector<string> &ans){

        if(i==n){
            ans.push_back(curr);
            return;
        }

        curr.push_back('0');
        generate(i+1,n,curr,ans);
        curr.pop_back();

        curr.push_back('1');
        generate(i+1,n,curr, ans);
    }
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_set<string>dup(nums.begin(),nums.end());
        vector<string>ans;

        string curr="";

        generate(0,nums.size(),curr,ans);

        for(int i=0;i<ans.size();i++){
            if(dup.count(ans[i])==0)return ans[i];
        }

        return "000";
    }
};