class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;
        while(temp > 0){
            int digit = temp % 10;
            sum += digit;
            product *= digit;
            temp = temp / 10;
        }
        if(n % (sum + product) == 0){
            return true;
        }
        return false;
    }
};