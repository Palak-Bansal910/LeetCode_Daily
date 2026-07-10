class Solution {
public:
    int addDigits(int num) {
        if(num < 10){
            cout<< num;
        }
        int sum = 0;
        do{
            sum = 0;
            while(num > 0){
            int a = num % 10;
            num = num / 10;
            sum = sum + a;
            }
            num = sum;
        }while(sum >= 10);
        return sum;
    }
};