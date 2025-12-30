#include<iostream>
using namespace std;

// isma hum logo ne 
char toLowerCase(char ch){

    if(ch>='a' && ch<='z'){
        return ch;
    }

    else{
        return (ch - 'A' + 'a');
    }
    
}

bool checkPalindrome(char ch[], int n) {
    // iss vala ko ham 2 pointer approach se karenge
    // noon --> ye jaise palindrome ha to isma (first and last same), (2nd last and 2nd first same)
    // while loop lagake hamna check karliya
        int s = 0;
        int e = n-1;

        while(s<=e){
            if(toLowerCase(ch[s]) == toLowerCase(ch[e])){
                s++;
                e--;
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