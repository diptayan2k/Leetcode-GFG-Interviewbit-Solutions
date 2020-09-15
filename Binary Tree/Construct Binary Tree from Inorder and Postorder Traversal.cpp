/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
   
Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* build(int &idx, int l, int r, vector<int>& inorder, vector<int>& postorder, map<int,int>& mp)
    {
        if(idx==-1) return NULL;
        if(l>r) return NULL;
        
        TreeNode* node = new TreeNode(postorder[idx]);
        int i = mp[postorder[idx]];
        idx--;
        node->right = build(idx,i+1,r,inorder,postorder,mp);
        node->left = build(idx,l,i-1,inorder,postorder,mp);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int> mp;
        
        for(int i = 0; i<inorder.size(); i++) mp[inorder[i]] = i;
        
        int idx = postorder.size()-1;
        return build(idx,0,inorder.size()-1,inorder,postorder,mp);
   
    }
};
