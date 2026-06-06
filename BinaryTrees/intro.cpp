//what is a binary tree?
//In this type of tree root has atmost 2 children or we can say a parent have atmost 2 children

//type of traversals
// Inorder traversal -> LNR
// Preorder Traversal -> NLR
// Postorder Traversal -> LRN
//in above statements -> L - Left
//                       R -> Right
//                       N -> print that node

#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node * left;
    node * right;

    node(int data){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

node* buildTree(node* root){
    cout<<"enter the root node value"<<endl;
    int n;
    cin>>n;

    //now build the root node
    root = new node(n);

    if(n == -1){
        return NULL;
    }

    //now we create one left node and recursion will automatically create all left nodes
    cout<<"enter the value for left node "<<n<<endl;
    root->left = buildTree(root->left);

    //now we create one right node and recursion will automatically create all right nodes 
    cout<<"enter the value for right node"<<n<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    //When we need level order traversal(aka BFS) we need a queue also
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        cout<<temp->data<<endl;
        q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
             if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}

void inorderTraversal(node * root){
    //this method follows LNR

    //base case
    if(root == NULL){
        return ;
    }

    //L
    inorderTraversal(root->left);

    //N
    cout<<root->data<<endl;

    //R
    inorderTraversal(root->right);
}

void preOrderTraversal(node * root){
    // this follows NLR

    //base case
    if(root == NULL){
        return ;
    }

    //N
    cout<<root->data<<endl;

    //L
    preOrderTraversal(root->left);

    //R
    preOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    //this follows LRN

    //base case
    if(root == NULL){
        return ;
    }

    //L
    postOrderTraversal(root->left);

    //R
    postOrderTraversal(root->right);

    //N
    cout<<root->data<<endl;
}

int main() {

    node* root = NULL;

    //create tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    // levelOrderTraversal(root);

    //inorder traversal
    postOrderTraversal(root);
    

    return 0; 
}