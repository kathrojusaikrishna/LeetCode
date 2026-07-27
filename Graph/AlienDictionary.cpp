// Problem: Alien Dictionary
// Difficulty: Medium
//platform: Geeksforgeeks
// Approach: Topological sort
// Time: O(n*m)
// Space: O(V + E)


class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        
        int n = words.size();
        
        string ans="";
        vector<unordered_set<int>>adj(26);
        vector<bool>preset(26,false);
        queue<int>q;
        
        vector<int>inOrder(26,0);
        
        for(int i=0;i<n-1;i++){
            
            string &a = words[i];
            string &b = words[i+1];
        
            int j=0;
            
            while(j<a.size() && j<b.size() && a[j]==b[j]){
                j++;
            }
            
            if(j == b.size() && a.size() > b.size())return "";
            
            if(j < a.size() && j<b.size()){
                
                int u = a[j]-'a';
                int v = b[j]-'a';
                
                if(adj[u].insert(v).second){
                    inOrder[v]++;
                }
            }
        }
        
        for(auto& word : words){
            for(auto& ch : word){
                preset[ch-'a']=true;
            }
        }
        
        for(int i=0;i<26;i++){
            if(preset[i] && inOrder[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans += (node + 'a');
            
            
            for(auto& v : adj[node]){
                inOrder[v]--;
                
                if(inOrder[v]==0){
                    q.push(v);
                }
            }
        }
        
        int counter=0;
        
        for(auto x : preset){
            if(x)counter++;
        }
        
        if(counter == ans.size())return ans;
        else return "";
    }
};