pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    //find the node
    TreeNode* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp != NULL && temp->data != key){
        if(key < temp->data){
            //if that node is less than key value then it can be our pred
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    if(temp == NULL){
    return {pred, succ};
    }

    //now we find our key in bst

    //now predecessor and successor

    //predecessor --> To find it we have to find max in the target node left subtree
    //Successor -->To find it we have to find min in the target node right subtree

    //pre
    TreeNode* leftSub = temp->left;

    while(leftSub != NULL){
        pred = leftSub->data;
        leftSub = leftSub->right;
    }

    //succ
    TreeNode* rightSub = temp->right;

    while(rightSub != NULL){
        succ = rightSub->data;
        rightSub = rightSub->left;
    }

    pair<int,int> ans = make_pair(pred,succ);

    return ans;
}