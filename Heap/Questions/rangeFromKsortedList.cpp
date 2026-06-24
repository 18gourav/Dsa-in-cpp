#include<queue>
#include<limits.h>
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
int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    priority_queue<node*,vector<node*>,compare> minHeap;
    int maxi = INT_MIN;
    int  mini = INT_MAX;

    //step 1: create min heap for every first elem of each lost and compute maxi 
    //and mini
    for(int i=0;i<k; i++){
        int elem = a[i][0];
        mini = min(mini,elem);
        maxi = max(maxi,elem);
        minHeap.push(new node(elem,i,0));
    }

    //STEP2 ->make our range start and end and initialise them as max and mini
    int ansStart = mini;
    int ansEnd = maxi;

    //step3 ->ab isma ham log min heap top mini ma store karate jayenge or range update karta jayenge and fir 
    //pura array traverse krenge or max nikalnege jab tak pura nhi ho jata array 
    while(!minHeap.empty()){

        //extracting mini from minheap top
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        //updating range after calculating mini
        if(maxi - mini < ansEnd-ansStart){
            ansEnd = maxi;
            ansStart = mini;
        }

        //now accesing next elem and update max
        if(temp -> col +1 < n){
            maxi = max(maxi,a[temp->rows][temp->col+1]);
            minHeap.push(new node(a[temp->rows][temp->col+1],temp->rows,temp->col+1));
        }
        else{
            break;
        }
    }

    int ans = ansEnd - ansStart + 1;

    return ans;
}