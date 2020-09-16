/*
Link : https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor
of a given key. In case, if the either of predecessor or successor is not found print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST.
The last line contains the key.

Output:
Print the predecessor followed by successor for the given key. If the predecessor or successor is not found print -1.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1

*/

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// 1st Approach :
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL) return;
    
    if(root->key==key)
    {
        
        if(root->left!=NULL)
        {
            Node* temp = root->left;
            while(temp->right!=NULL) temp= temp->right;
            pre = temp;
        }
        if(root->right!=NULL)
        {
            Node* temp = root->right;
            while(temp->left!=NULL) temp = temp->left;
            suc = temp;
        }
        
       
    }
    
    else if(key<root->key) 
    {
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
    else if(key>root->key) 
    {
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }

}

// 2nd Approach : 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
	if (root == NULL) return;
	findPreSuc(root->left, pre, suc, key);
	if (root->key < key) pre = root;
	if (root->key > key and suc == NULL) suc = root;
	findPreSuc(root->right, pre, suc, key);



}
