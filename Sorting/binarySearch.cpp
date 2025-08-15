//linear search--> iss algo ma koi problem nahi ha bs agar bohot badi arr de di to matter ho jayega kyuki ye har 
//elem pa jaake search karta ha. Time complexity--> O(N)

//binary search--> iss algo ma ham log mid nikalte ja raha ha or left ya right ma jaan ke liye to agar badi arr
// mili to problem nhi hogi. Time complexity--> O(logN)
#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int s = 0;
    int e = n-1;

     // iss vale formula ma koi problem nahi ha bs agar ham log s and e ki bohot badi value denge or vo int ki 
     //range se bhar nikal gai to matter ho jayega
    // int mid = (s+e)/2;

    // iss ma koi problem nahi ha kyuki e-s se vo badi value cut ho jayegi
    int mid = s + (e-s)/2;

    while(s<=e){
        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
        else if(key < arr[mid]){
            e = mid-1;
        }

        mid = s + (e-s)/2;
    }
    return -1;
}

int main() {

    int odd[5] = {5,9,14,21,30};
    int even[6] = {6,10,15,24,35,49};

    int index = binarySearch(even,6,6);
    cout<<"index of 6 is"<<" "<<index;

    return 0;
}