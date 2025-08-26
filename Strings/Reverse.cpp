#include<iostream>
using namespace std;

//in this program we are going to reverse char array

void reverseChar(char a[], int n){
    int start = 0;
    int end = n-1;

    while(start<=end){
        swap(a[start],a[end]);
        start++;
        end--;
    }

}

int lenOfstring(char str[]) {
        int count = 0;
        for(int i=0; str[i]!='\0'; i++){
            count++;
        }

        return count;
}

int main() {
    char str[20];

    cin>>str;
    int len = lenOfstring(str);

    reverseChar(str,len);
    cout<<str;

    return 0;
}