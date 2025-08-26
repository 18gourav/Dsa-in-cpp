#include<iostream>
using namespace std;

bool checkPalindrome(char ch[], int n) {
          int start = 0;
          int end = n-1;

          while(start<=end){
            if(ch[start] == ch[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
          }
          return true;
}

int lenOfstring(char str[]) {
        int count = 0;
        for(int i=0; str[i]!='\0'; i++){
            count++;
        }

        return count;
}

int main() {

    char a[20];
    cin>>a;
    int len = lenOfstring(a);

    if(checkPalindrome(a,len)) {
        cout<<"Yes this is a palindrome!";
    }
    else{
        cout<<"This is not a palindrome!";

    }


    return 0;
}