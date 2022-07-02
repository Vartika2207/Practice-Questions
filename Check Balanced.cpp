/*
Check Balanced

Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format
The first and only line of output contains true or false.
Constraints
Time Limit: 1 second
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true

*/



/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
/********************/
//time: 0(node*height)=>higher time complexity
int height(BinaryTreeNode<int> *root){
    if(root == nullptr)
        return 0;
    
    if(!root->left && !root->right)
        return 1;
    
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced_(BinaryTreeNode<int> *root) {
	if(root == NULL || (!root->left && !root->right))
        return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh - rh) > 1)
        return false;
    
    return isBalanced_(root->right) && isBalanced_(root->left);
}
/********************/

bool isBalanced(BinaryTreeNode<int> *root) {
    return isBalanced_(root);
}
