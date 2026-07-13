class Solution {
public:
    bool check(string &s, int len) {
        vector<int> cnt(26, 0);
        int n = s.size();

        int i = 0;

        while (i < n) {
            int j = i;

            while (j < n && s[j] == s[i])
                j++;

            int run = j - i;

            if (run >= len)
                cnt[s[i] - 'a'] += run - len + 1;

            if (cnt[s[i] - 'a'] >= 3)
                return true;

            i = j;
        }

        return false;
    }

    int maximumLength(string s) {
        int n = s.size();

        int low = 1, high = n;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(s, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};