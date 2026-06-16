BinaryTreeNode<int>* solve(vector<int> &preorder,int max,int &i){
    //base case
    if(i >= preorder.size()){
        return NULL;
    }

    //base case
    if(preorder[i] > max){
        return NULL;
    }

    //now first index of preorder is root
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i++]);

    //now left
    root -> left = solve(preorder,root->data,i);

    //now right
    root -> right = solve(preorder,max,i);

    return root;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    
    int max = INT_MAX;
    int i = 0;

    return solve(preorder,max,i);
}