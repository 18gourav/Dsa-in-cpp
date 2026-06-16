void inorderVector(BinaryTreeNode<int>* root,vector<int> &ans){
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
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> ans;
    inorderVector(root,ans);

    int s = 0;
    int e = ans.size()-1;

    while(s<e){
        if(ans[s] + ans[e] == target){
            return true;
        }
        else if(ans[s] + ans[e] < target){
            s++;
        }
        else{
            e--;
        }
    }

    return false;
}