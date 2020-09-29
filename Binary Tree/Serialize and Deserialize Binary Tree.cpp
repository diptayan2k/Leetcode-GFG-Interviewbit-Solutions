/*
Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted 
across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "x,";
        return to_string(root->val)+"," + serialize(root->left)+ serialize(root->right);
    }

    // Decodes your encoded data to tree.
    
    TreeNode* decode(vector<string>& v, int &idx)
    {
        if(idx==v.size()) return NULL;
        if(v[idx]=="x") 
        {
            idx++;
            return NULL;
        }
        
        TreeNode* node = new TreeNode(stoi(v[idx]));
        idx++;
        node->left = decode(v,idx);
        node->right = decode(v,idx);
        
        return node;
    }
    
    TreeNode* deserialize(string data) {
        
        
        vector<string> v;
        string s;
        for(int i = 0; i<data.size();i++)
        {
            if(data[i]==',') 
            {
                v.push_back(s);
                s="";
            }
            else s+=data[i];
        }
    
        int idx = 0;        
        return decode(v,idx);
        
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
