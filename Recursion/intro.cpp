#include<iostream>
using namespace std;

//Recursion --> it is method in which function call itself
//it has 2 mandate things --> 
                              // "base case"--> if its not given then program will stack overflow(int this code base case is 0)
                              // "recursive function"--> in a smaller way we "big problem = smthg * small problem"
                              //for eg in this case badi problem --> fact(n), choti-->fac(n-1)--> recursive func: f(n) = n*f(n-1)
int factorial(int n){
    if(n == 0){
        return 1;
    }

    int smallProb = factorial(n-1);
    int bigProb = n * smallProb;

    return bigProb;
}

int power(int n){
    if(n == 0){
        return 1;
    }

    int smallprob = power(n-1);
    int bigprob = 2 * smallprob;

    return bigprob;
}

int main() {

    int n;
    cin>>n;

    int ans = power(n);
    cout<<ans<<endl;

    return 0;
}