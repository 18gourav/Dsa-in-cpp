int binarySearch(vector<int> &arr,int s,int e,int key){
    if(s>e){
        return -1;
    }

    int mid = s + (e-s)/2;
    if(arr[mid] == key){
        return mid;
    }

    if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
         return binarySearch(arr,s,mid-1,key);
    }

}
int search(vector<int> &nums, int target) {
    // Write your code here.
     return binarySearch(nums,0,nums.size()-1,target);

}