// Problem: Integer to english words
// Difficulty: Hard
// Platform: Leetcode
// Approach: computing using map
// Time: O(1)
/

class Solution {
public:

    vector<string>Below20={
        "","One" ,"Two", "Three","Four", "Five" ,"Six","Seven","Eight","Nine","Ten",
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
    };

    vector<string>tens={
        "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
    };

    string helper(int num){

        if(num==0)return "";
        if(num <20){
            return Below20[num]+" ";
        }

        if(num<100){
            return tens[num/10] + " " + helper(num%10); 
        }

        return Below20[num/100] + " Hundred " + helper(num%100);
    }
    string numberToWords(int num) {
        
        string ans="";

        if(num==0)return "Zero";

        vector<pair<int,string>>units={
            {1000000000,"Billion"},
            {1000000,"Million"},
            {1000,"Thousand"},
            {1,""}
        };

        for(auto&[value,name]:units){
            if(num >= value){
                ans += helper(num/value);

                if(name!=""){
                    ans += name + " ";
                }

                num %= value;

            }
        }

        while(!ans.empty() && ans.back()==' ')ans.pop_back();

        return ans;
    }
};