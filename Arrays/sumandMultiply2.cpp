// Problem: Concatinate non-zero digits and multiply by sum II 
// Difficulty: Medium
// Approach: prefixSum and computation
// Time: O(n)
// Space: O(n) 

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const int MOD = 1e9 + 7;
        int m = s.size();

        
        vector<int> prefix(m);
        prefix[0] = s[0] - '0';

        
        vector<int> zeros(m);
        zeros[0] = (s[0] == '0');

        
        string temp = "";
        if (s[0] != '0')
            temp += s[0];

        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1] + (s[i] - '0');

            zeros[i] = zeros[i - 1];
            if (s[i] == '0')
                zeros[i]++;
            else
                temp += s[i];
        }

        int k = temp.size();

        
        vector<long long> prefNum(k + 1, 0);

        for (int i = 0; i < k; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + (temp[i] - '0')) % MOD;
        }

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            
            long long sum =
                prefix[r] - (l == 0 ? 0 : prefix[l - 1]);

            
            int pos = l;
            while (pos <= r && s[pos] == '0')
                pos++;

            if (pos > r) {
                ans.push_back(0);
                continue;
            }

            
            int zeroCnt =
                zeros[r] - (l == 0 ? 0 : zeros[l - 1]);

            int len = (r - l + 1) - zeroCnt;

            
            int start = pos - zeros[pos];

            
            long long x =
                (prefNum[start + len] -
                 prefNum[start] * pow10[len]) % MOD;

            if (x < 0)
                x += MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};