#include<iostream>
using namespace std;

void update(int **p2) {
    // p2 = p2 + 1;
    // kya kuch change hoga isse --> No
    // why? --> jo p2 ha uski alag clone ban chuka ha update ma hi sirf na ki main ma

    // *p2 = *p2 + 1;
    // kya kuch change hoga isse --> Yes

    **p2 = **p2 + 1;
    // kya kuch change hoga isse --> Yes
}

int main() {

    int i = 5;
    int *ptr = &i;
    // this is called double pointer - which means pointing to a pointer
    int **pt = &ptr;

    cout<<"everything is right"<<endl;

    //in all three cout statements the output will be 5
    cout<<i<<endl;
    cout<<*ptr<<endl;
    cout<<**pt<<endl;

    //in all three cout statements the output will be address of i
    cout<<&i<<endl;
    cout<<ptr<<endl;
    cout<<*pt<<endl;

    cout<<"before"<<endl;
    cout<<i<<endl;
    cout<<ptr<<endl;
    cout<<pt<<endl;
    update(pt);
    cout<<i<<endl;
    cout<<ptr<<endl;
    cout<<pt<<endl;

    return 0;
}