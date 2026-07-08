class Solution {
public:
    bool isAnagram(string &a, string &b) {
        if (a.size() != b.size()) return false;

        vector<int> freq(26, 0);

        for (char c : a) freq[c - 'a']++;
        for (char c : b) freq[c - 'a']--;

        for (int x : freq) {
            if (x != 0) return false;
        }

        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (!isAnagram(ans.back(), words[i])) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};