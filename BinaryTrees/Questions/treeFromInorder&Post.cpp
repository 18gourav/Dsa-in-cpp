class Solution {
  public:
    map<int,int> createmap(map<int,int> &nodeToIndex,vector<int> &inorder){
        for(int i=0;i<inorder.size(); i++){
            nodeToIndex[inorder[i]] = i;
        }
        
        return nodeToIndex;
    }
    Node* solve(vector<int> &inorder, vector<int> &preorder,int &preOrderIndex,map<int,int> &nodeToIndex,int size,int inorderStart,int inorderEnd){
        //base case
        if(preOrderIndex >= size || (inorderStart > inorderEnd)){
            return NULL;
        }
        
        //now take first elem of preorder
        int elem = preorder[preOrderIndex++];
        
        //now this elem is root
        Node* root = new Node(elem);
        
        //now find index of this elem in inorder
        int pos = nodeToIndex[elem];
        
        //now go to left
        root->left = solve(inorder,preorder,preOrderIndex,nodeToIndex,size,inorderStart,pos-1);
        
        //now go to right
        root->right = solve(inorder,preorder,preOrderIndex,nodeToIndex,size,pos+1,inorderEnd);
        
        return root;
        
        
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preOrderIndex = 0;
        int n = inorder.size();
        
        map<int,int> nodeToIndex;
        createmap(nodeToIndex,inorder);
        
        Node* ans = solve(inorder,preorder,preOrderIndex,nodeToIndex,n,0,n-1);
        
        return ans;
    }
};