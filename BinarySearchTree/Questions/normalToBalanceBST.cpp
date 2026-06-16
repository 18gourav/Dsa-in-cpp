void inorderVector(TreeNode<int>* root,vector<int> &ans){

    //base case

    if(root == NULL){
        return ;
    }

    //left
    inorderVector(root->left,ans);

    //push elem
    ans.push_back(root->data);

    //right
    inorderVector(root->right,ans);

}

TreeNode<int>* inorderToBST(int s,int e,vector<int> ans){

    //base case
    if(s>e){
        return NULL;
    }

    //2nd step->find mid of ans array;
    int mid = s + (e-s)/2;

    //3rd step->make new node of data arr[mid]
    TreeNode<int>* balancedRoot = new TreeNode<int>(ans[mid]);

    //4th step --> now place all elem before mid at left and after mid at right
    balancedRoot -> left = inorderToBST(s,mid-1,ans);
    balancedRoot -> right = inorderToBST(mid+1,e,ans);

    return balancedRoot;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.

    //1st step --> make indorder vector
    vector<int> ans;
    inorderVector(root,ans);

    int n = ans.size();

    return inorderToBST(0,n-1,ans);
}
                        