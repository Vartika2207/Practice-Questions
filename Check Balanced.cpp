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
//time: O(n*h)
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

/********************/
//time: O(n), better approach
class pair_BT{
    public:
        int height;
        bool balanced;
};

pair_BT* isBalanced_helper(BinaryTreeNode<int> *root){
    if(root == nullptr){
        pair_BT* new_pair = new pair_BT();
        new_pair->height = 0;
        new_pair->balanced = true;
        return new_pair;
    }
    
    pair_BT* left_ = isBalanced_helper(root->left);
    pair_BT* right_ = isBalanced_helper(root->right);
    
    bool is_balanced;
    if(!left_->balanced || !right_->balanced || abs(left_->height - right_->height) > 1)
        is_balanced = false;
    else
        is_balanced = true;
    
    pair_BT* new_pair = new pair_BT();
    new_pair->height = 1 + max(left_->height, right_->height);
    new_pair->balanced = is_balanced;
    
    return new_pair;
}

bool isBalanced_better(BinaryTreeNode<int> *root) {
    if(root == nullptr)
        return true;
    return isBalanced_helper(root)->balanced;
}
/********************/

bool isBalanced(BinaryTreeNode<int> *root) {
    return isBalanced_better(root);
}
