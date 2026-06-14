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

node* minValue(node* root){
    node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}

node* maxValue(node* root){
    node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}

node* deleteFromBst(node* root,int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            node* temp = maxValue(root->left);
            root->data = temp->data;
            root->right = deleteFromBst(root->right,temp->data);
            return root;
        }
    }
    
    if(val < root->data){
        //left ma jao
        root->left = deleteFromBst(root->left,val);
        return root;
    }

    else{
        //right ma jao
        root->right = deleteFromBst(root->right,val);
        return root;
    }

}

int main(){
    node* root = NULL;

    //50 20 70 10 30 90 110 -1 

    cout<<"Take input for bst"<<endl;
    takeInput(root);

    cout<<"Printing the bst"<<endl;
    levelOrderTraversal(root);

    // cout<<"inorder traversal"<<endl;
    // inorderTraversal(root);

    // cout<< "Pre order Traversal"<<endl;
    // preOrderTraversal(root);

    // cout<< "Post order traversal"<<endl;
    // postOrderTraversal(root);

    cout<<"min val in bst "<<minValue(root)->data<<endl;

    cout<<"min val in bst "<<maxValue(root)->data<<endl;

    root = deleteFromBst(root,50);

    cout<<"Printing the bst"<<endl;
    levelOrderTraversal(root);


}