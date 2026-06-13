//What is Binary Search Tree? --> It is a type of tree in which for every node
//                                Left Node Data should be less than root node data
//                                Right Node Data should be greater than root node data

#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this ->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

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

void insertInBST(node* &root,int d){
    //base case
    if(root==NULL){
        root = new node(d);
        return ;
    }

    if(d > root->data){
        insertInBST(root->right,d);
    }
    if(d < root->data){
        insertInBST(root->left,d);
    }
}
void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertInBST(root,data);
        cin>>data;
    }
}

int main(){
    node* root = NULL;

    //10 8 21 7 27 5 4 3 -1

    cout<<"Take input for bst"<<endl;
    takeInput(root);

    cout<<"Printing the bst"<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal"<<endl;
    inorderTraversal(root);

    cout<< "Pre order Traversal"<<endl;
    preOrderTraversal(root);

    cout<< "Post order traversal"<<endl;
    postOrderTraversal(root);
}