// Given signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go 
// outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
#include<math.h>

class Solution {
public:
    int reverse(int x) {
       
        int ans = 0;
        int INT_MAX = pow(2,31);
        int INT_MIN = pow(2,31) - 1;
        
        while(x!=0) {
            int digit = x%10;

            if((ans>INT_MAX/10) || (ans<INT_MIN/10)) {
                   return 0;
            }

            ans = (ans * 10) + digit;

            x=x/10;

        }

        return ans;
        
    }
};