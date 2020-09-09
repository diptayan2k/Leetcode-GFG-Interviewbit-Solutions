/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st;
        TreeNode* current = root;
        vector<int> ans;
        
        do
        {
            if(current == NULL and !st.empty())
            {
                current = st.top();
                st.pop();
                current = current->left;
                
            }
            if(current!=NULL)
            {
                ans.push_back(current->val);
                st.push(current);
                current = current->right;
                
            }
        }while(!st.empty());
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};
