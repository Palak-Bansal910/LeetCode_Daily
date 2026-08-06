class Solution {
public:
    int productOfDigits(int N){
        int product = 1;
        while(N > 0){
            int digit = N % 10;
            product *= digit;
            N = N /10;
        }
        return product;
    }
    int solve(int n, int t, int i){
        if(productOfDigits(i)%t == 0){
            return i;
        }

        return solve(n, t, i+1);
    }
    int smallestNumber(int n, int t) {
        return solve(n,t,n);
    }
};