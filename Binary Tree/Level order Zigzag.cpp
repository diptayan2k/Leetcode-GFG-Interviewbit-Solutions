/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
         vector<vector<int> > ans;
        queue<TreeNode* > q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        int sz = q.size();
        vector<int> level;
        int cnt=0;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            
            if(level.size()==sz)
            {
                if(cnt%2==1) reverse(level.begin(),level.end());
                ans.push_back(level);
                sz = q.size();
                level.clear();
                cnt++;
            }
            
        }
        
        return ans;
        
    }
};
