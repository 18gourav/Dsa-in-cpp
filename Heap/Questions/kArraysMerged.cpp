#include <bits/stdc++.h> 
class node{
    public:
        int data;
        int rows;
        int col;

    node(int data,int rows,int col){
        this -> data = data;
        this -> rows = rows;
        this -> col = col;
    }
};

class compare{
    public:
        bool operator()(node* a,node* b){
            return  a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>,compare> minHeap;

    // step1-> saare arrays ka 1st elem store karo.
    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    } 

    vector<int> ans;

    //step 2
    while(minHeap.size() > 1){
        node* top = minHeap.top();

        ans.push_back(top->data);
        minHeap.pop();

        //so now we have to insert next elem of top elem in that array
        int i = top-> rows;
        int j = top-> col;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }

    return ans;
}
//TC: O(n*k(logk))
//SC: O(n*k)