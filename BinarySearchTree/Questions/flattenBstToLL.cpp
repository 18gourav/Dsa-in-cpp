void inorderVector(TreeNode<int>* root,vector<TreeNode<int>*> &ans){

    //base case

    if(root == NULL){
        return ;
    }

    //left
    inorderVector(root->left,ans);

    //push elem
    ans.push_back(root);

    //right
    inorderVector(root->right,ans);

}
TreeNode<int>* flatten(TreeNode<int>* root)
{

    //1st step -> make a vector which contain all nodes in inorder
    vector<TreeNode<int>*> ans;

    inorderVector(root,ans);

    int n = ans.size();

    TreeNode<int>* newRoot = ans[0];

    //2nd step --> In this we have to traverse ans array
    //            and make every node left NULL and right to next elem
    for(int i=0; i<n-1; i++){
        //left NULL
       ans[i] -> left = NULL;

        //right to next elem
        ans[i] -> right = ans[i+1];
    }

    //3rd step -> make last elem left and right NULL
    ans[n-1] -> left = NULL;
    ans[n-1] -> right = NULL;

    return newRoot;
}