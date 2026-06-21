#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inorderTraversal(BinaryTreeNode* root,vector<int> &ans){
	//base case
	if(root == NULL){
		return ;
	}

	//left
	inorderTraversal(root->left,ans);

	//push root elem val
	ans.push_back(root->data);

	//right
	inorderTraversal(root->right,ans);
}
void fillTreeInPreorder(BinaryTreeNode* root,vector<int> ans,int &index){
	//base case
	if(root == NULL){
		return ;
	}

	if(index >= ans.size()){
		return ;
	}

	//N
	root -> data = ans[index++];

	//L
	fillTreeInPreorder(root->left,ans,index);

	//R
	fillTreeInPreorder(root->right,ans,index);

}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> ans;

	inorderTraversal(root,ans);

	int index = 0;
	fillTreeInPreorder(root,ans,index);

	return root;
}