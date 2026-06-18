/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};

info solve(TreeNode * root,int &ans){
    //base case
    if(root == NULL){
        //if base case reached we return our ans
        return {INT_MIN,INT_MAX,true,0};
    }

    //now for left
    info left = solve(root->left,ans);

    //now for right
    info right = solve(root->right,ans);

    //now we insert data in our cuur node
    info currNode;

    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);
    currNode.size = left.size + right.size + 1;

    if(left.isBst && right.isBst && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBst = true;
        ans = max(ans, currNode.size);
    }
    else{
        currNode.isBst = false;
    }

    return currNode;
}
int largestBST(TreeNode * root){
    int maxSize = 0;
    info ans = solve(root,maxSize);
    return maxSize;
}