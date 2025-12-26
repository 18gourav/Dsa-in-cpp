#include<iostream>
#include<climits>

using namespace std;

int getMin(int arr[], int n) {
    int min = INT_MAX;

    for(int i=0; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
    
    //mini = min(mini,arr[i]) --> same as above if logic
}

int getMax(int arr[], int n) {

    int max = INT_MIN;

    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
    
    //maxi = max(maxi,arr[i]) --> same as obove if logic
}

int main()
{
    int arr[5];

    for(int i=0;i<5;i++) {
        cin>>arr[i];
    }

    cout<<"Max element is"<<' '<<getMax(arr,5)<<endl;
    cout<<"Min element is"<<' '<<getMin(arr,5);

    return 0;
}