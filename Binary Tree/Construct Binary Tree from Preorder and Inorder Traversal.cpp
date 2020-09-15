/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
 Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    
    TreeNode* build(int &idx, int l, int r, vector<int>& preorder, vector<int>& inorder,map<int,int>& mp)
    {
        if(idx==preorder.size()) return NULL;
        if(l>r) return NULL;
        
        TreeNode* node = new TreeNode(preorder[idx]);
        int i = mp[preorder[idx]];
        idx++;
        node->left = build(idx,l,i-1,preorder,inorder,mp);
        node->right = build(idx,i+1,r,preorder,inorder,mp);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int> mp;
        
        for(int i = 0; i<inorder.size(); i++) mp[inorder[i]] = i;
        int idx = 0;
        return build(idx,0,preorder.size()-1,preorder,inorder,mp);
    }
};
   
