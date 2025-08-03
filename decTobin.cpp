#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int place = 1;

    while(n != 0) {
        int bit = n & 1;
        //humna yaha pe pow(10,i) isliye use nhi kiya kyuki vo double values dedeta ha jisse ans accurate nhi ata
        ans = (bit * place) + ans;
        n = n >> 1;
        place *= 10;
    }

    cout << "the ans is " << ans;

    return 0;
}
