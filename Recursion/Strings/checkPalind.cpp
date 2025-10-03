//this is the code for checking palindrome
#include<iostream>
using namespace std;

bool checkPalindrome(string a,int i,int j){
    if(i>j){
        return true;
    }

    if(a[i] != a[j]){
        return false;
    }
    else {
        return checkPalindrome(a,i+1,j-1);
    }
}

int main() {

    string name = "detartrated";

    bool isPlaindrome = checkPalindrome(name,0,name.length()-1);
    cout<<endl;

    if(isPlaindrome) {
        cout<<"yes it is a palindrome";
    }
    else {
        cout<<"not its not a palindrome";
    }

    return 0;
}