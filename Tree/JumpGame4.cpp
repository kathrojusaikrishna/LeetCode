// Problem: Jump Game 4
// Difficulty: Hard
// Approach: Queue, BFS
// Time: O(n)
// Space: O(n) -> for queue

class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        if(n==1) return 0;
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }

        queue<int>q;
        vector<bool>vis(n,false);

        q.push(0);
        vis[0]=true;

        int jumps=0;

        while(!q.empty()){

            int size = q.size();

            while(size--){

                int i = q.front();
                q.pop();


                if(i== n-1)return jumps;

                int forward = i+1;
                int backward = i-1;

                if(forward<n && !vis[forward]){
                    q.push(forward);
                    vis[forward]=true;
                }

                if(backward>=0 && !vis[backward]){
                    q.push(backward);
                    vis[backward]=true;
                }

                for(auto it: mp[arr[i]]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }

                mp[arr[i]].clear();
            }

            jumps++;
        }

        return -1;
    }
};