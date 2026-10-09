#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, string& s, char target){
    int ans=0;
    while(l<r){
        if(s[l]!=s[r]){
            if(s[l]==target ||s[r]==target)ans++;
            else ans+=2;
        }
        l++;
        r--;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        char c;
        string s;

        cin>>n>>c;
        cin>>s;

        cout<<solve(0,n-1,s,c)<<'\n';
    }
}