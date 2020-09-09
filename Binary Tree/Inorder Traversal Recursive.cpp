/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* node, vector<int>& v)
    {
        if(node->left!=NULL) inorder(node->left,v);
        v.push_back(node->val);
        if(node->right!=NULL) inorder(node->right,v);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root!=NULL)
        inorder(root,ans);
        
        return ans;
        
    }
};
