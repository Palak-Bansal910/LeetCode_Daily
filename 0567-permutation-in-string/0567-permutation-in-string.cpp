class Solution {
public:
    bool isAnagram(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int k = s1.size();
        int j = s2.size();
        for(int i = 0; i <= j - k; i++){
            string temp = s2.substr(i,k);
            if(isAnagram(s1,temp)) return true;
        }
        return false;
    }
};