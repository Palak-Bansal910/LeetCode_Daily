class Solution {
public:
    bool isHappy(int n) {
        bool Happy = false;
        int sum = 0;
        unordered_set<int> visited;
        do{
            if(visited.count(n)){
                return false;
            }
            visited.insert(n);
            sum = 0;
            while(n > 0){
            int a = n % 10;
            n = n / 10;
            sum = sum + (a*a);
            }
            n = sum;
        }while(sum != 1);
        if(sum == 1){
            Happy = true;
        }
        return Happy;   
    }
};