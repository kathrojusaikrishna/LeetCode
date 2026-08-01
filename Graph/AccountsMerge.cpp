// Problem: Accounts Merge
// Difficulty: Medium
//platform: Leetcode
// Approach: Disjoint set union
// Time: O(n*eloge)
// Space: O(n*m)

class Solution {

    unordered_map<string,int>mp;
    unordered_map<string,string>emailToName;

    vector<int>parent,size;
public:

    void makeset(int n){
        parent.resize(n,0);
        size.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(parent[node]==node){
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void solveUnion(int u, int v){

        int pu = find(u);
        int pv = find(v);

        if(pu==pv)return;

        if(size[pu]>size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>>ans;
        int n = accounts.size();

        unordered_map<int,vector<string>>st;
        int index=0;
        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                if(mp.count(accounts[i][j])==0){
                    mp[accounts[i][j]] = index;
                    index++;
                }

                emailToName[accounts[i][j]] = accounts[i][0];
            }
        }

        makeset(index+1);

        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m-1;j++){

                string mail = accounts[i][j];
                string next = accounts[i][j+1];
                solveUnion(mp[mail],mp[next]);
            }
        }

        for(auto& it : mp){

            string email = it.first;
            int id = it.second;

            int root = find(id);

            st[root].push_back(email);

        }

        for(auto& group : st){
            vector<string>account;

            sort(group.second.begin(), group.second.end());

            account.push_back(emailToName[group.second[0]]);

            for(auto& mail : group.second){
                account.push_back(mail);
            }

            ans.push_back(account);
        }

        return ans;
    }
};