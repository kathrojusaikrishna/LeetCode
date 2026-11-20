#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& nums){

    vector<long long>pairs(100001,0);

    for(auto& x : nums){
        pairs[x] +=x;
    }

    long long prev1=0;
    long long prev2=0;

    for(int i=1;i<=100000;i++){
        long long curr = max(prev1,prev2+pairs[i]);

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums[i]=x;
    }

    long long result = solve(nums);

    cout<<result<<'\n';
    return 0;
}