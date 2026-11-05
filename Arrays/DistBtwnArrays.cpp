// Problem: Find the distance between the two arrays
// Difficulty: Easy
// Platform : Leetcode
// Approach: brute force
// Time: O(n*n)
// Space: O(1)

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int ans=0;
        int n =arr1.size();
        int m=arr2.size();
        for(int i=0;i<n;i++){
            bool valid=true;
            for(int j=0;j<m;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    valid=false;
                    break;
                }
            }
            if(valid)ans++;
        }
        return ans;
    }
};