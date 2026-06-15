void inorderVector(BinaryTreeNode<int>* root,int &ans,int k,int &count){

    //base case
    if(root == NULL || count >= k){
        return ;
    }

    //left
    inorderVector(root->left,ans,k,count);

    count++;
    if(count == k){
        ans = root->data;
        return;
    }

    //right
    inorderVector(root->right,ans,k,count);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.

    int ans = -1; 
    int count = 0;
    inorderVector(root,ans,k,count);

    return ans;
}