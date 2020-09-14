/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    
    void dfs(TreeNode* node, int height, int &maxheight)
    {
        if(node==NULL) return ;
        
        maxheight = max(maxheight,height);
        dfs(node->left,height+1, maxheight);
        dfs(node->right, height+1, maxheight);
        
        
    }
    int maxDepth(TreeNode* root) {
        
        int ans = 0;
        dfs(root,1,ans);
        
        return ans;
    }
};
