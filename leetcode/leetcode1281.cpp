// problem to subtract the sum of digits from the product of digits of a number
class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod= 1;
        int add=0;

        while(n!=0){
            int digit = n%10;
            
            prod = prod * digit;
            add = add + digit;
            n=n/10;
        }
        int result = prod-add;

        return result;
        
    }
};