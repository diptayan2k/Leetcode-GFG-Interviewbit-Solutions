// Link : https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int> > ans;
        queue<TreeNode* > q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        int sz = q.size();
        vector<int> level;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            
            if(level.size()==sz)
            {
                ans.push_back(level);
                sz = q.size();
                level.clear();
            }
            
        }
        
        return ans;
        
    }
};
