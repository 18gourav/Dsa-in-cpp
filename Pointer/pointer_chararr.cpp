#include<iostream>
using namespace std;

int main() {

    int arr[5] = {2,3,4};
    char temp[6] = "abcde";

    //in this the address would be printed
    cout<<arr<<endl;

    //in this case entire sting will be printed
    cout<<temp<<endl;
    //from this case we understand -- cout is function diff for char and int arr

    char *c = &temp[0];
    //in this full string will be printed--why?--reason above
    cout<<c<<endl;
    
    char tem = 'g';
    char *b = &tem;
    //output -- gabcde -- why? not z?--because cout will iterate in tem until it found null char
    cout<<b;

    //dont's
    //char *ch = 'abcde'
    
    return 0;
}