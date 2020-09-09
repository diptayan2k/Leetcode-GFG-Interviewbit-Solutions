/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
  Link : https://leetcode.com/problems/binary-tree-right-side-view/
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
    
    void dfs(TreeNode* node,int level,vector<int>& ans)
    {
        if(node == NULL) return;
        if(ans.size()<=level) ans.push_back(node->val);
        
        dfs(node->right,level+1,ans);
        dfs(node->left,level+1,ans);
        
    }
    vector<int> rightSideView(TreeNode* root) {
    
        vector<int> ans;
        
        dfs(root,0,ans);
        return ans;
    }
};
