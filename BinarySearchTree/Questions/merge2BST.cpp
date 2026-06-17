void inorderVector(TreeNode *root1,vector<int> &ans){
    //base case
    if(root1 == NULL){
        return ;
    }

    //left
    inorderVector(root1->left,ans);

    //push value in ans vector
    ans.push_back(root1->data);

    //right
    inorderVector(root1->right,ans);
}
vector<int> merge(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size() + b.size());

    int i=0,j=0;
    int k=0;

    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }

    while(i<a.size()){
        ans[k++] = a[i];
        i++;
    }

    while(j<b.size()){
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

TreeNode* inorderToBST(int s,int e,vector<int> &ans){

    //base case
    if(s>e){
        return NULL;
    }

    //2nd step->find mid of ans array;
    int mid = s + (e-s)/2;

    //3rd step->make new node of data arr[mid]
    TreeNode* balancedRoot = new TreeNode(ans[mid]);

    //4th step --> now place all elem before mid at left and after mid at right
    balancedRoot -> left = inorderToBST(s,mid-1,ans);
    balancedRoot -> right = inorderToBST(mid+1,e,ans);

    return balancedRoot;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    //step 1 --> store inorder of each tree.
    vector<int> inorder1;
    inorderVector(root1,inorder1);

    vector<int> inorder2;
    inorderVector(root2,inorder2);

    //step2 --> now merge these 2 into a new array
    vector<int> ans = merge(inorder1,inorder2);

    //step3 -> now make the bst from this merged inorder
    TreeNode* root = inorderToBST(0,ans.size()-1,ans);

    //step5 now convert this bst to array
    vector<int> finalAns;
    inorderVector(root,finalAns);

    return finalAns;
}