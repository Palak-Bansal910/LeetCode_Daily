class Solution {
public:
    bool isPrefixAndSuffix(string &a, string &b) {
        int n = a.size();
        int m = b.size();

        if (n > m) return false;

        return b.compare(0, n, a) == 0 &&
               b.compare(m - n, n, a) == 0;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    ans++;
            }
        }

        return ans;
    }
};