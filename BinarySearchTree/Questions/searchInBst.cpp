//TC --> O(n)

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    //base case
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    if(x < root->data){
        return searchInBST(root->left,x);
    }
    else{
        return searchInBST(root->right,x);
    }
}
//upper algo uses recursion so it has some space also

//now to do it in o(1) space, we use iterative approach
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int>* temp = root;

    while(temp != NULL){
        if(temp->data == x){
            return true;
        }

        if(x < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }

    return false;
} 