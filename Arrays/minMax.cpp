#include<iostream>
#include<climits>

using namespace std;

int getMin(int arr[], int n) {
    int mini = INT_MAX;

    for(int i=0;i<n;i++) {
        if(arr[i] < mini) {
            mini = arr[i];
        }
    }
    //mini = min(mini,arr[i]) --> same as above if logic

    return mini;
}

int getMax(int arr[], int n) {
    int maxi = INT_MIN;

    for(int i=0;i<n;i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    //maxi = max(maxi,arr[i]) --> same as obove if logic

    return maxi;
}

int main()
{
    int arr[5];

    for(int i=0;i<5;i++) {
        cin>>arr[i];
    }

    cout<<"the max element is"<<getMax(arr,5)<<endl;
    cout<<"Min element is"<<getMin(arr,5);

    return 0;
}