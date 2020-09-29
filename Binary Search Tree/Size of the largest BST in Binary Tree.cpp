/*
Link : https://practice.geeksforgeeks.org/problems/largest-bst/1

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
*/

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST

vector<int> findlargestBST(Node* node, int& ans)
{

    if(node->left==NULL and node->right==NULL)
    {
        ans = max(ans,1);
        return {1,node->data,node->data};
    }
    
    vector<int> l,r;
    if(node->left!=NULL) l = findlargestBST(node->left,ans);
    if(node->right!=NULL) r = findlargestBST(node->right,ans);
    
    if(node->left!=NULL and node->right!=NULL)
    {
        if(l[0]>0 and r[0]>0 and node->data>l[2] and node->data<r[1])
        {
            ans = max(ans,1+l[0]+r[0]);
            return {1+l[0]+r[0],l[1],r[2]};
        }
        else return {0,-1,-1};
    }
    else if(node->left!=NULL)
    {
        if(l[0]>0 and node->data>l[2])
        {
            ans = max(ans,1+l[0]);
            return {1+l[0],l[1],node->data};
        }
        else return {0,-1,-1};
        
    }
    else if(node->right!=NULL)
    {
        if(r[0]>0 and node->data<r[1])
        {
            ans = max(ans,1+r[0]);
            return {1+r[0],node->data,r[2]};
        }
        else return {0,-1,-1};
        
    }
    
}

int largestBst(Node *root)
{
    int ans = 0;
    if(root!=NULL)
        findlargestBST(root,ans);
    return ans;
}
