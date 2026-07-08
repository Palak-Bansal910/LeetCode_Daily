class Solution {
public:
    bool isPalindrome(int n) {
        int x = n;
        signed long int reverse = 0;
        while(n > 0){
            int a = n % 10;
            n = n / 10;
            reverse = reverse * 10 + a;
        }
        
        return reverse == x;
    }
};