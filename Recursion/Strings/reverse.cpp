#include<iostream>
using namespace std;

void reverseStr(char str[],int i, int j){
    if(i>j){
        return ;
    }

    swap(str[i],str[j]);
    i++;
    j--;
    reverseStr(str,i,j);
}

int main() {

   char str[20] = {'f','g','b','a','r'};

   reverseStr(str,0,4);

   for(int i=0;i<5;i++){
    cout<<str[i]<<" ";
   }


    return 0;
}