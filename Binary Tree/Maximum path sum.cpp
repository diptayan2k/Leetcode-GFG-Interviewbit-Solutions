/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6

Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    
    int dfs(TreeNode* node, int& ans)
    {
        
        int p = 0, q = 0;
        if(node->left!=NULL) 
            p = max(p,dfs(node->left,ans));
        if(node->right!=NULL)
            q = max(q,dfs(node->right,ans));
        
        ans = max(ans,p+q+node->val);
        
        return max(p,q)+node->val;
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        
        dfs(root,ans);
        
        return ans;
        
    }
};
