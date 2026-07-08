class Solution {
public:
    int reverse(int x) {
        signed long long reverse = 0;
        /*bool flag = false;
        if(x < 0){
            x = abs(x);
            flag = true;
        }*/
        while(x != 0){
            int digit = x % 10;
             x = x /10;
            reverse = reverse * 10 + digit;
        }
        /*if(flag){
            reverse = reverse * -1;
        }*/
        if(reverse > INT_MAX || reverse < INT_MIN){
            return 0;
        }
        
        return reverse;
    }
};