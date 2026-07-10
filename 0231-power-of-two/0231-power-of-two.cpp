class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*bool isPower = false;
        if(n == 1) return true;
        unsigned int num = n;
        int shift_count = countr_zero(num);
        if(n == pow(2,shift_count)){
            isPower = true;
        }
        return isPower;*/
         if(n <= 0)
        return false;

        int low = 0;
        int high = 30;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int value = 1 << mid;  
            if(value == n)
                return true;
            else if(value < n)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};