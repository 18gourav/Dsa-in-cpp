//The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's 
//in its binary representation.

#include<math.h>

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;

        int ans = 0;
        int i = 0;
        while (n != 0) {
            int bit = n & 1;
            bit = ~bit & 1; // ensure only LSB is taken after ~
            if (bit == 1) {
                ans += pow(2, i);
            }
            n = n >> 1;
            i++;
        }
        return ans;
    }
};
