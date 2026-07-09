class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        string sum;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry){
            if(i >= 0){
                carry += a[i--] - '0';
            }
            if(j >= 0){
                carry += b[j--] - '0';
            }
            sum += carry % 2 + '0';
            carry /= 2;    
        }
        reverse(begin(sum), end(sum));
        return sum;
    }
};