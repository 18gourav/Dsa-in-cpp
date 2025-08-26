#include<iostream>
using namespace std;
//in strings
// the simple char is defined as: char a = 'a' it stores only one alphabet
// Now a term called character array is here is defined as: char a[20] = {'g','o', '\0'}
// it is displayed as go,after doing cout char array all alphabet before \0 get printed

//in this program we are going to print len of char array

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
    cout<<"length of string is "<<lenOfstring(str);

    return 0;
}