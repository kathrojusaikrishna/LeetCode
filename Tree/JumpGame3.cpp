// Problem: Jump Game 3
// Difficulty: Medium
// Approach: Queue, BFS
// Time: O(n)
// Space: O(n) -> for queue

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        queue<int>q;
        int n = arr.size();
        vector<bool>vis(n,false);

        q.push(start);
        vis[start]=true;

        while(!q.empty()){
            int i = q.front();
            q.pop();

            if(arr[i]==0)return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if(forward <n && !vis[forward]){
                q.push(forward);
                vis[forward]=true;
            }

            if(backward>=0 && !vis[backward]){
                q.push(backward);
                vis[backward]=true;
            }
        }

        return false;
    }
};