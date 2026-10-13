// Problem: Analyze User Website Visit Pattern
// Difficulty: Medium
// Platform: takeUforward
// Approach: sort and brute-force
// Time: O(n^3)
// Space: O(n)

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // Your Code Goes Here

        vector<tuple<int,string,string>>visits;
        int n = username.size();

        for(int i=0;i<n;i++){
            visits.push_back({timestamp[i],username[i],website[i]});
        }

        sort(visits.begin(),visits.end());

        unordered_map< string,vector<string>>users;


        for(auto& [time,u,web]:visits){
            users[u].push_back(web);
        }

        map<vector<string>,int>freq;

        for(auto& [user,sites] : users){
            int m = sites.size();

            set<vector<string>>patterns;

            for(int i=0;i<m;i++){
                for(int j=i+1;j<m;j++){
                    for(int k=j+1;k<m;k++){
                        patterns.insert({sites[i],sites[j],sites[k]});
                    }
                }
            }

            for(auto& pattern : patterns){
                freq[pattern]++;
            }
        }

        vector<string>ans;
        int maxCount=0;

        for(auto& [pattern,count] : freq){
            if(count > maxCount){
                maxCount = count;
                ans = pattern;
            }
        }
        return ans;

    }
};