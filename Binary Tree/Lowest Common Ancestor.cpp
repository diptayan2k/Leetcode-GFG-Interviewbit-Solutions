/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4] 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3

Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
 
class Solution {
public:
    
    bool dfs(TreeNode* node, TreeNode* &lca,TreeNode* p,TreeNode* q)
    {
        if(node==NULL) return false;
        
        int current=0,left=0,right = 0;
        if(node==p or node== q) current = 1;
        
        left = dfs(node->left,lca,p,q);
        right = dfs(node->right,lca,p,q);
        
        if(left+right+current ==2) lca = node;
        
        return (left+right+current>0);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* ans;
        dfs(root,ans,p,q);
        
        return ans;
        
    }
};
