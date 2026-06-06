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
        this->left = NULL;
        this->right = NULL;
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
        q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

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

void buildTreeFromLevelOrder(node* &root){
    cout<<"enter the data for node: "<<endl;
    int data;
    cin>>data;

    root = new node(data);

    queue<node*> Q;
    Q.push(root);

    while(!Q.empty()){
        node* temp = Q.front();
        Q.pop();

        //now left node
        cout<<"Enter the value for left node of: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            Q.push(temp->left);
        }

        //now right node
        cout<<"Enter the value for right node of : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            Q.push(temp->right);
        }
    }
}

int main() {

    node* root = NULL;

    buildTreeFromLevelOrder(root);
    levelOrderTraversal(root);

    // //create tree
    // root = buildTree(root);
    // //1 3 5 7 11 -1 17 -1 -1 -1 -1 -1 -1

    // //level order
    // // levelOrderTraversal(root);

    // //inorder traversal
    // postOrderTraversal(root);
    

    return 0; 
}