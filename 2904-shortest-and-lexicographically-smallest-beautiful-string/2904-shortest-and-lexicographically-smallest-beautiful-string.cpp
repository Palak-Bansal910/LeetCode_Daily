class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(ranges::count(s,'1') < k){
            return "";
        }
        string ans = s;
        int count = 0;
        for(int left = 0, right = 0; right < s.length(); right++){
            count += s[right] -'0';
            while(count > k || s[left] == '0'){
                count -= s[left] - '0';
                left++;
            }
            if(count == k){
                string t = s.substr(left, right - left + 1);
                if(t.length() < ans.length() || t.length() == ans.length() && t < ans){
                    ans = move(t);
                }
            }
        }
        return ans;
    }
};