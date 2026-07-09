// Problem: Serialize and De-serialize BST
// Difficulty: Medium
//platform: Leetcode
// Approach: level order
// Time: O(n)
// Space: O(n)

#include<bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data="";
        if(!root)return data;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();

            if(temp==nullptr){
                data += "N,";
                continue;
            }
            
            data += to_string(temp->val)+ ",";

            q.push(temp->left);
            q.push(temp->right);
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return nullptr;

        stringstream ss(data);
        string token;

        queue<TreeNode*>q;
        
        getline(ss,token,',');

        TreeNode* root= new TreeNode(stoi(token));

        q.push(root);

        while(!q.empty()){

            TreeNode* parent = q.front();
            q.pop();

            getline(ss,token,',');

            if(token != "N"){
                parent->left = new TreeNode(stoi(token));
                q.push(parent->left);
            }

            getline(ss,token,',');
            if(token != "N"){
                parent->right = new TreeNode(stoi(token));
                q.push(parent->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;