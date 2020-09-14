/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Link : https://leetcode.com/problems/balanced-binary-tree/

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
    
    int dfs(TreeNode *node, bool &is_balanced)
    {
        if(node==NULL) return 0;
        
        int p = dfs(node->left,is_balanced);
        int q = dfs(node->right,is_balanced);
        if(abs(p-q)>=2) is_balanced = false;
        return 1+max(p,q);
    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root,ans);
        
        return ans;
    }
};
