
//optimal
// Problem: Longest Common prefix
// Difficulty: Medium
// Approach: Hashset
// Time: max (O(n* max(arr1)) , O(m* max(arr2)));
// Space: O(1)


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        int ans=0;
        int n = arr1.size();
        int m = arr2.size();
        unordered_set<string>st;

        for(int i=0;i<n;i++){

            string x = to_string(arr1[i]);
            string prefix="";

            for(auto ch:x){
                prefix +=ch;
                st.insert(prefix);
            }
        }

        for(int i=0;i<m;i++){

            string y = to_string(arr2[i]);
            string prefix="";

            for(auto ch: y){
                prefix +=ch;

                if(st.count(prefix)){
                    ans = max(ans, (int)prefix.size());
                }
            }
        }

        return ans;
    }
};


//bruteforce
// Problem: Longest Common prefix
// Difficulty: Medium
// Approach: Nested for loop
// Time: O(n*m*d) - d is the longest prefix length
// Space: O(1)

class Solution {
public:

    int commonPrefix(int num1, int num2){

        int prefix=0;
        string x = to_string(num1);
        string y = to_string(num2);

        int i=0;
        int j=0;
        while(i<x.size() && j<y.size()){
            if(x[i]==y[j]){
                prefix++;
                i++;
                j++;
            }else{
                break;
            }
        }

        return prefix;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();
        int ans=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int tempPrefix = commonPrefix(arr1[i],arr2[j]);

                ans = max(ans,tempPrefix);
            }
        }

        return ans;
    }
};