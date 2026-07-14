class Solution {
public:
    int solve(string s, int k, int total_un){
        int i = 0, j = 0;
        int max_len = INT_MIN;
        unordered_map<char,int> state;
        for(char ch = 'a'; ch <= 'z'; ch++){
            state[ch] = 0;
        }
        int un_ch = 0, un_ch_k = 0;
        while(j < s.size()){
            state[s[j]]++;
            if(state[s[j]] == 1) un_ch++;
            if(state[s[j]] == k) un_ch_k++;
            while(un_ch > total_un){
                state[s[i]]--;
                if(state[s[i]] == 0) un_ch--;
                if(state[s[i]] == k -1) un_ch_k--;
                i++;
            }
            if(un_ch == total_un && un_ch == un_ch_k) max_len = max(max_len, j - i +1);
            j++;
        }
        return max_len;
    }
    int longestSubstring(string s, int k) {
        int ans = INT_MIN;
        for(int i = 1; i <=26; i++){
            ans = max(ans,solve(s,k,i));
        }
        return ans == INT_MIN? 0 : ans;
    }
};