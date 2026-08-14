class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int res = 0; 
        for(int i = 0; i < n; i++){
            vector<int> count(26);
            for(int j = i; j < n; j++){
                int idx = s[j] - 'a';
                count[idx]++;
                if(count[idx] > 2) break;
                res = max(res, j-i+1);
            }
        }
        return res;
    }
};