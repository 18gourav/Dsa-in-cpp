//What is a heap? --> It is a complete binary tree that comes with a heap order property
//A complete binary tree is a special type of binary tree where every level is completely filled,
//except possibly the last level, which must be filled from left to right 
//Heap Order Property -->there are two type of heap --> Min heap and max heap
//Min heap-> in this parent node value will always less than child node
//Max heap -> in this parent node value will always greater than child node

//Now we will implement heap using array

//IMP POINTS
//If we have to find left child of ith node in array -> 2*i
//If we have to find right child of ith node in array -> 2* + 1
//If we have to find parent of ith node in array -> i/2

#include<iostream>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;
    
    heap(){
        arr[0] = -1;
        size = 0;
    }

    //in this we will insert in a max heap
    void insert(int n){
        //step 1-> we will insert that elem in last of arr
        size = size + 1;
        int index = size;
        arr[size] = n;

        //step2 -> now after placing we will check that if it is less than parent elem then insertion is succesfull
        //         if not then we will swap parent and that node elem and keep going to parent node unitl root node/condition applied

        while(index > 1){

            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap( arr[parent] , arr[index] );
                parent = index;
            }
            else{
                return ;
            }

        }
    }
    //TC of insertion -> O(logn)

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }cout<<endl;
    }

    //by default we delete root node(first elem of array) always
    void deleteFromHeap(){
        if(size == 0){
            cout<< "Nothing to delete";
            return ;
        }

        //step 1-> put last node value(last elem in array) in root node(first elem)
        arr[1] = arr[size];

        //step 2 -> delete last node
        size = size -1; 

        //step3 -> now we have to put our root elem in correct place
        //so we keep comapring it to child node until it reach array end/condittion satisfy
        int index = 1;
        while(index <= size){
            int leftChild = 2 * index;
            int rightChild = 2 * index + 1;

            if(leftChild < size &&  arr[index] < arr[leftChild] &&  arr[leftChild]>arr[rightChild]){
                swap(arr[leftChild],arr[index]);
                index = leftChild;
            }
            else if(rightChild < size &&  arr[index] < arr[rightChild] &&  arr[leftChild]<arr[rightChild]){
                swap(arr[rightChild],arr[index]);
                index = rightChild;
            }
            else{
                return ;
            }
        }
    }
    //TC of deletion -> O(logn)         
    
};

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

    return 0;
}