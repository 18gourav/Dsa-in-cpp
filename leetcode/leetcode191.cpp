//problem to check no of 1's in binary representation of a number
class Solution {
public:
    int hammingWeight(int n) {

        int count=0;

        while(n!=0){

            if(n&1){
                count = count + 1;
            }
            n=n>>1; //this is called right shift and we can also call it as n/2 and left shift as n*2
        }

        

        return count;
        
    }
};